#include <iostream>
#include <string>

using namespace std;


int main(){
	long startHour, endHour, startMin, endMin, startSec, endSec;
	cout << "Please enter the start time of the experiment (hour min sec):" << endl;
	cin >> startHour >> startMin >> startSec;
	cout << endl << "Please enter the end time of the experiment (hour min sec):" << endl;
	cin >> endHour >> endMin >> endSec;


// защита от дурака
	if ( (endHour>24)||(endHour<0) || (startHour>24)||(startHour<0) || 
		 (endMin>60)||(endMin<0) || (startMin>60)|| (startMin<0) ||
		 (endSec>60)||(endSec<0) || (startSec>60)||(startSec<0) ) {
			 cout << endl << "Error entering data: wrong format" << endl;
			 exit (EXIT_FAILURE);
	}


// учёт того, что эксперемент закончился на следующий день
	if (startHour > endHour) {
		endHour += 24;
	}
	else {
		if (startHour == endHour) {
			if (startMin > endMin) {
				endHour += 24;
			}
			else {
				if (startMin == endMin) {
					if (startSec > endSec) {
						endHour += 24;
					}
				}
			}
		}
	}


// подсчёт длительности
	startSec = startSec + 60*startMin + 3600*startHour;
	endSec = endSec + 60*endMin + 3600*endHour - startSec;
	endHour = endSec / 3600;
	endSec %= 3600;
	endMin = endSec / 60;
	endSec %= 60;
	
// человеческий вывод
	cout << endl << "the experiment has lasted for ";
	if (endHour != 1) {
		cout << endHour << " hours ";
	}
	else {
		cout << endHour << " hour ";
	}
	
	if (endMin != 1) {
		cout << endMin << " minutes and ";
	}
	else {
		cout << endMin << " minute and ";
	}
	
	if (endSec != 1) {
		cout << endSec << " seconds" << endl;
	}
	else {
		cout << endSec << " second" << endl;
	}

}