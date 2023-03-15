 #include "p3_header.h"

// file name: name.cpp

// Student: Ben Austin, CS202 001, Novemebr 28th  2021, Program 3, bena2@pdx.edu

// The name.cpp file is used to implement general functions and functions within the 
// name, event_time, and event date scopes. 


/*********** Event Date ************/

// The Event Date constructor intializes all data members while also calling the base constructor
// and passing all relevant arguments. 
// Inputs: Source Month: value month should be intitalized to.
// 	   Source Day: value day should be intitalized to.
// 	   Source Year: value year should be intitalized to.
// 	   Source Hour: to be passed to event time constructor.
// 	   Source Minute: to be passed to event time constructor.
// 	   Source Period: to be passed to event time constructor.
// 	   Source Source Full Name: to be passed to event time constructor.
// Outputs: NA
event_date:: event_date( int source_month, int source_day, int source_year, int source_hour, int source_minute, 
		         string * source_period, char * source_full_name): event_time(source_hour, source_minute,
			 source_period, source_full_name), month(source_month), day(source_day), year(source_year)
{
}

// The Event Date constructor intializes all data members to zero, and calls the event time 
// constructor: 
// Inputs: Source: The object to be passes to the event time constructor.
// Outptus: NA
event_date:: event_date(const name & source): event_time(source), month(0), day(0), year(0)
{
}

// The Event Date constructor intializes all data members to zero, and calls the event time 
// constructor: 
// Inputs: Source: The object to be passes to the event time constructor.
// Outptus: NA
event_date:: event_date(const event_time & source): event_time(source), month(0), day(0), year(0)
{
}

// The Input Date function prompts the user through inputing the date information
// and calls the event time input function. 
// Inputs: Type: passed to event time input function. 
// Outputs: returns 1 if successfull and zero if not. 
int event_date:: input_date(int type)
{
	input_event_time(type);
	do
	{
		do
		{
			do
			{
				cout << "Please enter the date the you would like to reserve (MM/DD/YYYY): ";
				cin >> month;
			}
			while(fail('/')); 
			cin >> day; 
		}
		while(fail('/'));
		cin >> year;
	}
	while(fail('\n') || month<1 || month>12 || year<2021 ||year>2222 || day_check(month,day));
	if(year >1) return 1;
	return 0;
}


// The Input Date function prompts the user through inputing the date information only
// and calls the event time input function.
// Inputs: Type: passed to event time input function. 
// Outputs: returns 1 if successfull and zero if not. 
int event_date:: input_date_only()
{
	input_event_time(4);
	do
	{
		do
		{
			do
			{
				cout << "Please enter the desired date (MM/DD/YYYY): ";
				cin >> month;
			}
			while(fail('/')); 
			cin >> day; 
		}
		while(fail('/'));
		cin >> year;
	}
	while(fail('\n') || month<1 || month>12 || year<2021 ||year>2222 || day_check(month,day));
	if(year >1) return 1;
	return 0;
}

// The change date function changes the data memebers to reflect the values stored in the
// arguments passed in. 
// Inputs: Source Month: The new month value. 
// 	   Source Day: The new day value. 
// 	   Source Year: The new year value. 
// Outputs: returns 1 upon success and 0 upon failure. 
int event_date:: change_date(int source_month,int source_day, int source_year)
{
      if(source_month<1 || source_month>12 || source_year<2021 ||source_year>2222 || day_check(source_month,source_day))
                return 0;
	month = source_month;
	day = source_day;
	year = source_year;
	if(source_year==year) return 1;
	return 0;
}

// The change date function changes the data members to the date passed in via argument. 
// Inputs: Source: the date to be copied in. 
// Outputs:  returns 1 upon success and 0 upon failure. 
int event_date:: change_date(const event_date & source)
{
	month = source.month;
	day = source.day;
	year = source.year;
	return 1;
}


