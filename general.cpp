#include "p3_header.h"

// file name: general.cpp

// Student: Ben Austin, CS202 001, Novemebr 28th  2021, Program 3, bena2@pdx.edu

// The general.cpp file is used to implement general functions within the 
// animal, super animal, animal date, and car classes.

/*********** Animal **********/

// The Constructor intializes all data members to their zero equivalent values. 
// Inputs: NA
// Outputs: NA
animal:: animal()
{
	age =0;
	
}


// The Compare animal function compares the current object to the animal object passed in. 
// Inputs: Source: The animal to be compared. 
// Outputs: 0 less than, 1 equal, 2 greater than. 
int animal:: compare_animal(const animal & source) const
{
	if(a_name==source.a_name)
		return 1;
	if(a_name>source.a_name)
		return 2;
	return 0;
}


// The Input Animal function prompts the user through entering the animal information. 
// Inputs: View: viewing type (defaults to no specific type).
// Outputs: Returns 1 upon success and 0 upon failure. 
int  animal:: input_animal(int view)
{
	// The users viewing choice. 
	char type_S;

	cout << "Please enter the name of the animal: ";
	getline(cin, a_name);

	cout << "Please enter the species of the animal: ";
	getline(cin,species);

	do
	{
		cout << "Please enter the age of the animal: ";
		cin >> age;
	}
	while(len());

	if(view==0)
	{
		do { 
			cout << "Please select viewing type: \n"
				<< "A: Aquatic \n"
				<< "B: Farm \n"
				<< "C: Sanctuary \n"
				<< "Please enter your choice: ";
			cin >> type_S;
			type_S=toupper(type_S);
		}while(len() || (type_S!='A' && type_S!='B' && type_S!='C'));
	}

	else if(view==1)
		type_S = 'A';
	else if(view==2)
		type_S = 'B';
	else 
		type_S = 'C';

	switch(type_S)
	{
		case 'A': type ="Aquatic";
			  break;
		case 'B': type="Farm";
			  break;
		case 'C': type="Sanctuary";
		default: type="";
	}

	cout << "Please enter the location: ";
	getline(cin, location);
	a_to_upper(location);
	if(age>-0) return 1;
	return 0;
}

// The Display function outputs the animal information. 
// Inputs: Out: The output stream to be used. 
// Outputs: NA
void animal:: display(ostream & out) const
{
	out << "Animal being viewed: \n"
	    << "Name: " <<  a_name << endl
	    << "Species: " << species << endl
	    << "Age: " << age << endl
	    << "Viewing type: " << type << endl
	    << "Viewing Location: " << location << endl;
}


// The == operator compares both animal objects. 
// Inputs: Source: The animal to be compared. 
// 	   To Compare: The animal to be compared. 
// Outputs: Returns true if source is equal to to compare, and
// 	    false if not. 
bool operator==(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)==1)
		return true;
	return false;
}


// The == operator compares an animal object and a string. 
// Inputs: Source: The animal to be compared. 
// 	   To Compare: The string to be compared.
// Outputs: Returns true if source is equal to to compare, and
// 	    false if not. 
bool operator==(const animal & source, const string & to_compare)
{
	if(source.location == to_compare) 
		return true;
	return false;
}


// The == operator compares an animal object and a string. 
// Inputs: To Compare: The animal to be compared. 
// 	   Source: The string to be compared.
// Outputs: Returns true if source is equal to to compare, and
// 	    false
bool operator==(const string & source, const animal & to_compare)
{
	if(source==to_compare.location)
		return true;
	return false;
}

// The != operator compares both animal objects. 
// Inputs: Source: The animal to be compared. 
//         To Compare: The animal to be compared. 
// Outputs: Returns true if source is not equal to to compare, and
//          false if not. 
bool operator!=(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)!=1)
		return true;
	return false;
}


// The != operator compares an animal object and a string. 
// Inputs: Source: The animal to be compared. 
//         To Compare: The string to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool operator!=(const animal & source, const string & to_compare)
{
	if(source.location != to_compare) 
		return true;
	return false;
}

// The != operator compares an animal object and a string.
// Inputs: To Compare: The animal to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false.
bool operator!=(const string & source, const animal & to_compare)
{
	if(source!=to_compare.location)
		return true;
	return false;
}

// The >  operator compares both animal objects. 
// Inputs: Source: The animal to be compared. 
//         To Compare: The animal to be compared. 
// Outputs: Returns true if source is greater than to to compare, and
//          false if not. 
bool operator>(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)==2)
		return true;
	return false;
}


