#include "p3_header.h"

// file name: datastructure.cpp

// Student: Ben Austin, CS202 001, Novemebr 28th  2021, Program 3, bena2@pdx.edu

// The datastructure.cpp file is used to implement general functions within the 
// park, table, and node classes.


/********** Park *******************/


// The Constuctor intializes the park data members to their zero equivalent values. 
// Inputs: NA
// Outputs: NA
park:: park():next_id(1)
{
}

// The Copy Constructor copies teh source table into the park. 
// Inputs: Source: The table to be copied. 
// Outputs: NA
park:: park(const table & source): table(source), next_id(1)
{
}

// The Fill Animals function prompts the user through entiring animal information. 
// Inputs: NA
// Outputs: Returns the number of animals added. 
int park:: fill_animals()
{
	// The Users Selection.
	char answer = 'Y';
	// The number of animals added.
	int count = 0;


	answer = 'Y';
	cout << "Would you like to add any Aquatic animals? (Y/N): ";
	cin >> answer;
	answer = toupper(answer);
	len();
	cout << "Please enter all Aquatic Animals: " << endl;
	while(answer=='Y')
	{
		super_animal temp;
		temp.input_animal(1);
		aquatic_animals.push_back(temp);
		++count;
		cout << "Would you like to add another Aquatic animal? (Y/N): ";
		cin >> answer;
		answer = toupper(answer);
		len();
	}

	answer = 'Y';
	cout << "Would you like to add any Farm animals? (Y/N): ";
	cin >> answer;
	answer = toupper(answer);
	len();
	cout << "Please enter all Farm Animals: " << endl;
	while(answer=='Y')
	{
		super_animal temp;
		temp.input_animal(2);
		farm_animals.push_back(temp);
		++count;
		cout << "Would you like to add another Farm  animal? (Y/N): ";
		cin >> answer;
		answer = toupper(answer);
		len();
	}

	answer = 'Y';
	cout << "Would you like to add any Sanctuary animals? (Y/N): ";
	cin >> answer;
	answer = toupper(answer);
	len();
	cout << "Please enter all Sanctuary Animals: " << endl;
	while(answer=='Y')
	{
		super_animal temp;
		temp.input_animal(2);
		sanctuary_animals.push_back(temp);
		++count;
		cout << "Would you like to add another Sanctuary animal? (Y/N): ";
		cin >> answer;
		answer = toupper(answer);
		len();
	}
	return count;
}


// The Display Animals function outputs all park animals.
// Inputs: NA
// Outputs: Returns the number of animals displayed.
int park:: display_animals()
{	
	int count;
	auto it = aquatic_animals.begin();
	while(it!=aquatic_animals.end())
	{
		it->display(cout);
		++it;
		++count;
	}

	
	it = farm_animals.begin();
	while(it!=farm_animals.end())
	{
		it->display(cout);
		++it;
		++count;
	}

	it = sanctuary_animals.begin();
	while(it!=sanctuary_animals.end())
	{
		it->display(cout);
		++it;
		++count;
	}
	return count;	


}

// The Remove Animals function removes the desired animal from the park and all reservation
// lists. 
// Inputs: NA
// Outputs: Returns the number of reservations removed.
int park:: remove_animal()
{
	// Holds the information about the animal to be removed. 
	animal temp;
	// Holds the number of animals removed.
	int count =0;
	
	cout << "Please enter the information for the animal to remove: \n";
	temp.input_animal();
	
	auto it = aquatic_animals.begin();
	while(it!=aquatic_animals.end())
	{
		if(*it == temp)
		{
			it = aquatic_animals.erase(it);
			++count;
		}
		else 
			++it;
	}

	
	it = farm_animals.begin();
	while(it!=farm_animals.end())
	{
		if(*it == temp)
		{
			it = farm_animals.erase(it);
			++count;
		}
		else 
			++it;
	}

	it = sanctuary_animals.begin();
	while(it!=sanctuary_animals.end())
	{
		if(*it == temp)
		{
			it = sanctuary_animals.erase(it);
			++count;
		}
		else 
			++it;
	}
	
	return remove(temp)+count;


}