// The compare date function compares the current date to that of the object passed in. 
// Inputs: Source: the date to compared. 
// Outputs: 0 for less than, 1 for equal, 2 for greater than. 
int event_date:: compare_date(const event_date & source) const
{
	if(month==source.month && day==source.day && year==source.year)
	{
		if(static_cast<const event_time&>(*this)==static_cast<const event_time&>(source))
			return 1;
		else if(static_cast<const event_time&>(*this)>static_cast<const event_time&>(source)) 
			return 2;
		return 0;
	}
	if(year>source.year) return 2;
	if(year==source.year && month>source.month) return 2;
	if(year==source.year && month==source.month && day>source.day) return 2;
	return 0;
}

// THe copy date function copies the current date into the destination object. 
// Inputs: Dest: the destination
// Outputs:  returns 1 upon success and 0 upon failure. 
int event_date:: copy_date(event_date & dest) const
{
	dest.month=month;
	dest.day = day;
	dest.year=year;
	if(year==dest.year) return 1;
	return 0;
}

// The << operator outputs the date.
// Inputs: Out: The output stream to be used. 
// 	   Source: The date to be output.
// Outputs: Returns the modified output buffer. 
ostream & operator<<(ostream & out, const event_date & source)
{
	out << source.month << "/" << source.day << "/" << source.year;
	return out;
}

// The >operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns true if greater than and false if not. 
bool event_date:: operator>(const event_date & source) const
{
	if(compare_date(source)==2)
		return true;
	return false;
}


// The >=operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns true if greater than or equal and false if not. 
bool event_date:: operator>=(const event_date & source) const
{
	if(compare_date(source)>=1)
		return true;
	return false;
}


// The <=operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns true if less than or equal  and false if not. 
bool event_date:: operator<=(const event_date & source) const
{
	if(compare_date(source)<=1)
		return true;
	return false;
}


// The <operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns true if less than and false if not. 
bool event_date:: operator<(const event_date & source) const
{
	if(compare_date(source)<1)
		return true;
	return false;
}


// The ==operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns true if equal and false if not. 
bool event_date:: operator==(const event_date & source) const
{
	if(compare_date(source)==1 && (event_time::operator==(source)))
		return true;
	return false;
}


// The ==operator compares the current object to the source object passed in.
// Inputs: Source: the date to be compared.
// Outputs: Returns false if equal and true if not.
bool event_date:: operator!=(const event_date & source) const
{
	if(compare_date(source)!=1)
		return true;
	return false;
}

/*********** Time ************/


// The Event Time constructor intializes all data members while also calling the base constructor
// and passing all relevant arguments. 
//Inputs:  Source Hour: intializes the hour.
// 	   Source Minute: intializes the minute.
// 	   Source Period: intializes the period.
// 	   Source Source Full Name: to be passed to name constructor.
// Outputs: NA
event_time:: event_time( int source_hour, int source_minute, string * source_period, char * source_full_name):
	     name(source_full_name), hour(source_hour), minute(source_minute)
{
	if(source_period)
		period = *source_period;
}


// The Event Time  constructor intializes all data members to zero, and calls the name
// constructor: 
// Inputs: Source: The object to be passes to the name constructor.
// Outptus: NA
event_time:: event_time(const name & source): name(source), hour(0), minute(0)
{
}


// The Input Time function prompts the user through inputing the time info
// and calls the name input operator.
// Inputs: Type: guides the function through what input is needed.
// Outputs: returns 1 if successfull and zero if not. 
int event_time:: input_event_time(int type)
{
	if(type!=4)
	{
		do
		{
			cout << "Please enter the booker's full name: ";
			cin >> *this;
		}
		while(len());
	}

	if(type==3)
	{
		hour = 9;
		minute = 0;
		period = "AM";
	}
	else
	{	
		do
		{
			do
			{
				do
				{
					cout << "Please provide the time you would like to reserve(HH:00 AM/PM): ";
					cin >> hour;
				}
				while(fail(':'));
				cin >> minute;
			}
			while(fail(' '));
			getline(cin, period);
			a_to_upper(period);
		}
		while(hour < 1 || hour > 12 || minute != 0|| (period!="AM" && period !="PM"));
	}
	if(hour>0 && hour <=12)
		return 1;
	return 0;
}

