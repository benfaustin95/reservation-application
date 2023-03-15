#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include "p3_error.h"
using namespace std;

// file: p3_header.h

// Student: Ben Austin, November 30th, 2021, CS202 001, Program 3,
//          bena2@pdx.edu

// Files Included: datastructure.cpp, event.cpp, general.cpp, name.cpp, p3_main.cpp
// 				   p3_header.h, p3_error.h.

// Program Purpose: 

// File Purpose: To store all class, function definitions, and global constants. 

class animal_date;
class event;

class animal
{
	public:
		animal();
		int compare_animal(const animal &) const;
		int input_animal(int = 0);
		void display(ostream &) const;
		friend bool operator==(const animal & source, const animal & to_compare);
		friend bool operator==(const animal & source, const string & to_compare);
		friend 	bool operator==(const string & source, const animal & to_compare);
		friend 	bool operator!=(const animal & source, const animal & to_compare);
		friend 	bool operator!=(const animal & source, const string & to_compare);
		friend 	bool operator!=(const string & source, const animal & to_compare);
		friend 	bool operator>(const animal & source, const string & to_compare);
		friend 	bool operator>(const animal & source, const animal & to_compare);
		friend 	bool operator>(const string & source, const animal & compare);
		friend 	bool operator>=(const animal & source, const animal & to_compare);
		friend 	bool operator>=(const animal & source, const string & to_compare);
		friend 	bool operator>=(const string & source, const animal & compare);
		friend 	bool operator<(const animal & source, const animal & to_compare);
		friend 	bool operator<(const animal & source, const string & to_compare);
		friend 	bool operator<(const string & source, const animal & compare);
		friend 	bool operator<=(const animal & source, const animal & to_compare);
		friend 	bool operator<=(const animal & source, const string & to_compare);
		friend 	bool operator<=(const string & source, const animal & compare);
	private:
		string a_name;
		string species;
		int age;
		string type; //viewing type;
		string location;
};

class super_animal: public animal
{
	public:
		super_animal();
		int input_animal(int =0);
		int  display(ostream &);
		bool check_availability(const event &);
	private:
		int max_guest;
		vector<animal_date> res_list;
};

class car
{
	public:
		car();
		int compare_car(const car &) const;
		int input_car();
		void display(ostream &) const;

		friend bool operator==(const car & source, const car & to_compare);
		friend bool operator==(const car & source, const string & to_compare);
		friend 	bool operator==(const string & source, const car & to_compare);
		friend 	bool operator!=(const car & source, const car & to_compare);
		friend 	bool operator!=(const car & source, const string & to_compare);
		friend 	bool operator!=(const string & source, const car & to_compare);
		friend 	bool operator>(const car & source, const string & to_compare);
		friend 	bool operator>(const car & source, const car & to_compare);
		friend 	bool operator>(const string & source, const car & compare);
		friend 	bool operator>=(const car & source, const car & to_compare);
		friend 	bool operator>=(const car & source, const string & to_compare);
		friend 	bool operator>=(const string & source, const car & compare);
		friend 	bool operator<(const car & source, const car & to_compare);
		friend 	bool operator<(const car & source, const string & to_compare);
		friend 	bool operator<(const string & source, const car & compare);
		friend 	bool operator<=(const car & source, const car & to_compare);
		friend 	bool operator<=(const car & source, const string & to_compare);
		friend 	bool operator<=(const string & source, const car & compare);
	private:
		string plate;
		string type;
		string color;
}; 


class name 
{ 
	public: 
		name(char * = NULL);
		name(const name &);
		~name();
		int compare(const string &);
		int compare(const name &);	
		
		//operators
		name & operator=(const name &);
		name & operator=(const string &);
		name & operator=(const char []);

		friend ostream & operator<<(ostream &, const name &);
		friend istream & operator>>(istream &, name &);

		friend bool operator>(const string &, const name &);
		friend bool operator>(const name &, const string &);
		friend bool  operator>(const name &, const name &);
		friend bool  operator>(const name &, const char *);
		friend bool  operator>(const char *, const name &);
	
