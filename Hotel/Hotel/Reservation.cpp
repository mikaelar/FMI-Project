#include "Reservation.h"
#pragma warning(disable:4996)

Reservation::Reservation()
{
	days = 0;
	roomNumber = 0;
	bedNumber = 0;
	price = 0;
}

Reservation::Reservation(const String& type, int days, int roomNumber, int bedNumber)
{
	this->type = type;
	this->days = days;
	this->roomNumber = roomNumber;
	this->bedNumber = bedNumber;
}

void Reservation::setType(const String& type)
{
	this->type = type;
}

void Reservation::setID(const String& id)
{
	this->visitor.setID(id);
}

void Reservation::setName(const String& name)
{
	this->visitor.setName(name);
}

void Reservation::setDays(int days)
{
	this->days = days;
}

void Reservation::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}

void Reservation::setBedNumber(int bedNumber)
{
	this->bedNumber = bedNumber;
}

void Reservation::setPrice(double price)
{
	this->price = price;
}

const String& Reservation::getType() const
{
	return type;
}

const String& Reservation::getID() const
{
	return visitor.getID();
}

const String& Reservation::getName() const
{
	return visitor.getName();
}

int Reservation::getDays() const
{
	return days;
}

int Reservation::getRoomNumber() const
{
	return roomNumber;
}

int Reservation::getBedNumber() const
{
	return bedNumber;
}

double Reservation::getPrice() const
{
	return price;
}