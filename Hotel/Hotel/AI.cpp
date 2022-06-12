#include "AI.h"
#include <iostream>
#pragma warning (disable : 4996)

AI::AI() :Reservation()
{
	paidBar = false;
}

AI::AI(const String& type, int days, int roomNumber, int bedNumber)
	: Reservation(type, days, roomNumber, bedNumber) {}

void AI::display() const
{
	std::cout << "All inclusive reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << price << "$." << std::endl;
}

bool AI::goToRestaurant() const
{
	return true;
}

bool AI::goToBar() const
{
	return paidBar;
}

void AI::payToBar() const
{
	//bool a = true;
	//setPaidBar(a);
}

Reservation* AI::clone() const
{
	return new AI(*this);
}