#include "p3_header.h"
// file name: event.cpp

// Student: Ben Austin, CS202 001, Novemebr 28th  2021, Program 3, bena2@pdx.edu

// The event.cpp file is used to implement general functions within the 
// event heirarchy.


/************* Event ************/

// The Constructor intializes all data members to their zero equivalent value and calls the base class 
// constructor. 
// Inputs: Source_id: The intial value for booking id. 
//         Source_guest: The intial value for the guests. 
//         Source Month: value month should be intitalized to.
//         Source Day: value day should be intitalized to.
//         Source Year: value year should be intitalized to.
//         Source Hour: to be passed to event time constructor.
//         Source Minute: to be passed to event time constructor.
//         Source Period: to be passed to event time constructor.
//         Source Source Full Name: to be passed to event time constructor.
// Outputs: NA
event:: event( int source_id, int source_guests, int source_month, int source_day, 
	       int source_year, int source_hour, int source_minute, string * source_period, 
	       char * source_full_name): event_date(source_month, source_day, source_year,
	       source_hour, source_minute, source_period, source_full_name), booking_id(source_id),
	       guests(source_guests)
{

}

// The Constructor intitalizes all data members to zero and calls the base class 
// constructor. 
// Inputs: Source: the object to be passed to the event date constructor. 
// Outputs: NA
event:: event(const event_date & source): event_date(source), booking_id(0), guests(0)
{
}

int event:: get_guest() const
{
	return guests;
}


// The event destructor exists just incase any future derived classes have a destructor. 
// Inputs: NA
// Outputs: NA
event:: ~event()
{
	booking_id =0;
	guests =0;
}


// The Input Function is implemented in derived classes. 
int event:: input(int s_id, const animal & source)
{
	return 0;
}

// The Input function prompts the user through inputing the event data. 
// Inputs: S_id: The event booking id. 
//         Type: Is passed down to the event time input function to 
//               guide viewing type selection. 
// Outputs: Returns 1 upon success and zero upon failure. 
int event:: input(int s_id, int type)
{
	event_date::input_date(type);
	do
	{
		cout << "How many guests are in your party: ";
		cin >> guests;
	}
	while(len());

	booking_id=s_id;

	if(booking_id) return 1;
	return 0;
}


// The Display function outputs the event data as well as all base class data. 
// Inputs: Out: the output buffer to be used. 
// Outputs: NA
void event:: display(ostream & out)  const
{
	out << "Reservation: " << booking_id << endl
	    << "Reservation for: " << static_cast<const name&>(*this) << endl
	    << "Date: " << static_cast<const event_date&>(*this) << " Time: " << static_cast<const event_time&>(*this) << endl
	    << "Number of guests in party: " << guests << endl;
}


// The Compare ID function compares the id passed in to that of the current object. 
// Inputs: S_id: the source id to be compared. 
// Outputs: 0 less than, 1 equal to, 2 greater than.
int event:: compare_id(int s_id) const
{
	if(booking_id>s_id)
		return 2;
	if(booking_id==s_id)
		return 1;
	return 0;
}


// The Compare ID function compares the id passed in to that of the current object. 
// Inputs: Source: the event object whose id will be compared. 
// Outputs: 0 less than, 1 equal to, 2 greater than.
int event:: compare_id(const event & source) const
{
	if(booking_id>source.booking_id)
		return 2;
	if(booking_id==source.booking_id)
		return 1;
	return 0;
}


// The Compare location function is implemented in the derived classes. 
int event:: compare_location(const string & to_compare) const
{
	return 0;
}


// The Compare Animal function is implemented in the derived classes. 
int event:: compare_animal( const animal & to_compare) const 
{
	return 0;
}


// The Compare Car function is implemented in the derived class. 
int event:: compare_car(const car & to_compare) const 
{
	return 0;
}


// The << operator calls the source display function (source is upcasted)
// display is called via dynamic binding. 
// Inputs: Out: the output buffer to be used. 
//         Source: reference to the object ot be displayed. 
// Outputs: Modified output buffer.
ostream & operator<<(ostream & out, const event & source)
{
	source.display(out);
	return out;
}


// The > operator compares the source to to compare argument. 
// Inputs: Source: the string to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)<1)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the string to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)>1)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the event to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)>0)
		return true;
	return false;
}



// The > operator compares the source to to compare argument. 
// Inputs: Source: the event to be compared. 
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)==2)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the event to be compared. 
//         Source: The integer to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)==0)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: Source: the animal to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)==0)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the animal to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)==2)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the car to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)==0)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: Source: the car to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)==2)
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: To Compare: the event date  to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator>(to_compare))
		return true;
	return false;
}


