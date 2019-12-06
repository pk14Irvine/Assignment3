#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal(string n, string f) : name(n), food(f) {}
	virtual void display() const = 0;
	virtual float calcFoodAmt() const = 0;
	virtual float calcVetCost() const = 0;
protected:
	string name, food;
};

class Mammal : public Animal
{
public:
	Mammal(string n, string f, int a, int w) : age(a), weight(w),Animal(n,f) {}
	virtual void display() const;
	virtual float calcFoodAmt() const;
	virtual float calcVetCost() const;
protected:
	int age, weight;
};

class Bird : public Animal
{
public:
	Bird(string n, string f, float w) : weight(w), Animal(n, f) {}
	virtual void display() const;
	virtual float calcFoodAmt() const;
	virtual float calcVetCost() const;
protected:
	float weight;
};

class Fish : public Animal
{
public:
	Fish(string n, string f, int l) : length(l), Animal(n, f) {} 
	virtual void display() const;
	virtual float calcFoodAmt() const;
	virtual float calcVetCost() const;
protected:
	int length;
};

class Reptile : public Animal
{
public:
	Reptile(string n, string f) : Animal(n, f) {}
	virtual void display() const;
	virtual float calcFoodAmt() const;
	virtual float calcVetCost() const;
};

class Amphibian : public Animal
{
public:
	Amphibian(string n, string f) : Animal(n, f) {} 
	virtual void display() const;
	virtual float calcFoodAmt() const;
	virtual float calcVetCost() const;
};


float Mammal::calcVetCost() const
{
	float cash = 0;
	if (age <= 12)
	{
		cash = 200;
	}
	if (age >= 13 && age <= 96)
	{
		cash = 200;
	}
	if (age > 96)
	{
		cash = 500;
	}
	return cash;
}

float Bird::calcVetCost() const
{
	float cash = 0;
	if (weight <= .5)
	{
		cash = 100;
	}
	if (weight > .5)
	{
		cash = 250;
	}
	return cash;
}

float Fish::calcVetCost() const
{
	return 0;
}

float Reptile::calcVetCost() const
{
	return 175.0;
}

float Amphibian::calcVetCost() const
{
	return 0;
}

float Mammal::calcFoodAmt() const
{
	int freq = 0;
	if (age <= 12)
	{
		freq = 5;
	}
	if (age >= 13 && age <= 24)
	{
		freq = 4;
	}
	if (age > 24)
	{
		freq = 3;
	}
	float amount = weight / 5;
	return freq * amount * 365;
}

float Bird::calcFoodAmt() const
{
	int freq = 0;
	if (weight <= .5)
	{
		freq = 3;
	}
	if (weight > .5)
	{
		freq = 2;
	}
	float amount = .5 * weight;
	return freq * amount * 365;
}

float Fish::calcFoodAmt() const
{
	int freq = 0;
	if (length <= 30)
	{
		freq = 2;
	}
	if (length > 30)
	{
		freq = 1;
	}
	float amount = 1.5;
	return freq * amount * 365;
}

float Reptile::calcFoodAmt() const
{
	return 2 * 1 * 52;
}

float Amphibian::calcFoodAmt() const
{
	return 1 * .5 * 365;
}

void Mammal::display() const
{
	cout << "Name: " << name << endl;
	cout << "Type: Mammal" << endl;
	cout << "Food: " << food << endl;
}
void Bird::display() const
{
	cout << "Name: " << name << endl;
	cout << "Type: Bird" << endl;
	cout << "Food: " << food << endl;
}
void Fish::display() const
{
	cout << "Name: " << name << endl;
	cout << "Type: Fish" << endl;
	cout << "Food: " << food << endl;
}
void Reptile::display() const
{
	cout << "Name: " << name << endl;
	cout << "Type: Reptile" << endl;
	cout << "Food: " << food << endl;
}
void Amphibian::display() const
{
	cout << "Name: " << name << endl;
	cout << "Type: Amphibian" << endl;
	cout << "Food: " << food << endl;
}

/*
Arguments for the contructors should be passed in the following order:

Mammal:     name, food, age, weight
Bird:     name, food, weight
Fish:     name, food, weight
Reptile:     name, food
Amphibian:     name, food

*/