// The > operator compares an animal object and a string.
// Inputs: Source: The animal to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is greater to to compare, and
//          false if not.
bool operator>(const animal & source, const string & to_compare)
{
	if(source.location>to_compare)
		return true;
	return false;
}


// The > operator compares an animal object and a string.
// Inputs: To Compare: The animal to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is greater than to compare, and
//          false.
bool operator>(const string & source, const animal & compare)
{
	if(source>compare.location)
		return true;
	return false;
}



// The >=  operator compares both animal objects. 
// Inputs: Source: The animal to be compared. 
//         To Compare: The animal to be compared. 
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not. 
bool operator>=(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares an animal object and a string.
// Inputs: Source: The animal to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is greater/ equal to  to compare, and
//          false if not.
bool operator>=(const animal & source, const string & to_compare)
{
	if(source.location>=to_compare)
		return true;
	return false;
}


// The >= operator compares an animal object and a string.
// Inputs: To Compare: The animal to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false.
bool operator>=(const string & source, const animal & compare)
{
	if(source>=compare.location)
		return true;
	return false;
}


// The < operator compares both animal objects.
// Inputs: Source: The animal to be compared.
//         To Compare: The animal to be compared.
// Outputs: Returns true if source is less than  to compare, and
//          false if not.
bool operator<(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)==0)
		return true;
	return false;
}


// The < operator compares an animal object and a string.
// Inputs: Source: The animal to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool operator<(const animal & source, const string & to_compare)
{
	if(source.location<to_compare)
		return true;
	return false;
}


// The < operator compares an animal object and a string.
// Inputs: To Compare: The animal to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false.
bool operator<(const string & source, const animal & compare)
{
	if(source<compare.location)
		return true;
	return false;
}


// The <= operator compares both animal objects.
// Inputs: Source: The animal to be compared.
//         To Compare: The animal to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool operator<=(const animal & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares an animal object and a string.
// Inputs: Source: The animal to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool operator<=(const animal & source, const string & to_compare)
{
	if(source.location<=to_compare)
		return true;
	return false;
}


// The <= operator compares an animal object and a string.
// Inputs: To Compare: The animal to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false.
bool operator<=(const string & source, const animal & compare)
{
	if(source<=compare.location)
		return true;
	return false;
}


// The Constructor intializes all data members to their zero equivalent values. 
animal_date:: animal_date(): guest_count(0)
{
}


// The Constructor copies the event date data into the animal date class. 
// Inputs: Source: The event date data to be copied.
// Outputs: NA
animal_date:: animal_date(const event_date & source, int source2):event_date(source), guest_count(source2)
{
}

// The Display function outputs the animal date data. 
// Inputs: Out: The output buffer to be used. 
// Outputs: NA
int animal_date:: display(ostream & out)
{
	out << static_cast<event_date&>(*this) << static_cast<event_time&>(*this) << 
	     " Current Occupancy: " << guest_count << endl;
	return 1;
}

// The Check Guest function determines whether any guests can be added to the 
// date and time. 
// Inputs: To Add: the number of guests to add. 
//         Max: The max number of guests the animal can hold. 
// Outputs: Returns 0 upon failure and 1 upon success. 
int animal_date:: check_guest(int to_add, int max)
{
	if(to_add+guest_count>max)
	{
		return 0;
	}
	return 1;
}

// The Add Guest function adds the number of guests passed in to the animal 
// date. 
// Inputs: To Add: The number of guests to add. 
// Outputs: NA
void animal_date:: add_guest(int to_add)
{
	guest_count+=to_add;
}


// The Constructor intializes all data members to their zero equivalent values. 
super_animal:: super_animal():max_guest(0)
{
}


// The Input Animal function prompts the user through inputing animal data. 
// Inputs: View: The type of animal to be created. 
// Outputs: Returns 1 upon success and 0 upon failure. 
int super_animal::input_animal(int view)
{
	animal::input_animal(view);

	cout << "Please enter the animal's max guest occupancy: ";
	cin >> max_guest;
	len();
	cout << endl << endl;

	return 1;
}


// The Display function outputs all animal data. 
// Inputs: Out: The output buffer to be used. 
// Outputs: returns 1 upon success and 0 upon failure. 
int super_animal:: display(ostream & out)
{

	animal::display(out);
	cout << "Max Occupency: " << max_guest << endl;
	cout << "Current Reservation List: \n";

	auto it = res_list.begin();
	while(it!=res_list.end())
	{
		it->display(out);
		++it;
	}
	return 1;
}
	