// The Create Res function prompts the user through entering reservation information.
// Inputs: NA
// Outputs: NA
int park:: create_res()
{	
	char type_S;
	int success =0;
	do 
	{ 
		cout << "Please select reservation viewing type: \n"
			<< "A: Aquatic \n"
			<< "B: Farm \n"
			<< "C: Sanctuary \n"
			<< "Please enter your choice: ";
		cin >> type_S;
		type_S=toupper(type_S);
	}while(len() || (type_S!='A' && type_S!='B' && type_S!='C'));

	switch(type_S)
	{
		case 'A': success += create_res(aquatic_animals, 1);
			  break;
		case 'B': success += create_res(farm_animals, 2);
			  break;
		case 'C': success += create_res(sanctuary_animals,3);
			  break;
		default: break;
	}
	if(success)
	{
		cout << "booking id " << next_id-1 << endl;
		return next_id -1;
	}
	return 0;
}


// The Create Res function prompts the user through entering the reservation information. 
// Inputs: List: The list of animals to be booked. 
//         Type: Determines what type of event is created. 
// Outputs: NA
int park:: create_res(vector<super_animal> & list, int type)
{
	// Holds the animal information to be stored in the reservation.
	animal temp;
	// Points to the new reservation. 
	event * res = NULL;
	// Holds the availability return value.
	bool fail = false;

	if(type==1)
		res = new aquatic;
	else if(type==2)
		res = new farm;
	else
		res = new sanctuary;

	char answer = 'N';
	if(list.end() != list.begin())
	{
		for(unsigned int i=0; i<list.size() && answer != 'Y' ; ++i)
		{
			cout << endl << endl;
			list[i].display(cout);
			cout << endl;
			cout << "Would you like to view the above animals? ";
			cin >> answer;
			len();
			answer = toupper(answer);
			if(answer=='Y')
			{
				temp = list[i];
				res->input(next_id++, temp);
				fail = list[i].check_availability(*res);
				if(!fail)
				{
					try{
						insert(*res);
					}
					catch(bad_list)
					{
						cout << "Booking failure try again" << endl;
						--next_id;
					}
				}
				else 
					--next_id;
			}
		}
		if(answer == 'N')
		{
			cout << "No Animal selected" << endl;
		}
		if(fail)
		{
			cout << "No availability during desired time slot" << endl;
		}
	}
	else
		cout << "No Aquatic animals to view " << endl;
	if(res)
	{
		delete res;
		res = NULL;
	}
	return 0;
}


// The Remove Res By ID function  allows the user to remove reservation by ID. 
// Inputs: NA
// Outputs: returns 1 upon success and 0 upon failure. 
int park:: remove_res_by_id()
{
	int to_remove =0;

	cout << "Please enter the booking ID of the reservation to be removed: ";
	cin >> to_remove;
	len();

	return remove(to_remove);
}


// The Remove Res By Date function  allows the user to remove reservations by date.
// Inputs: NA
// Outputs: returns 1 upon success and 0 upon failure. 
int park:: remove_res_by_date()
{
	event_date temp;
	
	cout << "Please input date and time of the reservation(s) to be removed: \n";
	temp.input_date_only();

	return remove(temp);
}


// The Remove Res By Car function  allows the user to remove reservations by car.
// Inputs: NA
// Outputs: returns 1 upon success and 0 upon failure. 
int park:: remove_res_by_car()
{
	car temp;

	cout << "Please enter the car information for the sanctuary reservation to remove below: \n";
	temp.input_car();

	return remove(temp);
}