		friend bool  operator>=(const string &, const name &);
		friend bool  operator>=(const name &, const string &);
		friend bool  operator>=(const name &, const name &);
		friend bool  operator>=(const name &, const char *);
		friend bool  operator>=(const char *, const name &);
		
		friend bool  operator<(const string &, const name &);
		friend bool  operator<(const name &, const string &);
		friend bool  operator<(const name &, const name &);
		friend bool  operator<(const name &, const char *);
		friend bool  operator<(const char *, const name &);
	
		friend bool  operator<=(const string &, const name &);
		friend bool  operator<=(const name &, const string &);
		friend bool  operator<=(const name &, const name &);
		friend bool  operator<=(const name &, const char *);
		friend bool  operator<=(const char *, const name &);
		
		friend bool  operator==(const string &, const name &);
		friend bool  operator==(const name &, const string &);
		friend bool  operator==(const name &, const name &);
		friend bool  operator==(const name &, const char *);
		friend bool  operator==(const char *, const name &);
	
		friend bool  operator!=(const string &, const name &);
		friend bool  operator!=(const name &, const string &);
		friend bool  operator!=(const name &, const name &);
		friend bool  operator!=(const name &, const char *);
		friend bool  operator!=(const char *, const name &);

	protected:
		char * full_name;
};


class event_time: public name
{
	public:
		event_time(int = 0, int = 0, string * = NULL, char * = NULL);
		event_time(const name &);
		int input_event_time(int = 0);
		int change(int , int, const string &);
		int change(const event_time &);
		int compare(const event_time &) const;
			
		//operators
		
		friend ostream & operator<<(ostream &, const event_time &);	

		bool operator>(const event_time &) const;	
		bool operator>=(const event_time &) const;	
		bool operator<=(const event_time &) const;	
		bool operator<(const event_time &) const;	
		bool operator==(const event_time &) const;	
		bool operator!=(const event_time &) const;	
					
	protected:
		int hour;
		int minute;
		string period; //am or pm
};


class event_date: public event_time
{
	public:
		event_date(int =0, int=0, int =0, int = 0, int = 0, string * = NULL, char * = NULL);
		event_date(const event_time &);
		event_date(const name &);
		int input_date(int = 0);
                int input_date_only();
                int change_date(int, int, int);
                int change_date(const event_date &);
                int compare_date(const event_date &) const;
                int copy_date(event_date & ) const;
		
		friend ostream & operator<<(ostream &, const event_date&);	
	
		bool operator>(const event_date &) const;	
		bool operator>=(const event_date &) const;	
		bool operator<=(const event_date &) const;	
		bool operator<(const event_date &) const;	
		bool operator==(const event_date &) const;	
		bool operator!=(const event_date &) const;	

	protected:
		int month;
		int day;
		int year;

};


class animal_date: public event_date
{
	public:
		animal_date();
		animal_date(const event_date &, int);
		int check_guest(int, int);
		int display(ostream &);
		void add_guest(int);

	private:
		int guest_count;
};

class event: public event_date
{
	public:
		event(int =0, int =0, int=0, int=0,int=0,int=0,int=0
		      , string* =NULL, char* =NULL);
		event(const event_date &);
		int get_guest() const;
		virtual ~event();
		virtual int input(int,int=0);
		virtual int input(int, const animal &);


		//operators
		

		friend ostream & operator<<(ostream &, const event &);

		friend bool  operator>(const string &, const event &);
		friend bool  operator>(const event &, const string &);
		friend bool  operator>(const event  &, const event &);
		friend bool  operator>(const event  &, int);
		friend bool  operator>(int, const event &);
		friend bool  operator>(const animal &, const event &);
		friend bool  operator>(const event &, const animal &);
		friend bool  operator>(const car &, const event &);
		friend bool  operator>(const event &, const car &);
		friend bool  operator>(const event &, const event_date&);
		friend bool  operator>(const event_date &, const event &);