// The > operator compares the source to to compare argument. 
// Inputs: Source: the event date  to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and 
//          false if not. 
bool  operator>(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator>(to_compare))
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: Source: the string to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)<=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: To Compare: the string to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument. 
// Inputs: To Compare: the event to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and 
//          false if not. 
bool  operator>=(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: Source: the event to be compared.
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The integer to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)<=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: Source: the animal to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)<=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument. 
// Inputs: To Compare: the animal to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and 
//          false if not.
bool  operator>=(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: To Compare: the car to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)<=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: Source: the car to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)>=1)
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: To Compare: the event date  to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator>=(to_compare))
		return true;
	return false;
}


// The >= operator compares the source to to compare argument.
// Inputs: Source: the event date  to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is greater than/equal to to compare, and
//          false if not.
bool  operator>=(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator>=(to_compare))
		return true;
	return false;
}


// The <= operator compares the source to to compare argument. 
// Inputs: Source: the string to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and 
//          false if not. 
bool  operator<=(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)>=1)
		return true;
	return false;
}

// The <= operator compares the source to to compare argument. 
// Inputs: To Compare: the string to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and 
//          false if not. 
bool  operator<=(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)<=1)
		return true;
	return false;
}


// The <=  operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is greater than to compare, and
//          false if not.
bool  operator<=(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument.
// Inputs: Source: the event to be compared.
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool  operator<=(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The integer to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not. 
bool  operator<=(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)>=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument. 
// Inputs: Source: the animal to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and 
//          false if not. 
bool  operator<=(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)>=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument. 
// Inputs: To Compare: the animal to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and 
//          false if not. 
bool  operator<=(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument.
// Inputs: To Compare: the car to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool  operator<=(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)>=1)
		return true;
	return false;
}


// The <=  operator compares the source to to compare argument.
// Inputs: Source: the car to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool  operator<=(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)<=1)
		return true;
	return false;
}


// The <= operator compares the source to to compare argument.
// Inputs: To Compare: the event date  to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool  operator<=(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator<=(to_compare))
		return true;
	return false;
}


// The <= operator compares the source to to compare argument.
// Inputs: Source: the event date  to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than/equal to to compare, and
//          false if not.
bool  operator<=(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator<=(to_compare))
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: Source: the string to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)>1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: To Compare: the string to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)<1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not
bool  operator<(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)<1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: Source: the event to be compared.
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)<1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The integer to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)>1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: Source: the animal to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)>1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: To Compare: the animal to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)<1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument. 
// Inputs: To Compare: the car to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is less than to compare, and 
//          false if not. 
bool  operator<(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)>1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: Source: the car to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)<1)
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: To Compare: the event date  to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator<(to_compare))
		return true;
	return false;
}


// The < operator compares the source to to compare argument.
// Inputs: Source: the event date  to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is less than to compare, and
//          false if not.
bool  operator<(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator<(to_compare))
		return true;
	return false;
}



// The == operator compares the source to to compare argument. 
// Inputs: Source: the string to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and 
//          false if not. 
bool  operator==(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: To Compare: the string to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument. 
// Inputs: To Compare: the event to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and 
//          false if not. 
bool  operator==(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: Source: the event to be compared.
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The integer to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: Source: the animal to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: To Compare: the animal to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: To Compare: the car to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)==1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: Source: the car to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)==1)
		return true;
	return false;
}


// The ==  operator compares the source to to compare argument.
// Inputs: To Compare: the event date  to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator==(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator==(to_compare))
		return true;
	return false;
}


// The == operator compares the source to to compare argument. 
// Inputs: Source: the event date  to be compared. 
//         To Compare: The event to be compared.
// Outputs: Returns true if source is equal to to compare, and 
//          false if not.
bool  operator==(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator==(to_compare))
		return true;
	return false;
}


// The !=  operator compares the source to to compare argument.
// Inputs: Source: the string to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const string & source, const event & to_compare)
{
	if(to_compare.compare_location(source)!=1)
		return true;
	return false;
}



// The !=  operator compares the source to to compare argument.
// Inputs: To Compare: the string to be compared.
//         To Source: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event & source, const string & to_compare)
{
	if(source.compare_location(to_compare)!=1)
		return true;
	return false;
}


// The == operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event  & source, const event & to_compare)
{
	if(source.compare_id(to_compare)!=1)
		return true;
	return false;
}