// The Retrieve by Date function  allows the user to retrieve reservations by date.
// Inputs: NA
// Outputs: returns 1 upon success and 0 upon failure. 
int park:: retrieve_by_date()
{
	event_date temp;
	vector<event*> dest;
	
	cout << "Please input date and time of the reservation(s) to be retrieved: \n";
	temp.input_date_only();

	int count = retrieve(temp, dest);

	auto it = dest.begin();

	while(it!=dest.end())
	{
		if(*it)
		{
			cout << **it << endl;
		}
		++it;
	}


	it = dest.begin();
	int count2 = count;
	while(it!=dest.end())
	{
		if(*it)
		{
			delete *it;
			--count2;

		}
		++it;
	}
	return count;
}


// The Retrieve by ID function  allows the user to retrieve reservations by ID.
// Inputs: NA
// Outputs: returns 1 upon success and 0 upon failure. 
int park:: retrieve_by_id()
{
	int to_r =0;
	event * temp = NULL;

	cout << "Please enter the booking ID of the reservation to be removed: ";
	cin >> to_r;
	len();


	int sucess = retrieve(to_r, temp);

	if(temp)
	{
		cout << *temp << endl;
		delete temp;
		temp = NULL;
	}

	return sucess;
}


// The Display by ID function  allows the user to display reservations by ID.
// Inputs: NA
// Outputs: returns the number of events displayed.
int park:: display_by_id()
{
	int to_remove = 0;

	cout << "Please enter the booking ID of the reservation to be displayed: ";
	cin >> to_remove;
	len();

	return display(to_remove);
}


// The Display by date function  allows the user to display reservations by date.
// Inputs: NA
// Outputs: returns the number of events displayed.
int park:: display_by_date()
{
	event_date temp;
	
	cout << "Please input date and time of the reservation(s) to be displayed: \n";
	temp.input_date_only();

	return display(temp);
}


// The Display by car function  allows the user to display reservations by car.
// Inputs: NA
// Outputs: returns the number of events displayed.
int park:: display_by_car()
{
	car temp;

	cout << "Please enter the car information for the reservation to be displayed: \n";
	temp.input_car();

	return display(temp);
}



// The Display by animal function  allows the user to display reservations by animal.
// Inputs: NA
// Outputs: returns the number of events displayed.
int park:: display_by_animal()
{
	animal temp;
	
	cout << "Please input date animal for which you would like to display reservations: \n";
	temp.input_animal();

	return display(temp);
}



/*********** Table *******************/


// The Constructor intializes root to NULL. 
table:: table()
{
	root = NULL;
}


// The Copy Constructor copies the source table into the current table. 
// Inputs: Source: the table to be copied. 
// Outputs: NA 
table:: table(const table & source): root(NULL)
{
	copy_bst(source);
}


// The Destructor destroys the current table. 
// Inputs: NA
// Outputs: NA
table:: ~table()
{
	destruct_bst(root);
}


// The Copy BST function copies the source table into the current object. 
// Inputs: Source: the table to be copied. 
// Outputs: returns the number of nodes copied.
int table:: copy_bst(const table & source)throw(bad_list)
{
	bad_list bad;
	if(root) 
	{
		bad.source =0;
		bad.root =1;
		throw bad;
	}
	if(!source.root)
	{
		bad.source=1;
		bad.root=0;
		throw bad;
	}
	return copy_bst(root, source.root);
}


// The Copy BST function copies the source table into the current table object. 
// Inputs: Dest: The destination root. 
//         Source: The source root. 
// Outputs: Returns the number of nodes copied.
int table:: copy_bst(node *& dest, node * source)
{
	if(!source) return 0;
	dest = new node(*source);
	int count = copy_bst(dest->get_left(), source->get_left());
	count += copy_bst(dest->get_right(), source->get_right());
	return count+1;
}



