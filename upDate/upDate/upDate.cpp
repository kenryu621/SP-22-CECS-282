#include "upDate.h"

int upDate::count;

int Greg_to_Jul(int yr, int mh, int dy)
{
	return dy - 32075 + 1461 * (yr + 4800 + (mh - 14) / 12) / 4 +
		367 * (mh - 2 - (mh - 14) / 12 * 12) / 12 -
		3 * ((yr + 4900 + (mh - 14) / 12) / 100) / 4;
}

void Jul_to_Greg(int julian_date, int& yr, int& mh, int& dy)
{
	julian_date += 68569;
	int temp = 4 * julian_date / 146097;
	julian_date = julian_date - (146097 * temp + 3) / 4;
	yr = 4000 * (julian_date + 1) / 1461001;
	julian_date = julian_date - 1461 * yr / 4 + 31;
	mh = 80 * julian_date / 2447;
	dy = julian_date - 2447 * mh / 80;
	julian_date = mh / 11;
	mh = mh + 2 - 12 * julian_date;
	yr = 100 * (temp - 49) + yr + julian_date;
}

upDate::upDate() {
	this->ptr[0] = 5;
	this->ptr[1] = 11;
	this->ptr[2] = 1959;
	this->count++;
}

upDate::upDate(int m, int d, int y)
{
	int temp_year, temp_month, temp_day;
	Jul_to_Greg(Greg_to_Jul(y, m, d), temp_year, temp_month, temp_day);
	if (temp_year != y || temp_month != m || temp_day != d)
		this->upDate::upDate();
	else
	{
		this->ptr[0] = m;
		this->ptr[1] = d;
		this->ptr[2] = y;
		this->count++;
	}
}

upDate::upDate(int jd)
{
	Jul_to_Greg(jd, this->ptr[2], this->ptr[0], this->ptr[1]);
	this->count++;
}

upDate::upDate(const upDate& right)
{
	this->ptr[0] = right.ptr[0];
	this->ptr[1] = right.ptr[1];
	this->ptr[2] = right.ptr[2];
	this->count++;
}

upDate::~upDate()
{
	this->count--;
	delete[] this->ptr;
}

void upDate::setDate(int m, int d, int y)
{
	this->upDate::upDate(m, d, y);
	this->count--;
}

int upDate::getYear() { return this->ptr[2]; }

int upDate::getMonth() { return this->ptr[0]; }

int upDate::getDay() { return this->ptr[1]; }

std::string upDate::getMonthName()
{
	switch (this->ptr[0])
	{
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:
		return "N/A";
	}
}

int upDate::GetDateCount()
{
	return count;
}

upDate& upDate::operator=(upDate right)
{
	this->ptr[0] = right.ptr[0];
	this->ptr[1] = right.ptr[1];
	this->ptr[2] = right.ptr[2];
	return *this;
}

upDate& upDate::operator+=(int num) {
	Jul_to_Greg(this->upDate::julian() + num, this->ptr[2], this->ptr[0], this->ptr[1]);
	return *this;
}

upDate& upDate::operator-=(int num) {
	Jul_to_Greg(this->upDate::julian() - num, this->ptr[2], this->ptr[0], this->ptr[1]);
	return *this;
}

upDate operator+(upDate left, int num)
{
	return upDate(left.julian() + num);
}

upDate operator-(upDate left, int num)
{
	return upDate(left.julian() - num);
}

upDate operator+(int num, upDate right)
{
	return upDate(right.julian() + num);
}

int operator-(upDate left, upDate right)
{
	return left.julian() - right.julian();
}

std::ostream& operator<<(std::ostream& output, upDate right)
{
	output << right.ptr[0] << "/" << right.ptr[1] << "/" << right.ptr[2];
	return output;
}

upDate operator++(upDate& right) {
	right += 1;
	return right;
}

upDate operator++(upDate& left, int) {
	upDate temp(left);
	left += 1;
	return temp;
}

upDate operator--(upDate& right) {
	right -= 1;
	return right;
}

upDate operator--(upDate& left, int) {
	upDate temp(left);
	left -= 1;
	return temp;
}

int upDate::julian() {
	return Greg_to_Jul(this->ptr[2], this->ptr[0], this->ptr[1]);
}

bool operator==(upDate left, upDate right) {
	return left.julian() == right.julian();
}

bool operator>(upDate left, upDate right) {
	return left.julian() > right.julian();
}

bool operator<(upDate left, upDate right) {
	return left.julian() < right.julian();
}