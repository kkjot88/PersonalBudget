#include <iostream>

#include "PersonalBudget.h"
#include "Date.h"
#include "Income.h"
#include "IncomeManager.h"

using namespace std;

#define c cout <<
#define e << endl

int main()
{
	Income i1;
	i1.setId(1);
	i1.setUserId(1);
	i1.setDate("2021-06-15");
	i1.setDescription("wplata 1");
	i1.setAmount(300);
	Income i2;
	i2.setId(2);
	i2.setUserId(1);
	i2.setDate("2021-06-01");
	i2.setDescription("wplata 2");
	i2.setAmount(300);
	Income i3;
	i3.setId(3);
	i3.setUserId(1);
	i3.setDate("2021-06-02");
	i3.setDescription("wplata 3");
	i3.setAmount(300);
	Income i4;
	i4.setId(4);
	i4.setUserId(1);
	i4.setDate("2021-06-02");
	i4.setDescription("wplata 4");
	i4.setAmount(300);

	Income i5;
	i5.setId(5);
	i5.setUserId(1);
	i5.setDate("2021-05-21");
	i5.setDescription("wplata 5");
	i5.setAmount(300);
	Income i6;
	i6.setId(6);
	i6.setUserId(1);
	i6.setDate("2021-05-05");
	i6.setDescription("wplata 6");
	i6.setAmount(300);

	Income i7;
	i7.setId(7);
	i7.setUserId(1);
	i7.setDate("2021-08-21");
	i7.setDescription("wplata 7");
	i7.setAmount(300);
	Income i8;
	i8.setId(8);
	i8.setUserId(1);
	i8.setDate("2021-07-05");
	i8.setDescription("wplata 8");
	i8.setAmount(300);

	IncomeManager incomeManager("x",1);

	incomeManager.income.push_back(i1);
	incomeManager.income.push_back(i2);
	incomeManager.income.push_back(i3);
	incomeManager.income.push_back(i4);
	incomeManager.income.push_back(i5);
	incomeManager.income.push_back(i6);
	incomeManager.income.push_back(i7);
	incomeManager.income.push_back(i8);

	incomeManager.showCurrentMonthIncomeAndGetTotal();

	//incomeManager.showPreviousMonthIncomeAndGetTotal();

	Date b1("2001-01-01");
	Date b2("2040-01-01");

	//incomeManager.showGivenPeriodIncomeAndGetTotal();

	//incomeManager.showIncomeForGivenPeriod(b1,b2);

	/*
	IncomeManager incomeManager("x",3);

	incomeManager.addIncome();	
	incomeManager.addIncome();	*/
	
	/*Date newDate1;

	Date nDate1("2021-06-09");
	Date nDate2("2021-06-09");

	c (newDate1 >= nDate1) e;
	c (newDate1 <= nDate1) e;
	c "-" e;
	c (newDate1 >= nDate2) e;
	c (newDate1 <= nDate2) e;
	c "-" e;*/

	/* newDate.getDate() e;

	newDate.setDate();

	c newDate.getYear() e;
	c newDate.getMonth() e;
	c newDate.getNumberOfDaysInCurrentMonth() e;
	c newDate.getDay() e;
	c newDate.getDate() e;
	c newDate.check() e; */
	
	/*
	string date = "2021-06-08";

	int year = stoi(date.substr(0, 4));

	int month = stoi(date.substr(5, 2));

	int day = stoi(date.substr(8, 2));

	c year e;
	c month e;
	c day e;*/
}
	
	