// The Destruct BST function destroys the current object table. 
// Inputs: Root: The root of the tree to be destroyed. 
// Outputs: Returns the number of nodes destroyed. 
int table:: destruct_bst(node *& root)
{
	if(!root) return 0;
	int count = destruct_bst(root->get_left());
	count += destruct_bst(root->get_right());
	delete root;
	root = NULL;
	return count+1;
}


// The Insert function inserts the source event reference into the table. 
// Inputs: Source: The event to be copied in. 
// Outputs: Returns 1 upon success and zero upon failure. 
int table:: insert(const event & source)throw(bad_list)
{
	if(insert(root, source)<1)
	{
		bad_list bad;
		bad.root =1;
		bad.source=0;
		throw bad;
	}
	return 1;
}


// The Insert function inserts the source event into the table. 
// Inputs: Root: The root of the table to be inserted into. 
//         Source: The event to be inserted. 
// Outputs: Returns 1 upon success and zero upon failure. 
int table:: insert(node *& root, const event & source)
{
	if(!root)
	{
		root = new node(&source);
		return 1;
	}
	if(root->compare_date(source)<=1)
		return insert(root->get_right(),source);
	else
		return insert(root->get_left(), source);
}


// The Insert function inserts the source table into the current table. 
//         Inputs: Source: The table to be inserted.
// Outputs: Returns 1 upon success and zero upon failure. 
int table:: insert(const table & source)throw(bad_list)
{
	if(!source.root)
	{
		bad_list bad;
		bad.source =1;
		bad.root=9;
		throw bad;
	}
	return insert(root, source.root);
}


// The Insert function copies the source table into the current table object. 
// Inputs: Root: The table to be copied into. 
//         Source: The table to be copied.
// Outptus: Returns the number of nodes copied.
int table:: insert(node *& root, node * source)
{
	if(!source) return 0;
	int count = insert(root, source->get_left());
	count += insert(root, source->get_right());
	insert(root, *source);
	return count+1;
}


// The insert fucntion inserts the source node data into the current table. 
// Inputs: Root: Pointer to the root of the current table. 
//         Source: The node to be copied into the table. 
// Outptus: returns 1 upon success and 0 upon failure. 
int table:: insert(node *& root, const node & source)
{
	if(!root)
	{
		root = new node(source);
		return 1;
	}
	if(root->compare_date(source)<1)
		return insert(root->get_right(),source);
	else
		return insert(root->get_left(), source);
}


// The remove function removes the node with the matching booking ID from the table. 
// Inputs: Source ID: The booking ID to be removed. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(int source_id)
{
	return remove(root, source_id);
}


// The Remove function removes the node with the matching event from the table. 
// Inputs: Source ID: The event to be removed. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(const event & source)
{
	return remove(root, source);
}


// The Remove function removes all ndoes with matching event dates from the table. 
// Inputs: Source: The even date to be removed. 
// Outputs: The number of nodes removed. 
int table:: remove(const event_date & source)
{
	return remove(root, source);
}


// The Remove function removes all nodes with matching cars from the table. 
// Inputs: Source: The car to be removed. 
// Outputs: The number of nodes removed. 
int table:: remove(const car & source)
{
	return remove(root, source);
}


// The Remove function removes all nodes with matching animals from the table. 
// Inputs: Source: The animal to be removed. 
// Outputs: The number of nodes removed. 
int table:: remove(const animal & source)
{
	return remove(root, source);
}


// The Remove function removes the node with the matching event from the table. 
// Inputs: Source: The event to be removed. 
//         Dest: Points to the root of the table to be removed from. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(node *& dest, const event & source)
{
	if(!dest) return 0;
	if(dest->compare_id(source)==1)
		return remove(dest);
	int count = remove(dest->get_left(), source);
	if(!count)
		count+= remove(dest->get_right(), source);
	return count;
}


