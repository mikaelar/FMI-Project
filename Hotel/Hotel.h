#pragma once
#include "Visitor.h"
#include "Reservation.h"
#include "NO.h"
#include "AI.h"
#include "UAI.h"
#include "Log.h"
const int MAX_NUMBER_OF_VISITORS = 200;

class Hotel
{

private:
	Reservation** reservations;
	size_t count;
	size_t capacity;

	void free();
	void copyFrom(const Hotel& other);
	void resize();

public:
	Hotel();
	Hotel(const String& name, const String& address);
	Hotel(const Hotel& other);
	Hotel& operator=(const Hotel& other);
	~Hotel();

private:
	String name;
	String address;
	Visitor visitors[MAX_NUMBER_OF_VISITORS];
	Log logs[MAX_NUMBER_OF_VISITORS];

	size_t logCounter;
	size_t lastVisitor;
	size_t allVisitors;
	size_t allReservations;

public:
	size_t getLastVisitor() const;
	size_t getLogCounter()const;
	Visitor getVisitor(size_t index) const;
	Log getLog(size_t index)const;

	void addVisitor(const char* id, const String& name);
	void deleteVisitor(size_t index);
	void addReservation(const char* id, const String& type, size_t days, size_t room, size_t beds);
	bool deleteReservation(size_t index);

	void listVisitors() const;
	void listReservations() const;
	void listVisitorReservation(const char* id) const;

	void addLog(const String& visitorName);              //adds visitors to log array
	void exportVisitors(const char* file);               //saves visitors to file

	void display() const;
};