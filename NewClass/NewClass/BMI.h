// Header ==> Function Declarations

#include <iostream>
#include <string>

using namespace std;

#ifndef BMI_H
	#define BMI_H
class BMI 
{
	public: 
		//Default Constructor
		BMI();

		//Overload Constructor
		BMI(string, int, double);

		//Destructor
		~BMI();

		//Accessor Function
		string getName() const;
			// getName - returns name of patient

		int getHeight() const;
			// getHeight - returns height of patient

		double getWeight() const;
			// getWeight - returns weight of patient

		//Mutator Functions
		void setName(string);
			//	setName - set name of patient
			// @param string - name of patient
		void setHeight(int);
			//	setHeight - set Height of patient
			// @param int - Height of patient
		void setWeight(double);
			//	setWeight - set Weight of patient
			// @param double - Weight of patient
		
		double calculateBMI();
			//	calculateBMI - calculateBMI of patient
			// @param double - BMI of patient
		
	private: 
		//Member Variable
		string newName;
		int newHeight;
		double newWeight;
};
#endif 