// The Remove function removes the node with the matching booking ID  from the table. 
// Inputs: Source: The booking ID to be removed. 
//         Dest: Points to the root of the table to be removed from. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(node *& dest, int source)
{
	if(!dest) return 0;
	if(dest->compare_id(source)==1)
		return remove(dest);
	int count = remove(dest->get_left(), source);
	if(!count)
		count += remove(dest->get_right(),source);
	return count;
}


// The Remove function removes the nodes with the matching event date from the table. 
// Inputs: Source: The event date to be removed. 
//         Dest: Points to the root of the table to be removed from. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(node *& dest, const event_date & source)
{
	if(!dest) return 0;
	if(dest->compare_date(source)==1)
	{
		while(dest && dest->compare_date(source)==1)
		{
			remove(dest);
		}
		if(!dest)
			return 0;
		else
			return remove(dest->get_right(), source)+1;
	}
	if(dest->compare_date(source)<1)
		return remove(dest->get_right(), source);
	return remove(dest->get_left(), source);
}


// The Remove function removes the nodes with the matching car from the table. 
// Inputs: Source: The car to be removed. 
//         Dest: Points to the root of the table to be removed from. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(node *& dest, const car & source)
{
	if(!dest) return 0;
	int count = 0;
	count += remove(dest->get_left(), source);
	count += remove(dest->get_right(), source);
	while(dest && dest->compare_car(source)==1)
	{
		remove(dest);
		++count;
	}
	return count;
}


// The Remove function removes the nodes with the matching animal from the table. 
// Inputs: Source: The animal to be removed. 
//         Dest: Points to the root of the table to be removed from. 
// Outputs: returns 1 upon success and 0 upon failure. 
int table:: remove(node *& dest, const animal & source)
{
	if(!dest) return 0;
	int count =0;
	count += remove(dest->get_left(), source);
	count += remove(dest->get_right(), source);
	while(dest && dest->compare_animal(source)==1)
	{
		remove(dest);
		++count;
	}
	return count;
}


// The Remove function removes the node from the the table.
// Inputs: Dest: The node to be removed. 
// Outputs: Returns 1 upon success and 0 upon failure.
int table:: remove(node *& dest)
{
	if(!dest->get_left() && !dest->get_right())
	{
		delete dest;
		dest = NULL;
		return 1;
	}
	if(!dest->get_left())
	{
		node * temp = dest;
		dest = temp->get_right();
		delete temp;
		return 1;
	}
	if(!dest->get_right())
	{
		node * temp = dest;
		dest = temp->get_left();
		delete temp;
		return 1;
	}
	node successor;
	ios(dest->get_right(), successor);
	*dest = successor;
	return 1;
}


// The IOS function finds the inorder successor and removes it from the table. 
// Inputs: Temp: The pointer to the possible IOS. 
//         Successor: pointer to the node to be copied. 
// Outputs: Returns 1 upon success and zero upon failure. 
int table:: ios(node *& temp, node & successor)
{
	if(!temp) return 0;
	if(!temp->get_left() && temp->get_right())
	{
		successor = *temp;
		node * temp2 = temp;
		temp = temp->get_right();
		delete temp2;
		return 1;
	}
	if(!temp->get_left())
	{
		successor = *temp;
		delete temp;
		temp = NULL;
		return 1;
	}
	return ios(temp->get_left(), successor);
}

// The remove all function destroyes the table.
int table:: remove_all()
{
	return 	destruct_bst(root);
}

// The Retrieve function retrieves the matching event. 
int table:: retrieve(const event & source, event *& dest) const
{
	return retrieve(root, dest, source);
}


// The retrieve function retrieves all matching event dates.
int table:: retrieve(const event_date & source, vector<event*> & dest) const
{
	return retrieve(root, dest, source);
}


// The retireve function retrieves all matching cars.
int table:: retrieve(const car & source, vector<event*> & dest) const
{
	return retrieve(root, dest, source);
}


// The retrieve function retireves all 
int table::  retrieve(const animal & source, vector<event*> & dest) const 
{
	return retrieve(root, dest, source);
}

