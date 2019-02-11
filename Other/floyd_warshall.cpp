#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
    int town, travel_time;
} Segment;

typedef struct Line {
    Segment* segments;
    int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
    Line* l = new Line;
    l->number = number;
    l->length = length;
    l->start_town = start_town;
    l->segments = new Segment[length];
    return l;
}

typedef struct Node {
    int town;
    vector< pair<Node*, int> > neighbours;
} Node;

void dump(int** d, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}

}

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
    // put your code here
	int** d = new int*[towns];
	
	for (int i = 0; i < towns; i++)
	{
		d[i] = new int[towns];
		for (int j = 0; j < towns; j++)
		{
			if (i==j)
			{
				d[i][j] = 0;
			}
			else
			{
				d[i][j] = INF;
			}
		}
	}
	
	//dump(d, towns, towns);
	
	// vector<vector<pair<int, int>>> town_nodes(towns);
	// for (int i = 0; i < lines_no; i++)
	// {
		// int cur_town = lines[i]->start_town;
		// for (int j = 0; j < lines[i]->length - 1; j++)
		// {
			// town_nodes[cur_town].push_back({lines[i]->segments[j].town, lines[i]->segments[j].travel_time});
			// d[cur_town][lines[i]->segments[j].town] = lines[i]->segments[j].travel_time;
			// cur_town = lines[i]->segments[j].town;
		// }
	// }
	
	for (int i = 0 ; i < lines_no; i++)
	{
		int cur_town = lines[i]->start_town;
		for (int j = 0; j < lines[i]->length; j++)
		{
			d[cur_town][lines[i]->segments[j].town] = lines[i]->segments[j].travel_time;
			d[lines[i]->segments[j].town][cur_town] = lines[i]->segments[j].travel_time;
			cur_town = lines[i]->segments[j].town;
		}
	}
		
	for (int k = 0; k < towns; k++)
	{
		for (int i = 0 ; i < towns; i++)
		{
			for (int j = 0; j < towns; j++)
			{
				d[i][j] = std::min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	
	//dump(d, towns, towns);
	
	return d;
}

int main() {
    int towns, lines_no, queries;
    cin >> towns >> lines_no >> queries;
    Line** lines = new Line*[lines_no];
    for (int i=0; i<lines_no; i++) {
        int len, start;
        cin >> len >> start;
        lines[i] = newLine(i, len-1, start);
        for (int j=0; j<len-1; j++) {
            int next, time;
            cin >> time >> next;
            lines[i]->segments[j].town = next;
            lines[i]->segments[j].travel_time = time;
        }
    }

    int** times = calculateTimesMatrix(lines, lines_no, towns);

    for (int i=0; i<queries; i++) {
        int u, v;
        cin >> u >> v;
        cout << times[u][v] << endl;
    }

    for (int i=0; i<towns; i++) delete[] times[i];
    delete[] times;
    for (int i=0; i<lines_no; i++) {
        delete[] lines[i]->segments;
        delete lines[i];
    }
    delete[] lines;
}