//============================================================================
// Name        : Assignment2Part3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :  Write a function that converts US time with hours, minutes, seconds,
// am/pm to "decimal time". In decimal time, the day has ten "hours",
// of 100 "minutes" each, and each "minute" has 100 "seconds". Return
// a floating-point number whose integral part is the decimal hours
//and whose fractional part are 0.01 * decimal minutes + 0.0001 *
//decimal seconds. Round to the nearest decimal second. If the inputs
//are invalid, return -1.
//============================================================================

#include <iostream>
#include<math.h>
using namespace std;

bool validate(int hours, int minutes, int seconds, bool pm){

	bool error = false;

	if((hours>=24||hours<0)||(minutes>59||minutes<0)||(seconds>59||seconds<0)||(hours+minutes+seconds==0))
		error = true;

	return error;
}

double covertTimetoSec(int hours,int minutes, int seconds, bool pm){
	double totalSeconds = 0;


	if(pm && hours!=12){
		hours = hours+12;
	}else if(!pm && hours == 12)
	{
		hours = hours - 12;
	}

	totalSeconds = (hours*3600)+(minutes*60)+seconds;

	return totalSeconds;
}

double decimal_time(int hours, int minutes, int seconds, bool pm)
{
	double result;
	bool error;
	error = validate(hours,minutes,seconds,pm);
	if(!error){
		int day1 = 24*3600;
		double dayDecimal = 10*100*100;//10^5 seconds in a day
		double sec24 = covertTimetoSec(hours,minutes,seconds,pm);
		double sec1insec24 = dayDecimal/(24*3600);
		double convertTime1 = sec1insec24 * sec24;
		int convertTime = round(convertTime1);
		int newHour = convertTime*1.0/10000;
		convertTime = convertTime%10000;
		int newMin = convertTime*1.0/100;
		convertTime = convertTime%100;

		result = newHour+(0.01*newMin)+(0.0001*convertTime);
	}else
		result = -1;
	return result;
}

int main() {
	int hr,min,sec;
	bool pm=false;
	cout<<"enter the time in Hrs Mins Secs true if PM";
	cin>>hr>>min>>sec>>pm;
	/*hr=59;
	min=59;
	sec=59;*/
	pm=true;
	double decTime = decimal_time(hr,min,sec,pm);
	if(decTime>=0)
	cout<<"the decimal time of "<<hr<<":"<<min<<":"<<sec<<" is"<<decTime<<endl;
	else
		cout<<"invalid time"<<endl;

	return 0;
}