// The Change Function  changes the date time stored in the current object to the time passed in 
// via arguments. 
// Inputs: New Hour: The new hour value. 
// 	   New Min: The new minute value. 
// 	   New Period: The new period value. 
// Outputs: Returns 1 upon success and zero upod failure. 
int event_time:: change(int new_hour, int new_min, const string & new_period)
{
	if(new_hour < 13 && new_hour>0 && minute!=0 && (period=="AM" || period =="PM"))
	{
		hour = new_hour;
		minute = new_min;
		period = new_period;
		return 1;
	}
	return 0;
}

// The Change function changes the time stored in teh current object to that of the object passed in. 
// Inputs: Source: the time object to be copied in. 
// Outputs: Returns 1 upon success and zero upod failure.
int event_time:: change(const event_time & source) 
{
	hour = source.hour;
	minute = source.minute;
	period = source.period;
	return 1;
}

// The Source comapre function compares the time stored in the current object to that
// of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: 0 lest than, 2 greather than, 1 equal to. 
int event_time:: compare(const event_time & source) const
{
	if(source.period != period && period == "AM")
		return 0;
	if(source.period != period && period == "PM")
		return 2;
	if(hour < source.hour)
		return 0;
	if(hour==source.hour && minute < source.minute)
		return 0;
	if(hour == source.hour && minute == source.minute)
		return 1;
	return 2;
}


// The << operator outputs the time. 
// Inputs: Out: The output buffer to be used.
//         Source: The time to be output. 
// Outputs: Returns the modified output buffer. 
ostream & operator<<(ostream & out, const event_time & source)
{
	out << source.hour << ":";
	if(source.minute<10)
		out << "0" << source.minute ;
	else 
		out << source.minute;
	out << " " << source.period;
	return out;
}

// The > operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is greater than  the argument,
//          false if not. 
bool event_time:: operator>(const event_time & source) const
{
	if(compare(source) == 2)
		return true;
	return false;
}


// The >= operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is greater than/equal to the argument,
//          false if not. 
bool event_time:: operator>=(const event_time & source) const
{
	if(compare(source) >=1)
		return true;
	return false;
}


// The <= operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is less than/equal to the argument,
//          false if not. 
bool event_time:: operator<=(const event_time & source) const
{
	if(compare(source) <=1)
		return true;
	return false;
}


// The < operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is less than to the argument,
//          false if not. 
bool event_time:: operator<(const event_time & source) const
{
	if(compare(source) == 0)
		return true;
	return false;
}


// The == operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is equal to the argument,
//          false if not. 
bool event_time:: operator==(const event_time & source) const
{
	if(compare(source)==1)
		return true;
	return false;
}


// The != operator compares the current time to that of the object passed in. 
// Inputs: Source: The time to be compared. 
// Outputs: Returns true if the current object is not equal to the argument,
//          false if not. 
bool event_time:: operator!=(const event_time & source) const
{
	if(compare(source) !=1)
		return true;
	return false;
}



/********** Name ************/


// The name function serves as the constructor for the name class
// Inputs: Source: points to the character array to be copied, is NULL by default
// Outputs: NA
name:: name(char * source): full_name(NULL)
{
	if(source)
	{
		copy_char(full_name, source);
	}
}


//  The name copy constructor serves to deep copy any name intialized as a copy of
//  another name.
//  Inputs: Source: the name to be copied
//  Outputs: NA
name:: name(const name & source): full_name(NULL)
{
	if(source.full_name)
	{	
		copy_char(full_name,source.full_name);
	}
}

// The name destructor serves to deallocate any dynamic memory 
// pointed to in the name class.
// Inputs: NA
// Outputs: NA
name:: ~name()
{
	destruct_char(full_name);
}

