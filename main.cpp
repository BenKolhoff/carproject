#include "Car.h"
#include "ServiceRecord.h"
#include <iostream>
#include <algorithm>

void findInInventory(std::vector<Car>::iterator it, std::vector<Car> inventory, int id){
	while(it != inventory.end()){
		if(it->getId() == id){
			break;
		}
		++it;
	}
}

void makeTrade(std::vector<Car>& inventory, Car tradein, Car tradeout){
	ServiceRecord outInspection("Sale inspection.", 0.0);
	tradeout.addRecord(outInspection);

	ServiceRecord inInspection("Presale inspection.", 19.95);
	tradein.addRecord(inInspection);

	auto it=inventory.begin();
	findInInventory(it, inventory, tradeout.getId());
	if(it != inventory.end()){
		inventory.erase(it);
	}
	inventory.push_back(std::move(tradein));
}

int main(int argc, char** argv){
	Car a(1985, "Toyota Hilux");
	ServiceRecord first("Oil change.", 9.95f);
	a.addRecord(first);
	std::cout << "Car a: " << a << std::endl;

	Car b(a);
	first = ServiceRecord("Radiator flush.", 19.95);
	b.addRecord(first);
	std::cout << "Car b: " << b << std::endl;
	
	std::vector<Car> inventory;
	inventory.push_back(std::move(a));
	inventory.push_back(std::move(b));

	std::cout << "Inventory is now: " << std::endl;
	for(auto it = inventory.begin(); it != inventory.end(); ++it) {
		std::cout << *it << std::endl;
	}

	Car c(b);
	c.setModel("Ford F150");
	std::cout << "Car c: " << c << std::endl;
	
	std::cout << "Customer wants to trade in " << c << std::endl;
	std::cout << "They want to get " << a << std::endl;
	makeTrade(inventory, std::move(c), std::move(a));

	std::cout << "After trade, inventory is: " << std::endl;
	std::cout << "===========================" << std::endl;
	for(auto it = inventory.begin(); it != inventory.end(); ++it){
		std::cout << *it << std::endl;
	}

	std::cout << "----------\n\n\n\n----------\n" << std::endl;

	std::vector<Car> new_inventory;

	Car firstCar(1989, "Honda Civic");
	ServiceRecord firstCarRec("Oil Change", 80.17f);
	firstCar.addRecord(firstCarRec);
	new_inventory.push_back(std::move(firstCar));

	Car secondCar(2002, "Volkswagen Something");
	ServiceRecord secondCarRecOne("Wiper Fluid", 15.19f);
	ServiceRecord secondCarRecTwo("Oil Change", 95.06f);
	secondCar.addRecord(secondCarRecOne);
	secondCar.addRecord(secondCarRecTwo);
	new_inventory.push_back(std::move(secondCar));

	Car thirdCar(2015, "Chevrolet Equinox");
	ServiceRecord thirdCarRec("New mirror", 126.34f);
	thirdCar.addRecord(thirdCarRec);
	new_inventory.push_back(std::move(thirdCar));

	Car fourthCar(1990, "Honda Odyssey");
	ServiceRecord fourthCarRecOne("Oil change", 70.40f);
	ServiceRecord fourthCarRecTwo("New tire", 180.92f);
	ServiceRecord fourthCarRecThree("Wiper fluid", 16.32f);
	fourthCar.addRecord(fourthCarRecOne);
	fourthCar.addRecord(fourthCarRecTwo);
	fourthCar.addRecord(fourthCarRecThree);
	new_inventory.push_back(std::move(fourthCar));

	Car fifthCar(2021, "Jeep Rover");
	ServiceRecord fifthCarRec("Oil change", 23.56f);
	fifthCar.addRecord(fifthCarRec);
	new_inventory.push_back(std::move(fifthCar));


	std::cout << "Final sorted inventory is: " << std::endl;
	std::cout << "===========================" << std::endl;
	std::sort(new_inventory.begin(), new_inventory.end());
	
	for(auto it = new_inventory.begin(); it != new_inventory.end(); ++it){
		std::cout << *it << std::endl;
	}

	//bool test = fourthCar < secondCar;
	//std::cout << test << std::endl;
}