// The Check Availability functions determines whether there is availbility during the 
// requested time period. 
// Inputs: Res: The reservation time request. 
// Outputs: Returns false upon success and true upon failure.
bool  super_animal:: check_availability(const event & res)
{
	bool found = false;

	auto it = res_list.begin();
	while(it!=res_list.end() && !found)
	{
		if(res ==  *it)
			found = true;
		else 
			++it;
	}
	if(!found)
	{
		if(res.get_guest()<=max_guest)
		{
			animal_date temp(res, res.get_guest());
			res_list.push_back(temp);
			return false;
		}
		else return true;
	}
	if(it->check_guest(res.get_guest(), max_guest))
	{
		it->add_guest(res.get_guest());
		return false;
	}
	else
		return true;
}

/******** Car **********/


// The Constructor intializes all data members to zero. 
// Inputs: NA
// Outputs: NA
car:: car()
{
}

// The Compare car function compares the current object to the car object passed in. 
// Inputs: Source: The car to be compared. 
// Outputs: 0 less than, 1 equal, 2 greater than.
int car:: compare_car(const car & to_compare) const
{
	if(plate==to_compare.plate)
		return 1;
	if(plate>to_compare.plate)
		return 2;
	return 0;
}


// The Input car function prompts the user through entering the car information.
// Inputs: NA
// Outputs: Returns 1 upon success and 0 upon failure.
int car:: input_car()
{
	cout << "Please enter the vehicle's plate number: ";
	getline(cin, plate);

	cout << "Please enter the type of vehicle: ";
	getline(cin, type);

	cout << "Please enter the vehicle's color: ";
	getline(cin, color);

	if(plate!="") return 1;
	return 0;
}

// The Display function outputs the car information.
// Inputs: Out: The output stream to be used.
// Outputs: NA
void car:: display(ostream & out) const
{
	out << "\nVehicle information: \n"
	    << "Plate Number: " << plate << endl
	    << "Type: " << type << endl
	    << "Color: " << color << endl;
}

// The == operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool operator==(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)==1)
		return true;
	return false;
}


// The ==  operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool operator==(const car & source, const string & to_compare)
{
	if(source.plate == to_compare) 
		return true;
	return false;
}


// The == operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false.
bool operator==(const string & source, const car & to_compare)
{
	if(source==to_compare.plate)
		return true;
	return false;
}


// The != operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool operator!=(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)!=1)
		return true;
	return false;
}


// The != operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool operator!=(const car & source, const string & to_compare)
{
	if(source.plate != to_compare) 
		return true;
	return false;
}


// The != operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false.
bool operator!=(const string & source, const car & to_compare)
{
	if(source!=to_compare.plate)
		return true;
	return false;
}

// The > operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is greater than to compare, and
//          false if not.
bool operator>(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)==2)
		return true;
	return false;
}


// The > operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is greater than to compare, and
//          false if not.
bool operator>(const car & source, const string & to_compare)
{
	if(source.plate>to_compare)
		return true;
	return false;
}


// The > operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is greater than to compare, and
//          false.
bool operator>(const string & source, const car & compare)
{
	if(source>compare.plate)
		return true;
	return false;
}


// The >= operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is greater than/ equal to to compare, and
//          false if not.
bool operator>=(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool operator>=(const car & source, const string & to_compare)
{
	if(source.plate>=to_compare)
		return true;
	return false;
}


// The >= operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false.
bool operator>=(const string & source, const car & compare)
{
	if(source>=compare.plate)
		return true;
	return false;
}


// The <  operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool operator<(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)==0)
		return true;
	return false;
}


// The < operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool operator<(const car & source, const string & to_compare)
{
	if(source.plate<to_compare)
		return true;
	return false;
}


// The < operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false.
bool operator<(const string & source, const car & compare)
{
	if(source<compare.plate)
		return true;
	return false;
}


// The <= operator compares both car objects.
// Inputs: Source: The car to be compared.
//         To Compare: The car  to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool operator<=(const car & source, const car & to_compare)
{
	if(source.compare_car(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares an car object and a string.
// Inputs: Source: The car to be compared.
//         To Compare: The string to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool operator<=(const car & source, const string & to_compare)
{
	if(source.plate<=to_compare)
		return true;
	return false;
}


// The <= operator compares an car object and a string.
// Inputs: To Compare: The car to be compared.
//         Source: The string to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false.
bool operator<=(const string & source, const car & compare)
{
	if(source<=compare.plate)
		return true;
	return false;
}