// The compare name function determines whether the name stored int the class
// object matches the name passed in via source. 
// Inputs: Source: the name to be compared.
// Outputs: returns a 1 if match and 0 if not a match
int name:: compare(const name & source)
{
	if(compare_char(full_name, source.full_name))
	{
		return 1;
	}
	else 
		return 0;
}



// The compare name function determines whether the name stored int the class
// object matches the name passed in via source. 
// Inputs: Source: the character array to be compared.
// Outputs: returns a 1 if match  and 0 if not a match
int name:: compare(const string & source)
{
	if(compare_char(full_name, source))
        {
                return 1;
        }
        else
                return 0;
}


// The = operator copies the source argument into the curent object. 
// Inputs: Source: The name object to be copied in. 
// Outputs: returns the current object by reference. 
name & name:: operator=(const name & source)
{
	if(this == &source)
		return *this;
	copy_char(full_name, source.full_name);
	return *this;
}


// The = operator copies the source argument into the curent object. 
// Inputs: Source: The string object to be copied in.
// Outputs: returns the current object by reference. 
name & name:: operator=(const string & source)
{
	if(*this == source)
		return *this;
	copy_char(full_name, source);
	return *this;
}


// The = operator copies the source argument into the curent object. 
// Inputs: Source: The character array object to be copied in.
// Outputs: returns the current object by reference. 
name & name:: operator=(const char source[])
{
	if(full_name == source)
		return *this;
	copy_char(full_name, source);
	return *this;
}

// The << operator outputs the name. 
// Inputs: Out: the output buffer to be used. 
// Outputs: Returns the modified output buffer.
ostream & operator<<(ostream & out, const name & source)
{
	out << source.full_name;
	return out;
}

// The >> operator extracts the name from the input buffer and copies into the
// name object. 
// Inputs: In: The input buffer to be used. 
//         Source: The name object the input will be stored in. 
// Outputs: Returns the modified input buffer. 
istream & operator>>(istream & in, name & source)
{
	char temp[10000];
	cin.get(temp, 1000);
	copy_char(source.full_name,temp);
	return in;
}

// The > operator compares the string and name object. 
// Inputs: To Compare: The string obejct to be compared. 
//         Source: The name object to be compared. 
// Outputs: Returns true if to compare is greater than source,
//          and false if not. 
bool operator>(const string & to_compare, const name & source)
{
	if(strcmp(to_compare.c_str(), source.full_name)>0)
		return true;
	return false;
}


// The > operator compares the string and name object. 
// Inputs: Source: The name obejct to be compared. 
//         To Compare : The string object to be compared. 
// Outputs: Returns true if source is greater than to compare
//          and false if not. 
bool operator>(const name & source, const string & to_compare)
{
	if(strcmp(source.full_name, to_compare.c_str()) > 0)
		return true;
	return false;
}


// The > operator comparesboth name object. 
// Inputs: Source: The name obejct to be compared. 
//         To Compare : The name object to be compared. 
// Outputs: Returns true if source is greater than to compare
//          and false if not. 
bool operator>(const name & source, const name & to_compare)
{
	if(strcmp(source.full_name, to_compare.full_name) > 0)
		return true;
	return false;
}


// The > operator compares the character array and name object. 
// Inputs: Source: The name obejct to be compared. 
//         To Compare : The character array to be compared. 
// Outputs: Returns true if source is greater than to compare
//          and false if not. 
bool operator>(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) > 0)
		return true;
	return false;
}

// The > operator compares the character array and name object. 
// Inputs: To Compare: The name obejct to be compared. 
//         Source: The character array to be compared. 
// Outputs: Returns true if source is greater than to compare
//          and false if not. 
bool operator>(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) > 0)
		return true;
	return false;
}

// The >= operator compares the string and name object. 
// Inputs: To Compare: The string obejct to be compared. 
//         Source: The name object to be compared. 
// Outputs: Returns true if to compare is greater than/equal to source,
//          and false if not. 
bool operator>=(const string & to_compare, const name & source)
{
	if(strcmp(to_compare.c_str(), source.full_name)>=0)
		return true;
	return false;
}