// The !=  operator compares the source to to compare argument.
// Inputs: Source: the event to be compared.
//         To Compare: The integer to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event  & source , int to_compare)
{
	if(source.compare_id(to_compare)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument.
// Inputs: To Compare: the event to be compared.
//         Source: The integer to be compared.
// Outputs: Returns true if source is equal to to compare, and
//          false if not.
bool  operator!=(int source, const event & to_compare)
{
	if(to_compare.compare_id(source)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument.
// Inputs: Source: the animal to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const animal & source, const event & to_compare)
{
	if(to_compare.compare_animal(source)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument. 
// Inputs: To Compare: the animal to be compared. 
//         Source: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and 
//          false if not.
bool  operator!=(const event & source, const animal & to_compare)
{
	if(source.compare_animal(to_compare)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument.
// Inputs: Source: the car to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const car & source, const event & to_compare)
{
	if(to_compare.compare_car(source)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument.
// Inputs: To Compare: the car to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event & source, const car & to_compare)
{
	if(source.compare_car(to_compare)!=1)
		return true;
	return false;
}


// The != operator compares the source to to compare argument.
// Inputs: To Compare: the event date  to be compared.
//         Source: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event  & source, const event_date & to_compare)
{
	if(source.event_date::operator!=(to_compare))
		return true;
	return false;
}


// The !=  operator compares the source to to compare argument.
// Inputs: Source: the event date  to be compared.
//         To Compare: The event to be compared.
// Outputs: Returns true if source is not equal to to compare, and
//          false if not.
bool  operator!=(const event_date & source, const event & to_compare)
{
	if(source.event_date::operator!=(to_compare))
		return true;
	return false;
}


/********* Aquatic ************/

// The Constructor intializes all data members to their zero equivalent value and calls the base class 
// constructor. 
// Inputs: S_animal: Pointer to animal object to be copied into subject member. 
// 	   S_time: The reserved time to be copied into the reserved time member. 
// 	   Source_id: The intial value for booking id. 
//         Source_guest: The intial value for the guests. 
//         Source Month: value month should be intitalized to.
//         Source Day: value day should be intitalized to.
//         Source Year: value year should be intitalized to.
//         Source Hour: to be passed to event time constructor.
//         Source Minute: to be passed to event time constructor.
//         Source Period: to be passed to event time constructor.
//         Source Source Full Name: to be passed to event time constructor.
// Outputs: NA
aquatic:: aquatic(animal * s_animal, int s_time,  int source_id, int source_guests, int source_month, int source_day,
               int source_year, int source_hour, int source_minute, string * source_period,
               char * source_full_name): event(source_id, source_guests, source_month, source_day, source_year,
               source_hour, source_minute, source_period, source_full_name), reserved_time(s_time)
{
	if(s_animal)
		subject = *s_animal;
}

// The Constructor intitalizes all data members to zero and calls the base class
// constructor.
// Inputs: Source: the object to be passed to the event constructor.
// Outputs: NA
aquatic:: aquatic(const event & source): event(source), reserved_time(0)
{
}


// The Input function prompts the user through inputing the aquatic event data.
// Inputs: id: The event booking id.
//         Source: Animal object to be copied into the event.
// Outputs: Returns 1 Upon success and zero upon failure. 
int aquatic:: input(int id, const animal & source)
{
	event::input(id);

	do
	{
		cout << "Amount of time you would like to reserve(1 or 2 hours): ";
		cin >> reserved_time;
	}
	while(len() || (reserved_time!=1 && reserved_time !=2));

	subject = source;
	if(subject == source) return 1;
	return 0;
}


// The Compare Animal function compares the anima stored in subject to the source 
// animal passed in via argument. 
// Inputs: Source: THe animal to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int aquatic:: compare_animal(const animal & source) const
{
	if(subject == source)
		return 1;
	if(subject > source)
		return 2;
	return 0;
}


// The Compare Location function compares the location stored in subject to the source 
// location passed in via argument. 
// Inputs: Source: The location to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int aquatic:: compare_location(const string & source) const
{
	if(subject==source)
		return 1;	
	if(subject>source) 
		return 2;
	return 0;
}

// The Display function outputs the event data as well as all base class data. 
// Inputs: Out: the output buffer to be used. 
// Outputs: NA
void aquatic:: display(ostream & out) const
{
	out << "Aquatic Animal Viewing for " << reserved_time << " hours" << endl;	
	event::display(out);
	cout << endl << endl;
	subject.display(out);
	cout << endl << endl;
}


/********* Farm **************/

// The Constructor intializes all data members to their zero equivalent value and calls the base class
// constructor.
// Inputs: S_animal: Pointer to animal object to be copied into subject member.
//         S_time: The reserved time to be copied into the reserved time member.
//         Source_id: The intial value for booking id.
//         Source_guest: The intial value for the guests.
//         Source Month: value month should be intitalized to.
//         Source Day: value day should be intitalized to.
//         Source Year: value year should be intitalized to.
//         Source Hour: to be passed to event time constructor.
//         Source Minute: to be passed to event time constructor.
//         Source Period: to be passed to event time constructor.
//         Source Source Full Name: to be passed to event time constructor.
// Outputs: NA
farm:: farm(animal * s_animal,int s_time,  int source_id, int source_guests, int source_month, int source_day,
               int source_year, int source_hour, int source_minute, string * source_period,
               char * source_full_name): event(source_id, source_guests, source_month, source_day, source_year,
               source_hour, source_minute, source_period, source_full_name), reserved_time(s_time)
{
	if(s_animal)
		subject = *s_animal;
}


// The Constructor intitalizes all data members to zero and calls the base class
// constructor.
// Inputs: Source: the object to be passed to the event constructor.
// Outputs: NA
farm:: farm(const event & source): event(source), reserved_time(0)
{
}


// The Input function prompts the user through inputing the aquatic event data.
// Inputs: id: The event booking id.
//         Source: Animal object to be copied into the event.
// Outputs: Returns 1 Upon success and zero upon failure. 
int farm:: input(int id, const animal & source) 
{
	event::input(id);

	do
	{
		cout << "Amount of time you would like to reserve(1 or 2 hours): ";
		cin >> reserved_time;
	}
	while(len() || (reserved_time!=1 &&reserved_time !=2));

	subject = source;
	if(subject == source) return 1;
	return 0;
}


// The Compare Animal function compares the anima stored in subject to the source 
// animal passed in via argument. 
// Inputs: Source: THe animal to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int farm:: compare_animal(const animal & source) const
{
	if(subject == source)
		return 1;
	if(subject > source)
		return 2;
	return 0;
}


// The Compare Location function compares the location stored in subject to the source 
// location passed in via argument. 
// Inputs: Source: The location to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int farm:: compare_location(const string & source) const
{
	if(subject==source)
		return 1;
	
	if(subject>source) 
		return 2;

	return 0;
}


// The Display function outputs the event data as well as all base class data. 
// Inputs: Out: the output buffer to be used. 
// Outputs: NA
void farm:: display(ostream & out) const
{
	out << "Farm Animal Viewing for " << reserved_time << " hours" << endl;
	
	event::display(out);
	cout << endl << endl;
	subject.display(out);
	cout << endl << endl;
}


/******** Sanctuary **********/

// The Constructor intializes all data members to their zero equivalent value and calls the base class
// constructor.
// Inputs: S_animal: Pointer to animal object to be copied into subject member.
//         S_car: The car to be copied into the car member. 
//         Source_id: The intial value for booking id.
//         Source_guest: The intial value for the guests.
//         Source Month: value month should be intitalized to.
//         Source Day: value day should be intitalized to.
//         Source Year: value year should be intitalized to.
//         Source Hour: to be passed to event time constructor.
//         Source Minute: to be passed to event time constructor.
//         Source Period: to be passed to event time constructor.
//         Source Source Full Name: to be passed to event time constructor.
// Outputs: NA
sanctuary:: sanctuary(animal * s_animal,car * s_car,  int source_id, int source_guests, int source_month, int source_day,
               int source_year, int source_hour, int source_minute, string * source_period,
               char * source_full_name): event(source_id, source_guests, source_month, source_day, source_year,
               source_hour, source_minute, source_period, source_full_name)
{
	if(s_car)
		guest_car = *s_car;
	if(s_animal)
		subject = *s_animal;
}


// The Constructor intitalizes all data members to zero and calls the base class
// constructor.
// Inputs: Source: the object to be passed to the event constructor.
// Outputs: NA
sanctuary:: sanctuary(const event & source): event(source)
{
}


// The Input function prompts the user through inputing the aquatic event data.
// Inputs: id: The event booking id.
//         Source: Animal object to be copied into the event.
// Outputs: Returns 1 Upon success and zero upon failure. 
int sanctuary:: input(int id, const animal & source)
{
	event::input(id,3);

	subject = source;

	guest_car.input_car();

	if(subject == source) return 1; 
	return 0;
}


// The Compare Animal function compares the anima stored in subject to the source 
// animal passed in via argument. 
// Inputs: Source: THe animal to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int sanctuary:: compare_animal(const animal & source) const
{
	if(subject == source)
		return 1;
	if(subject > source)
		return 2;
	return 0;
}


// The Compare Location function compares the location stored in subject to the source 
// location passed in via argument. 
// Inputs: Source: The location to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int sanctuary:: compare_location(const string & source) const
{
	if(subject==source)
		return 1;
	
	if(subject>source) 
		return 2;

	return 0;
}


// The Compare Car function compares the car stored in curernt object to the source 
// location passed in via argument. 
// Inputs: Source: The location to be compared. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int sanctuary:: compare_car(const car & source) const
{
	if(guest_car==source)
		return 1;
	if(guest_car>source)
		return 2;
	return 0;
}


// The Display function outputs the event data as well as all base class data. 
// Inputs: Out: the output buffer to be used. 
// Outputs: NA
void sanctuary:: display(ostream & out) const
{
	out << "Sanctuary Viewing: " << endl;
	
	event::display(out);

	guest_car.display(out);
	cout << endl << endl;
	subject.display(out);
	cout << endl << endl;

}
