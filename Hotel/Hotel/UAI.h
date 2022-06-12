#pragma once
#include "Reservation.h"

class UAI :public Reservation
{
public:
	UAI();
	UAI(const String& type, int days, int roomNumber, int bedNumber, double price);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;

	Reservation* clone() const override;
};