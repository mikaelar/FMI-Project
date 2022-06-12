#include "NO.h"
#include <iostream>
#pragma warning (disable : 4996)

NO::NO() :Reservation()
{
	paidBar = false;
	paidRestaurant = false;
}

NO::NO(const String& type, int days, int roomNumber, int bedNumber)
	:Reservation(type, days, roomNumber, bedNumber) {}

void NO::display() const
{
	std::cout << "Ultra all inclusive reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << price << "$." << std::endl;
}

bool NO::goToRestaurant() const
{
	return paidRestaurant;
}

bool NO::goToBar() const
{
	return paidBar;
}

Reservation* NO::clone() const
{
	return new NO(*this);
}