#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double f1(double x){
	return (cos(x)+exp(x-3));
}

double f2(double x){
	return log(x+1);
}

double f3(double x){
	return tan(x/8)*x +1.0/3;
}

double minFunc(double x){
	return min(min(f1(x), f2(x)), f3(x));
}

double maxFunc(double x){
	return max(max(f1(x), f2(x)), f3(x));
}

void makeTable(double (*func)(double), double step){
	printf("\n");
	printf("%s \n", " x        f(x)");
	printf("%s \n", "_____________________");
	for (double x=0; x<=2*3.1415; x+=step) {
		printf("%5.3f", x); 
		printf("%s", "     ");
		printf("%5.3f \n", func(x)); 
	}
}

int main(){
	cout << "Welcome, sir! To build a table of fucntion values on [0; 2pi] enter the step" << endl;
	double step;
	cin >> step;
	cout << "And press..." << endl;
	cout << " - 1 to f1(x)=cos(x) + exp(x-3);" << endl;
	cout << " - 2 to f2(x)=log(x+1);" << endl;
	cout << " - 3 to f3(x)=tan(x/8)*x + 1/3;" << endl;
	cout << " - Upwards Arrow to max{f1, f2, f3};" << endl;
	cout << " - Downwards Arrow to min{f1, f2, f3}." << endl;
	int key = getch();
	if (key == 224) {
		key = getch();
	}
	cout << endl;
	double (*func)(double);
	switch (key) {
		case 49: func = f1; break;
		case 50: func = f2; break;
		case 51: func = f3; break;
		case 72: func = maxFunc; break;
		case 80: func = minFunc; break;
		default: 
			func = NULL;
			cout << endl << "________________________" << endl << "Error: unexpected button" << endl;
		break;
	}
	if (func!=NULL) {
		makeTable(func, step);
	}
}

