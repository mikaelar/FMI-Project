#pragma once
#include "Reservation.h"

class AI:public Reservation
{
private:
	bool paidBar;

public:
	AI();
	AI(const String& type, int days, int roomNumber, int bedNumber);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;
	void payToBar() const;

	Reservation* clone() const override;
};