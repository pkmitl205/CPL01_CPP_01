//Function Definitions

#include "BMI.h"

BMI::BMI()
{
	newHeight = 0;
	newWeight = 0.0;
}

BMI::BMI(string name, int height, double weight)
{
	newName = name;
	newHeight = height;
	newWeight = weight;
}

BMI::~BMI()
{
	
}

string BMI::getName() const
{
	return newName;
}

int BMI::getHeight() const
{
	return newHeight;
}

double BMI::getWeight() const
{
	return newWeight;
}

void BMI::setName(string name)
{
	newName = name;
}

void BMI::setHeight(int height)
{
	newHeight = height;
}

void BMI::setWeight(double weight)
{
	newWeight = newWeight;
}

double BMI::calculateBMI()
{
	return ((newWeight * 703) / (newHeight * newWeight));
}