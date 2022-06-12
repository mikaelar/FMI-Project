#include "UAI.h"
#include <iostream>
#pragma warning (disable : 4996)

UAI::UAI() :Reservation() {}

UAI::UAI(const String& type, int days, int roomNumber, int bedNumber, double price)
	: Reservation(type, days, roomNumber, bedNumber) {}

void UAI::display() const
{
	std::cout << "Ultra all inclusive reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << price << "$." << std::endl;
}

bool UAI::goToRestaurant() const
{
	return true;
}

bool UAI::goToBar() const
{
	return true;
}

Reservation* UAI::clone() const
{
	return new UAI(*this);
}