// The >= operator compares the string and name object. 
// Inputs: Source: The name obejct to be compared. 
//         To Compare : The string object to be compared. 
// Outputs: Returns true if source is greater than/ equal to  to compare
//          and false if not.
bool operator>=(const name & source, const string & to_compare)
{
	if(strcmp(source.full_name, to_compare.c_str())>=0)
		return true;
	return false;
}


// The >= operator compares both name objects.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The name object to be compared.
// Outputs: Returns true if source is greater than/equal to to compare
//          and false if not.
bool operator>=(const name & source, const name & to_compare)
{
	if(strcmp(source.full_name, to_compare.full_name)>=0)
		return true;
	return false;
}


// The >= operator compares the character array and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The character array to be compared.
// Outputs: Returns true if source is greater than/equal to to compare
//          and false if not.
bool operator>=(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) >= 0)
		return true;
	return false;
}


// The >= operator compares the character array and name object.
// Inputs: To Compare: The name obejct to be compared.
//         Source: The character array to be compared.
// Outputs: Returns true if source is greater than/equal to to compare
//          and false if not.
bool operator>=(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) >= 0)
		return true;
	return false;
}


// The < operator compares the string and name object. 
// Inputs: To Compare: The string obejct to be compared. 
//         Source: The name object to be compared. 
// Outputs: Returns true if to compare is less than source,
//          and false if not. 
bool operator<(const string & to_compare, const name & source)
{
	if(strcmp(to_compare.c_str(), source.full_name)<0)
		return true;
	return false;
}

// The < operator compares the string and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The string object to be compared.
// Outputs: Returns true if source is less than to compare
//          and false if not.
bool operator<(const name & source, const string & to_compare)
{
	if(strcmp(source.full_name, to_compare.c_str())<0)
		return true;
	return false;
}


// The < operator compares both name objects.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The name object to be compared.
// Outputs: Returns true if source is less than to compare
//          and false if not.
bool operator<(const name & source, const name & to_compare)
{
	if(strcmp(source.full_name, to_compare.full_name)<0)
		return true;
	return false;
}


// The < operator compares the character array and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The character array to be compared.
// Outputs: Returns true if source is less than to compare
//          and false if not.
bool operator<(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) < 0)
		return true;
	return false;
}


// The < operator compares the character array and name object.
// Inputs: To Compare: The name obejct to be compared.
//         Source: The character array to be compared.
// Outputs: Returns true if source is less than to compare
//          and false if not.
bool operator<(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) < 0)
		return true;
	return false;
}


// The <= operator compares the string and name object.
// Inputs: To Compare: The string obejct to be compared.
//         Source: The name object to be compared.
// Outputs: Returns true if to compare is less than/equal to source,
//          and false if not.
bool operator<=(const string & to_compare, const name & source)
{
	if(strcmp(to_compare.c_str(), source.full_name)<=0)
		return true;
	return false;
}


// The <= operator compares the string and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The string object to be compared.
// Outputs: Returns true if source is less than/equal to to compare
//          and false if not.
bool operator<=(const name & source, const string & to_compare)
{
	if(strcmp(source.full_name, to_compare.c_str())<=0)
		return true;
	return false;
}


// The <= operator compares both name objects.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The name object to be compared.
// Outputs: Returns true if source is less than/equal to to compare
//          and false if not
bool operator<=(const name & source, const name & to_compare)
{
	if(strcmp(source.full_name, to_compare.full_name)<=0)
		return true;
	return false;
}


// The <= operator compares the character array and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The character array to be compared.
// Outputs: Returns true if source is less than/equal to  to compare
//          and false if not.
bool operator<=(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) <= 0)
		return true;
	return false;
}


// The <= operator compares the character array and name object.
// Inputs: To Compare: The name obejct to be compared.
//         Source: The character array to be compared.
// Outputs: Returns true if source is less than/equal to to compare
//          and false if not.
bool operator<=(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) <= 0)
		return true;
	return false;
}


