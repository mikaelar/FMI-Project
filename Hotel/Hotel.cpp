#include "Hotel.h"
#include<iostream>
using namespace std;

Hotel::Hotel() : name(), address(), logs()
{
	count=0;
	capacity=2;
	logCounter = 0;
	reservations = new Reservation * [capacity];
	allReservations = 0;
	lastVisitor = 0;
	allVisitors = 0;
}

size_t Hotel::getLastVisitor() const
{
	return lastVisitor;
}

Visitor Hotel::getVisitor(size_t index) const
{
	return visitors[index];
}

Log Hotel::getLog(size_t index) const
{
	return logs[index];
}

size_t Hotel::getLogCounter() const
{
	return logCounter;
}

void Hotel::addVisitor(const char* id, const String& name)
{
	int index = 0;
	int number = 0;
	while (id[index] != '\0')
	{
		number *= 10;
		number += (id[index++] - '0');
	}
	//visitors[lastVisitor].setID(number);
	//isitors[lastVisitor].setName(name);

	allVisitors++;
	lastVisitor++;
}

void Hotel::free()
{
	for (size_t i = 0; i < count; i++)
		delete reservations[i];
	delete[] reservations;
}

void Hotel::copyFrom(const Hotel& other)
{
	reservations = new Reservation * [other.capacity];
	count = other.count;
	capacity = other.capacity;

	//  for (size_t i = 0; i < count; i++)
	//	reservations[i] = other.reservations[i]->clone();
}

void Hotel::resize()
{
	Reservation** newCollection = new Reservation * [capacity *= 2];
	for (size_t i = 0; i <count; i++)
		newCollection[i] = reservations[i];
	delete[] reservations;
	reservations = newCollection;
}

Hotel::Hotel(const Hotel& other)
{
	copyFrom(other);
}

Hotel& Hotel::operator=(const Hotel& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Hotel::~Hotel()
{
	free();
}

void Hotel::deleteVisitor(size_t index)
{
	//customers[index].setCustomerID(0);
	//customers[index].setCustomerName("UNAVAILABLE");
	lastVisitor--;
}

void Hotel::addReservation(const char* id, const String& type, size_t days, size_t room, size_t beds)
{
	/*allReservations++;
	int index = 0;
	int number = 0;
	while (id[index] != '\0')
	{
		number *= 10;
		number += (id[index++] - '0');
	}

	size_t current = 0;
	for (int i = 0; i < lastVisitor; i++)
	{
		if (number == visitors[i].getID())
		{
			current = i;
			break;
		}
	}

	if (count == capacity)
		resize();

	if (type.compare("AI"))
	{
		AI a;
		a.setID(id);
		a.setName(visitors[current].getName());
		a.setDays(days);
		a.setRoom(room);
		a.setBeds(beds);

		visitors[current].setReservation(a);

		reservations[count++] = a.clone();
		cout << "All inclusive reservation successfully added!" << endl;
	}

	if (type.compare("UAI"))
	{
		UAI b;
		b.setID(id);
		b.setName(visitors[current].getName());
		b.setDays(days);
		b.setRoom(room);
		b.setBeds(beds);

		visitors[current].setReservation(b);

		reservations[count++] = b.clone();
		cout << "Ultra all inclusive reservation successfully added!" << endl;
	}

	if (type.compare("NO"))
	{
		NO c;
		c.setID(id);
		c.setName(visitors[current].getName());
		c.setDays(days);
		c.setRoom(room);
		c.setBeds(beds);

		visitors[current].setReservation(c);

		reservations[count++] = c.clone();
		cout << "Nights only reservation successfully added!" << endl;
	}*/
}

bool Hotel::deleteReservation(size_t index)
{

	size_t t = count;
	if (index > t - 1)
	{
		std::cout << "There is no reservation number " << index << "!" << std::endl;
		return false;
	}
	Reservation* temp;
	temp = reservations[index];
	for (size_t i = index; i < count - 1; i++)
	{
		reservations[i] = reservations[i + 1];
	}
	reservations--;
	delete temp;
	std::cout << "Erased (" << index << ")" << std::endl;
	return true;
}

void Hotel::listVisitors() const
{
	/*for (int i = 0; i < lastVisitor; i++)
	{
		cout << " Name: " << visitors[i].getName() << " ID: " << visitors[i].getID() << endl;
	}*/
}

void Hotel::listReservations() const
{
	/*for (size_t i = 0; i < count; i++)
		reservations[i]->print();*/
}

void Hotel::listVisitorReservation(const char* id) const
{
	//int index = 0;
	//int number = 0;
	//while (id[index] != '\0')
	//{
	//	number *= 10;
	//	number += (id[index++] - '0');
	//}

	//int current = 0;
	//for (int i = 0; i < lastVisitor; i++)
	//{
	//	if (number == visitors[i].getID())
	//	{
	//		current = i;
	//		break;
	//	}
	//}

	//cout << "Reservation: " << visitors[current].getReservation() << endl;
}

Hotel::Hotel(const String& name, const String& address)
{
	this->name = name;
	this->address = address;
}

void Hotel::display() const
{
	cout << "  Name: " << name << endl << "  Address: " << address << endl << "  Number of visitors: " << allVisitors << endl;
}

void Hotel::addLog(const String& data)
{
	logs[logCounter].setData(data);
	logCounter++;
}

void Hotel::exportVisitors(const char* file) {
	ofstream output(file);

	for (int i = 0; i < logCounter; i++)
		output << logs[i].getData() << endl;
	output.close();
}