#include "p3_header.h"
// file name: p3_main.cpp

// Student: Ben Austin, CS202 001, Novemebr 28th  2021, Program 3, bena2@pdx.edu

// The event.cpp file is used to implement the main program test bed. 

int main()
{
	// The table that will store all activities/tasks input by user.
	park res_system;
	// Vector holding the possible user choices.
	vector <char> to_compare = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','Q'};
	// Holds the users selection.
	char method;
	do
	{
		do
		{
			cout << "Please choose one of the below actions: \n"
				<< "A: Insert Animal(s)\n"
				<< "B: Remove Animal \n"
				<< "C: Create Reservation \n"
				<< "D: Remove Reservation  \n"
				<< "E: Remove Reservation by Date & Time\n"
				<< "F: Remove Reservation by Car \n"
				<< "G: Retrieve Reservation(s) by Date & Time \n"
				<< "H: Retrieve Reservation by Booking ID \n"
				<< "I: Display All Reservations \n"
				<< "J: Display by Booking ID \n"
				<< "K: Display by Date & Time\n"
				<< "L: Display by Car \n"
				<< "M: Display by Animal \n"
				<< "N: Remove All \n"
				<< "O: Display All Animals\n"
				<< "Q: Quit Program \n"
				<< "Please enter choice: ";
			cin >> method;
			method = toupper(method);
		}
		while(len() && !correct_choice(to_compare, method));

		cout << endl << endl;

		switch(method){
			case('A'): res_system.fill_animals();
				   break;
			case('B'): res_system.remove_animal();
				   break;
			case('C'): res_system.create_res();
				   break;
			case('D'): res_system.remove_res_by_id();
				   break;
			case('E'): res_system.remove_res_by_date();
				   break;
			case('F'): res_system.remove_res_by_car();
				   break;
			case('G'): res_system.retrieve_by_date();
				   break;
			case('H'): res_system.retrieve_by_id();
				   break;
			case('I'): res_system.display_all();
				   break;
			case('J'): res_system.display_by_id();
				   break;
			case('K'): res_system.display_by_date();
				   break;
			case('L'): res_system.display_by_car();
				   break;
			case('M'): res_system.display_by_animal();
				   break;
			case('N'): res_system.remove_all();
				   break;
			case('O'): res_system.display_animals();
				   break;
			case('Q'): break;
			default: break;
		}
		cout << endl << endl;
	}
	while(method!='Q');
	return 1;
}