		friend bool  operator>=(const string &, const event &);
		friend bool  operator>=(const event &, const string &);
		friend bool  operator>=(const event  &, const event &);
		friend bool  operator>=(const event  &, int);
		friend bool  operator>=(int, const event &);
		friend bool  operator>=(const animal &, const event &);
		friend bool  operator>=(const event &, const animal &);
		friend bool  operator>=(const car &, const event &);
		friend bool  operator>=(const event &, const car &);
		friend bool  operator>=(const event &, const event_date&);
		friend bool  operator>=(const event_date &, const event &);

		friend bool  operator<=(const string &, const event &);
		friend bool  operator<=(const event &, const string &);
		friend bool  operator<=(const event  &, const event &);
		friend bool  operator<=(const event  &, int);
		friend bool  operator<=(int, const event &);
		friend bool  operator<=(const animal &, const event &);
		friend bool  operator<=(const event &, const animal &);
		friend bool  operator<=(const car &, const event &);
		friend bool  operator<=(const event &, const car &);
		friend bool  operator<=(const event &, const event_date&);
		friend bool  operator<=(const event_date &, const event &);
	
		friend bool  operator<(const string &, const event &);
		friend bool  operator<(const event &, const string &);
		friend bool  operator<(const event  &, const event &);
		friend bool  operator<(const event  &, int);
		friend bool  operator<(int, const event &);
		friend bool  operator<(const animal &, const event &);
		friend bool  operator<(const event &, const animal &);
		friend bool  operator<(const car &, const event &);
		friend bool  operator<(const event &, const car &);
		friend bool  operator<(const event &, const event_date&);
		friend bool  operator<(const event_date &, const event &);

		friend bool  operator==(const string &, const event &);
		friend bool  operator==(const event &, const string &);
		friend bool  operator==(const event  &, const event &);
		friend bool  operator==(const event  &, int);
		friend bool  operator==(int, const event &);
		friend bool  operator==(const animal &, const event &);
		friend bool  operator==(const event &, const animal &);
		friend bool  operator==(const car &, const event &);
		friend bool  operator==(const event &, const car &);
		friend bool  operator==(const event &, const event_date&);
		friend bool  operator==(const event_date &, const event &);

		friend bool  operator!=(const string &, const event &);
		friend bool  operator!=(const event &, const string &);
		friend bool  operator!=(const event  &, const event &);
		friend bool  operator!=(const event  &, int);
		friend bool  operator!=(int, const event &);
		friend bool  operator!=(const animal &, const event &);
		friend bool  operator!=(const event &, const animal &);
		friend bool  operator!=(const car &, const event &);
		friend bool  operator!=(const event &, const car &);
		friend bool  operator!=(const event &, const event_date&);
		friend bool  operator!=(const event_date &, const event &);

	protected:
		int booking_id;
		int guests;

		virtual void display(ostream &)const ;
		virtual int compare_id(int) const;
		virtual int compare_id(const event &) const;
		virtual int compare_location(const string &) const;
		virtual int compare_animal(const animal &) const;
		virtual int compare_car(const car &) const;
};


class aquatic: public event
{
	public:
		aquatic(animal * = NULL, int =0, int =0, int =0, int=0, int=0,int=0,int=0,int=0
                      , string* =NULL, char* =NULL);
		aquatic(const event & source);
		int input(int ,const animal &);
		int compare_animal(const animal &) const;
		int compare_location(const string &) const;
		void display(ostream &)const ;
	private:
		animal subject;
		int reserved_time;
	
};


class farm: public event
{
	public:
		farm(animal * = NULL, int =0, int =0, int =0, int=0, int=0,int=0,int=0,int=0
                      , string* =NULL, char* =NULL);
		farm(const event & source);
		int input(int, const animal &);
		int compare_animal(const animal &) const;
		int compare_location(const string &) const;
		void display(ostream &)const ;
	private:
		animal subject;
		int reserved_time;

};


