#include "Car.h"
#include <iostream>

int Car::current_id = 0;

// Default constructor
Car::Car(int year, std::string model){
	this->id = Car::current_id++;
	this->year = year;
	this->model = model;
}

// Copy constructor
Car::Car(const Car& other) {
	this->id = Car::current_id++;
	this->year = other.year;
	this->model = other.model;
	this->records = other.getRecords();
	
	std::cout << "Copy constructor called" << std::endl;
}

// Copy operator constructor
Car& Car::operator=(const Car& other) {
	this->id = other.id;
	this->year = other.year;
	this->model = other.model;

	return *this;
}

// Move constructor
Car::Car(const Car&& other) noexcept {
	std::cout << "Move constructor called" << std::endl;
	if (this != &other) {
		this->id = other.id;
		this->year = other.year;
		this->model = other.model;
		this->records = other.getRecords();
	}
}

bool Car::operator<(const Car& other) {
	std::cout << "Whatever this is is called" << std::endl;

	double this_cost = 0;
	
	for (auto it = records.begin(); it != records.end(); ++it) {
		std::cout << "specific iteration of this_cost: " << (*it).getCost() << std::endl;
		this_cost += (*it).getCost();
	}
	
	std::cout << "This_cost: " << this_cost << std::endl;
	
	double other_cost = 0;

	for (auto it = other.records.begin(); it != other.records.end(); ++it) {
		other_cost += (*it).getCost();
	}

	std::cout << "other_Cost: " << other_cost << std::endl;

	return this_cost < other_cost;
}

int Car::getId() const {
	return this->id;
}

void Car::setYear(int year){
	this->year = year;
}

int Car::getYear() const {
	return year;
}

void Car::setModel(std::string model){
	this->model = model;
}

std::string Car::getModel() const {
	return model;
}

std::vector<ServiceRecord> Car::getRecords() const {
	return records;
}

void Car::addRecord(ServiceRecord record){
	records.push_back(record);
}

std::ostream& operator<<(std::ostream& os, const Car& car){
	os << car.id << ":" << car.year << " " << car.model << std::endl;
	os << "=========================" << std::endl;
	for(auto it=car.records.begin(); it != car.records.end(); ++it){
		os << "\t" << it->getCost() << ": " << it->getNotes() << std::endl;
	}
	return os;
}
