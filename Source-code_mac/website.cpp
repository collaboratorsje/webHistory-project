
#include "website.h"

Website::Website() {
    year = 0;
    month = 0;
    day = 0;
    minute = 0;
    second = 0;
}
// constructor
Website::Website(const std::string &websiteName, int year, int month, int day,
                 int minute, int second) {
    this->name = websiteName;
    this->year = year;
    this->month = month;
    this->day = day;
    this->minute = minute;
    this->second = second;
}
// setters and getters
std::string Website::getName() const { return name; }

void Website::setName(const std::string &websiteName) {
    this->name = websiteName;
}

int Website::getYear() const { return year; }

void Website::setYear(int year) { this->year = year; }

int Website::getMonth() const { return month; }

void Website::setMonth(int month) { this->month = month; }

int Website::getDay() const { return day; }

void Website::setDay(int day) { this->day = day; }

int Website::getMinute() const { return minute; }

void Website::setMinute(int minute) { this->minute = minute; }

int Website::getSecond() const { return second; }

void Website::setSecond(int second) { this->second = second; }
// print function
void Website::print() const {
    std::cout << "Website: " << name << std::endl;
    std::cout << "Date Visited: " << year << "-" << month << "-" << day
              << std::endl;
}
// sort function by date compares the website objects to eachother and returns a bool after using a cascading approach of comparing years, months, etc.
bool Website::sortByDate(const Website &w1, const Website &w2) {
    if (w1.getYear() != w2.getYear())
        return w1.getYear() < w2.getYear();
    if (w1.getMonth() != w2.getMonth())
        return w1.getMonth() < w2.getMonth();
    if (w1.getDay() != w2.getDay())
        return w1.getDay() < w2.getDay();
    if (w1.getMinute() != w2.getMinute())
        return w1.getMinute() < w2.getMinute();
    return w1.getSecond() < w2.getSecond();
}
// sort function by name compares alphabetically the two website objects names and returns a bool if the first's name is < the second's name
bool Website::sortByName(const Website& w1, const Website& w2) {
    return w1.getName() < w2.getName();
}
// This function is made so I could convert a Qstring object from the Qlistwidget on QT into a string so I could compare it to other website objects in the list
bool Website::compareData(const QString& otherData) const {
    // Assuming "name" is the relevant data to compare with the QString
    return QString::fromStdString(name).compare(otherData, Qt::CaseInsensitive) == 0;
}