// The == operator compares the string and name object.
// Inputs: To Compare: The string obejct to be compared.
//         Source: The name object to be compared.
// Outputs: Returns true if to compare is equal to source,
//          and false if not.
bool  operator==(const string & to_compare, const name & source)
{
	return !strcmp(to_compare.c_str(), source.full_name);
}


// The == operator compares the string and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The string object to be compared.
// Outputs: Returns true if source is equal to to compare
//          and false if not.
bool  operator==(const name & source, const string & to_compare)
{
	return !strcmp(source.full_name, to_compare.c_str());
}

// The == operator compares both name objects.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The name object to be compared.
// Outputs: Returns true if source is equal to to compare
//          and false if not
bool  operator==(const name & source, const name & to_compare)
{
	return !strcmp(source.full_name, to_compare.full_name);
}


// The == operator compares the character array and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The character array to be compared.
// Outputs: Returns true if source is equal to  to compare
//          and false if not.
bool operator==(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) == 0)
		return true;
	return false;
}


// The == operator compares the character array and name object.
// Inputs: To Compare: The name obejct to be compared.
//         Source: The character array to be compared.
// Outputs: Returns true if source is equal to to compare
//          and false if not
bool operator==(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) == 0)
		return true;
	return false;
}


// The != operator compares the string and name object.
// Inputs: To Compare: The string obejct to be compared.
//         Source: The name object to be compared.
// Outputs: Returns true if to compare is not equal to source,
//          and false if not.
bool  operator!=(const string & to_compare, const name & source)
{
	return strcmp(to_compare.c_str(), source.full_name);
}


// The != operator compares the string and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The string object to be compared.
// Outputs: Returns true if source is not equal to to compare
//          and false if not.
bool  operator!=(const name & source, const string & to_compare)
{
	return strcmp(source.full_name, to_compare.c_str());
}


// The != operator compares both name objects.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The name object to be compared.
// Outputs: Returns true if source is not equal to to compare
//          and false if not
bool  operator!=(const name & source, const name & to_compare)
{
	return strcmp(source.full_name, to_compare.full_name);
}


// The != operator compares the character array and name object.
// Inputs: Source: The name obejct to be compared.
//         To Compare : The character array to be compared.
// Outputs: Returns true if source is not equal to  to compare
//          and false if not.
bool operator!=(const name & source, const char * to_compare)
{
	if(strcmp(source.full_name, to_compare) != 0)
		return true;
	return false;
}


// The != operator compares the character array and name object.
// Inputs: To Compare: The name obejct to be compared.
//         Source: The character array to be compared.
// Outputs: Returns true if source is not equal to to compare
//          and false if not
bool operator!=(const char * source, const name & to_compare)
{
	if(strcmp(source, to_compare.full_name) != 0)
		return true;
	return false;
}


/************ General ****************/


// The copy char function copies the source character array into the destination 
// array.
// Inputs: Dest: the character pointer to be copied into.
// 	   Source: The character array to be copied. 
// Outputs: returns 1 if the copy was a success and 0 if t was a failure.
int copy_char(char * &dest, char source[])
{
	destruct_char(dest);
	dest = new char[strlen(source)+1];
	strcpy(dest, source);
	return 1;
}

// The copy char function copies the source character array into the destination 
// array.
// Inputs: Dest: the character pointer to be copied into.
// 	   Source: The character array to be copied. 
// Outputs: returns 1 if the copy was a success and 0 if t was a failure.
int copy_char(char * &dest, string source)
{
	destruct_char(dest);
	dest = new char[source.size()+1];
	strcpy(dest, source.c_str());
	return 1;
}

// The compare char function compares to character arrats passed in.
// Inputs: Org: the character array being compared to
//         To_compare: the character array being comapred.
// Outputs: returns 1 if a match and 0 if not a match
int compare_char(char * org, char to_compare[])
{
	// Holds the copied and case standardized character array 
	// to be compared.
	char * temp = NULL;
	// Holds the copied and case standardized character array
	// to be comapred too.
	char * temp2 = NULL;

	if(!org) return 0;

	copy_char(temp, org);
	copy_char(temp2, to_compare);

	a_to_upper(temp);
	a_to_upper(temp2);

	if(!strcmp(temp,temp2))
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 1;
	}
	else
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 0;
	}
}

