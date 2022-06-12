#pragma once
#include "String.h"
#include "Visitor.h"

class Reservation
{
protected:
	String type;
	Visitor visitor;
	int days;
	int roomNumber;
	int bedNumber;
	double price;

public:
	Reservation();
	Reservation(const String& type, int days, int roomNumber, int bedNumber);

	void setType(const String& type);
	void setID(const String& id);
	void setName(const String& name);
	void setDays(int days);
	void setRoomNumber(int roomNumber);
	void setBedNumber(int bedNumber);
	void setPrice(double price);

	const String& getType() const;
	const String& getID() const;
	const String& getName() const;
	int getDays() const;
	int getRoomNumber() const;
	int getBedNumber() const;
	double getPrice() const;

	virtual void display() const = 0;
	virtual bool goToRestaurant() const = 0;
	virtual bool goToBar() const = 0;

	virtual Reservation* clone() const = 0;
};