int table:: retrieve(int source, event *& dest) const
{
	return retrieve(root, dest, source);
}
	
int table:: retrieve(node * root, vector<event*> & dest, const event_date  & compare) const
{
	if(!root) return 0;
	if(root->compare_date(compare)<1)
		return retrieve(root->get_right(), dest, compare);
	if(root->compare_date(compare)>1)
		return retrieve(root->get_left(),dest, compare);
	event * temp = NULL;
	root->copy_event(temp);
	dest.push_back(temp);
	return retrieve(root->get_right(), dest, compare)+1;
}


int table:: retrieve(node * root, vector<event*> & dest, const car & compare) const
{
	if(!root) return 0;
	int count = 0;
	if(root->compare_car(compare)==1)
	{
		event * temp = NULL;
		root->copy_event(temp);
		dest.push_back(temp);
		++count;
	}
	count += retrieve(root->get_left(), dest, compare);
	count += retrieve(root->get_right(), dest, compare);
	return count;
}

int table:: retrieve(node * root, vector<event*> & dest, const animal  & compare) const
{
	if(!root) return 0;
	int count = 0;
	if(root->compare_animal(compare)==1)
	{
		event * temp = NULL;
		root->copy_event(temp);
		dest.push_back(temp);
		++count;
	}
	count += retrieve(root->get_left(), dest, compare);
	count += retrieve(root->get_right(), dest, compare);
	return count;
}

int table:: retrieve(node * root, event *& dest, const event & compare)const
{
	if(!root) return 0;
	if(root->compare_id(compare)==1)
	{
		root->copy_event(dest);
		return 1;
	}
	int count = retrieve(root->get_left(), dest,compare);
	if(!count)
		count += retrieve(root->get_right(), dest , compare);
	return count;
}

int table:: retrieve(node * root, event *& dest, int source) const
{
	if(!root) return 0;
	if(root->compare_id(source)==1)
	{
		root->copy_event(dest);
		return 1;
	}
	int count = retrieve(root->get_left(), dest, source);
	if(!count)
		count+= retrieve(root->get_right(), dest, source);
	return count;
}

int table:: display_all() const
{
	return display_all(root);
}

int table:: display_all(node * root)const
{
	if(!root) return 0;
	int count = display_all(root->get_left());
	root->display();
	count+= display_all(root->get_right());
	return count;
}

int table:: display(int source) const
{
	return display(root, source);
}

int table:: display(node * root, int source) const
{
	if(!root) return 0;
	if(root->compare_id(source)==1)
	{
		cout << endl;
		root->display();
		return 1;
	}
	int count = display(root->get_left(), source);
	if(!count)
		count += display(root->get_right(), source);
	return count;
}
	
int table:: display(const event & source)const
{
	return display(root, source);
}

int table:: display(node * root, const event & source)const
{
	if(!root) return 0;
	if(root->compare_id(source)==1)
	{
		cout << endl;
		root->display();
		return 1;
	}
	int count = display(root->get_left(), source);
	if(!count)
		count += display(root->get_right(), source);
	return count;
}

int table:: display(const event_date & source)const
{
	return display(root, source);
}

int table:: display(node * root, const event_date & source)const
{
	if(!root) return 0;
	if(root->compare_date(source)<1)
		return display(root->get_right(), source);
	if(root->compare_date(source)>1)
		return display(root->get_left(), source);
	cout << endl;
	root->display();
	return display(root->get_right(),source)+1;
}

int table:: display(const car & source)const
{
	return display(root, source);
}

int table:: display(node * root, const car & source)const
{
	if(!root) return 0;
	int count = 0;
	if(root->compare_car(source)==1)
	{
		cout << endl;
		root->display();
		++count;
	}
	count += display(root->get_left(), source);
	count += display(root->get_right(), source);
	return count;
}

int table:: display(const animal& source)const
{
	return display(root, source);
}