// The compare char function compares to character arrats passed in.
// Inputs: Org: the character array being compared to
//         To_compare: the character array being comapred.
// Outputs: returns 1 if a match and 0 if not a match
int compare_char(char * org, string to_compare)
{
	// Holds the copied and case standardized character array 
	// to be compared.
	char * temp = NULL;
	// Holds the copied and case standardized character array
	// to be comapred too.
	char * temp2 = NULL;

	if(!org) return 0;

	copy_char(temp, org);
	copy_char(temp2, to_compare.c_str());

	a_to_upper(temp);
	a_to_upper(temp2);

	if(!strcmp(temp,temp2))
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 1;
	}
	else
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 0;
	}
}


int compare_char(string org, string to_compare)
{
	// Holds the copied and case standardized character array 
	// to be compared.
	char * temp = NULL;
	// Holds the copied and case standardized character array
	// to be comapred too.
	char * temp2 = NULL;


	copy_char(temp, org.c_str());
	copy_char(temp2, to_compare.c_str());

	a_to_upper(temp);
	a_to_upper(temp2);

	if(!strcmp(temp,temp2))
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 1;
	}
	else
	{
		destruct_char(temp);
		destruct_char(temp2);
		return 0;
	}
}


// The a_to_upper function converts the character array passed in
// into all uppercase letters. 
// Inputs: Array: the character array to be converted
// Outputs: NA
void a_to_upper(char array[])
{
	int len = strlen(array);
	for(int i=0; i<len; ++i)
	{
		array[i] = toupper(array[i]);
	}
}


void a_to_upper(string & array)
{
	int len = array.length();
	for(int i=0; i<len; ++i)
	{
		array[i] = toupper(array[i]);
	}
}


// The destruct char function destroys the dynamically allocated
// character array passed in. 
// Inputs: Array: the array to be destoryed.
// Outputs: NA
void destruct_char(char array[])
{
	if(array)
		delete [] array;
	array = NULL;
}

// The len function checks to make sure the remaining character in the
// input buffer is a new line, and clears the buffer. 
// Inputs: NA
// Outputs: returns 0 if the remaining character was a newline and 0 if not.
int len()
{
	if(cin.peek() == '\n')
	{
		cin.clear();
		cin.ignore(1000,'\n');
		return 0;
	}
	else
	{
		cin.clear();
		cin.ignore(1000,'\n');
		return 1;
	}
}

// The Day check function compares the uses the month passed in to check that day is within 
// bounds. 
// Inputs: Month: The month to check day against. 
//         Day: The day to check. 
// Outputs: Returns 1 if within bounds and 0 if not. 
int day_check( int month, int day)
{
	int return_val =0;
	switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if(day>31 ||day <1) return_val=1;
			 else return_val=0;
			 break;
		case 2: if(day>29 ||day <1) return_val=1;
                         else return_val=0;
                         break;	 
		case 4:
		case 6:
		case 9:
		case 11: if(day>30 ||day <1) return_val=1;
                         else return_val=0;
                         break; 
		default: return_val = 1;
	}
	return return_val;
}


// The Correct Choice function checks whether the character passed in exists within the character vector. 
// Inputs: Comp: the vector to compare against. 
//         Method: the method to compare against. 
// Outputs: Returns 1 upon success and  zero upod failure. 
int correct_choice(vector<char> comp, char method)
{
	if(find(comp.begin(), comp.end(), method)!=comp.end())
		return 1;
	return 0;
}


// The fail function checks the validity of the most recetn input. 
// Inputs: C: the end character. 
// Outputs: Returns 1 upon success and  zero upod failure.
int fail(char c)
{
	if(cin.get() != c || cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		return 1;
	}
	else
	{
		cin.clear();
		return 0;
	}
}






