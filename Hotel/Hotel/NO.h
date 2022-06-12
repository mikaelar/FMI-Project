#pragma once
#include "Reservation.h"

class NO : public Reservation
{
private:
	bool paidBar;
	bool paidRestaurant;

public:
	NO();
	NO(const String& type, int days, int roomNumber, int bedNumber);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;

	Reservation* clone() const override;
};