int table:: display(node * root, const animal & source)const
{
	if(!root) return 0;
	int count = 0;
	if(root->compare_animal(source)==1)
	{
		root->display();
		++count;
	}
	count += display(root->get_left(), source);
	count += display(root->get_right(), source);
	return count;
}

table& table:: operator=(const table & source)
{
	if(this == &source) return *this;
	destruct_bst(root);
	copy_bst(source);
	return *this;
}

table operator+(const table& source, const event& to_add)
{
	table temp(source);

	temp.insert(to_add);

	return temp;
}

table operator+(const event& to_add, const table &source)
{
	table temp(source);

	temp.insert(to_add);

	return temp;
}


table operator+(const table& to_add, const table& source)
{
	table temp(source);

	temp.insert(to_add);

	return temp;
}

table& table:: operator+=(const event & source)
{
	insert(root, source);
	return *this;
}

table& table:: operator+=(const table& source)
{
	insert(root, source.root);
	return *this;
}

bool table:: operator==(const table & source)const
{
	return !match(root, source.root);
}

bool table:: operator!=(const table & source)const
{
	return match(root, source.root);
}

int table:: match(node * root, node * source) const
{
	if(!root && source) return 1;
	if(!root && !source) return 0;
	int count = match(root->get_left(), source->get_left());
	count+= match(root->get_right(), source->get_right());
	if(root->compare_id(*source)!=1)
		return count+1;
	return count;
}
	

/********** Node **************/


// The Constructor intitializes the date members to their its zero equivalent value. 
// Inputs: NA
// Outputs: NAj
node:: node():left(NULL), data(NULL), right(NULL)
{
}

// The Node Copy Constructor copies the event data into the node's data pointer and sets
// left/right pointers to NULL.
// Inputs: Source: The node whose data should be copied in. 
// Outputs: NA
node:: node(const node & source): left(NULL), data(NULL), right(NULL)
{
	if(source.data)
	{
		const aquatic* sa = dynamic_cast<const aquatic*>(source.data);
		const farm* sf = dynamic_cast<const farm*>(source.data);
		const sanctuary* ss = dynamic_cast<const sanctuary*>(source.data);

		if(sa)
			data = new aquatic(*sa);
		else if(sf)
			data = new farm(*sf);
		else if(ss)
			data = new sanctuary(*ss);
	}
}


// The Node Copy constructor copies the event data of the pointer passed in
// into the current node. 
// Inputs: Soure: the event data to be copied in. 
// Outputs: NA
node:: node(const event * source): left(NULL), data(NULL), right(NULL)
{
	if(source)
	{
		const aquatic* sa = dynamic_cast<const aquatic*>(source);
		const farm* sf = dynamic_cast<const farm*>(source);
		const sanctuary* ss = dynamic_cast<const sanctuary*>(source);

		if(sa)
			data = new aquatic(*sa);
		else if(sf)
			data = new farm(*sf);
		else if(ss)
			data = new sanctuary(*ss);
	}
}

// The Desctructor deallocates the event data pointed to by the data pointer. 
// Inputs: NA
// Outputs: NA
node:: ~node()
{
	if(data)
		delete data;
	data = NULL;
	left = right = NULL;
}


// The Copy Event function copies the data stored in event into the pointer pointed to by dest. 
// Inputs: Dest: The event pointer.
// Outputs: NA
void node:: copy_event(event *& dest) const
{
	if(dest) 
	{
		delete dest;
		dest = NULL;
	}
	event * source = data;
	if(source)
	{
		const aquatic* sa = dynamic_cast<const aquatic*>(source);
		const farm* sf = dynamic_cast<const farm*>(source);
		const sanctuary* ss = dynamic_cast<const sanctuary*>(source);

		if(sa)
			dest = new aquatic(*sa);
		else if(sf)
			dest  = new farm(*sf);
		else if(ss)
			dest  = new sanctuary(*ss);
		else 
			dest = new event(*source);
	}
	return;
}