class sanctuary: public event
{
	public:
		sanctuary(animal * = NULL, car * = NULL, int =0, int =0, int=0, int=0,int=0,int=0,int=0
                      , string* =NULL, char* =NULL);
		sanctuary(const event & source);
		int input(int ,const animal &);
		int compare_location(const string &) const;
		int compare_animal(const animal &) const;
		int compare_car(const car &) const;
		void display(ostream &)const ;
	private:
		animal subject;
		car guest_car;
};


class node
{
	public:
		node();
		node(const node &);
		node(const event *);
		~node();
		void copy_event(event *&) const;
		void change_event(const event *);
		void display() const;
		int compare_id(const event &) const;
		int compare_id(const node &) const;
		int compare_date(const event_date &) const;
		int compare_date(const node &) const;
		int compare_animal(const animal&) const;
		int compare_car(const car &) const;
		int compare_id(int) const;
		node*& get_right();
		node*& get_left();

		node& operator=(const node &);
		node& operator=(const event &);

	private:
		node * left;
		event * data;
		node * right;
};

class table
{
	public:
		table();
		table(const table &);
		~table(); 
		int copy_bst(const table &)throw(bad_list);
		int insert(const event &)throw(bad_list);
		int insert(const table &)throw(bad_list);
		int remove(int);
		int remove(const event &);
		int remove(const event_date &);
		int remove(const car &);
		int remove(const animal &);
		int retrieve(int, event *&) const;
		int retrieve(const event &, event *&) const;
		int retrieve(const event_date &, vector<event*> &) const;
		int retrieve(const car &, vector<event*> &) const;
		int retrieve(const animal&, vector<event*> &) const;
		int display_all()const;
		int display(const event &)const;
		int display(const event_date &)const;
		int display(const car &)const;
		int display(const animal &)const;
		int display(int) const;
		int remove_all();
		
		//Operators

		table & operator=(const table&);
		friend table operator+(const table&, const event &);
		friend table operator+(const event &, const table &);
		friend table operator+(const table&, const table&);
		table& operator+=(const event &);
		table& operator+=(const table &);
		bool operator==(const table&)const;
		bool operator!=(const table&)const;

	private:
		int copy_bst(node *&, node *);
		int destruct_bst(node *&);
		int insert(node *&, const event &);
		int insert(node *&, node *);
		int insert(node *&, const node &);
		int remove(node *&, int);
		int remove(node *&, const event &);
		int remove(node *&, const event_date &);
		int remove(node *&, const car &);
		int remove(node *&, const animal &);
		int remove(node*&);
		int ios(node*&, node &);
		int retrieve(node *, event *&, int) const;
		int retrieve(node *, vector<event*> &, const event_date&)const;
		int retrieve(node *, vector<event*> &, const car&)const;
		int retrieve(node *, vector<event*> &, const animal&)const;
		int retrieve(node *, event *&, const event &)const;
		int display(node *, const event &)const;
		int display(node *, const event_date &)const;	
		int display_all(node *)const;
		int display(node *, const car &)const;	
		int display(node *, const animal &)const;	
		int match(node *, node *)const;
		int display(node *, int) const;
		node * root;
};


class park: public table
{
	public:
		park();
		park(const table &);
		int fill_animals();
		int remove_animal();
		int display_animals();
		int create_res();
		int create_res(vector<super_animal> &, int=1);
		int remove_res_by_id();
		int remove_res_by_date();
		int remove_res_by_car();
		int retrieve_by_id();
		int retrieve_by_date();
		int display_by_id();
		int display_by_date();
		int display_by_car();
		int display_by_animal();
	private:
		vector<super_animal> aquatic_animals;
		vector<super_animal> farm_animals;
		vector<super_animal> sanctuary_animals;
		int next_id;
};



void destruct_char(char []);
int copy_char(char *&, char []);
int copy_char(char *&, string);
int compare_char(char *, char []);
int compare_char(char *, string);
int compare_char(string, string);
void a_to_upper(char []);
void a_to_upper(string &);
int len();
int day_check(int, int);
int correct_choice(vector<char>, char);
int fail(char);
bool animal_match(const string & temp, const animal &);






