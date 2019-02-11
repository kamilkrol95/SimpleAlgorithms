clear all;
x = 0:1000;
k = 5000;
y1 = x+k;
y2 = x.*log2(x);

% plot(x,y1);
% hold on;
% plot(x,y2);
% grid on;
a = importdata('C:\Users\Kamil\Documents\AGH IEiT\ASD\Programy\Test szybkosci\dane.txt');
plot(a);
grid on;