// The Change event fuction changes the event data to the argument stored in. 
// Inputs: Source: The data to be copied in. 
// Outputs: NA
void node:: change_event(const event * source)
{
	if(data)
	{
		delete data;
		data = NULL;
	}
	if(source)
	{
		const aquatic* sa = dynamic_cast<const aquatic*>(source);
		const farm* sf = dynamic_cast<const farm*>(source);
		const sanctuary* ss = dynamic_cast<const sanctuary*>(source);

		if(sa)
			data = new aquatic(*sa);
		else if(sf)
			data  = new farm(*sf);
		else if(ss)
			data  = new sanctuary(*ss);
	}
}



// The Display function outputs the data stored in the node. 
// Inputs: NA
// Outputs: NA
void node:: display() const
{
	if(data)
	cout << *data;
}

// The = operator copies the data stored in the source node into the 
// current object. 
// Inputs: Source: The node data to be copied in. 
// Outputs: Returns the current object by reference. 
node& node:: operator=(const node & source)
{
	if(this == &source)
		return *this;
	source.copy_event(data);
	return *this;
}


// The = operator copies the data stored in the source event into the 
// current object. 
// Inputs: Source: The event data to be copied in. 
// Outputs: Returns the current object by reference. 
node& node:: operator=(const event & source)
{
	if(this->compare_id(source)==1)
		return *this;
	change_event(&source);
	return *this;
}


// The Get Left function returns the left pointer by reference. 
// Inputs: NA
// Outputs: Left node pointer. 
node*& node:: get_left()
{
	return left;
}


// The Get Right function returns the left pointer by reference. 
// Inputs: NA
// Outputs: Right node pointer. 
node*& node:: get_right()
{
	return right;
}


// The Compare ID Function compares the event passed in to the event
// event stored in the current node. 
// Inputs: Source: The event to compare. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_id(const event & source) const
{
	if(!data || *data < source)
		return 0;
	if(*data == source)
		return 1;
	else 
		return 2;
}


// The Compare ID Function compares the event passed in to the event
// event stored in the current node. 
// Inputs: Source: The event to compare. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_id(const node & source) const
{
	if(!data || !source.data || *data < *source.data)
		return 0;
	if(*data == *source.data)
		return 1;
	else 
		return 2;
}

// The Compare Date Function compares the date of the event date passed in to the date
// of the data stored in the current node. 
// Inputs: Source: The event date to compare. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_date(const event_date & source) const
{
	if(!data || *data < source)
		return 0;
	if(*data == source)
		return 1;
	else return 2;
}


// The Compare Date Function compares the date stored in the node passed in to the date
// of the data stored in the current node. 
// Inputs: Source: The node to compare. 
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_date(const node & source) const
{
	if(!data ||!source.data|| static_cast<event_date&>(*data) < *source.data)
		return 0;
	else if(static_cast<event_date&>(*data) == *source.data)
		return 1;
	return 2;
}


// The Compare Animal Function compares the animal passed in to the animal stored in
// the node. 
// Inputs: Source: The animal to compare.
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_animal(const animal & source) const
{
	if(!data || *data < source)
		return 0;
	if(*data == source)
		return 1;
	else 
		return 2;
}


// The Compare car Function compares the animal passed in to the car stored in
// the node. 
// Inputs: Source: The car to compare.
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_car(const car & source) const
{
	if(!data || *data< source)
		return 0;
	if(*data == source)
		return 1;
	return 2;

}


// The Compare booking id  Function compares booking id the passed in to the id  stored in
// the node. 
// Inputs: Source: The id to compare.
// Outputs: 0 less than, 1 equal to , 2 greater than.
int node:: compare_id(int id) const
{
	if(!data || *data < id)
		return 0;
	if(*data == id)
		return 1;
	return 2;
}



	


