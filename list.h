#pragma once
#include <iostream>

using namespace std;
int cnt = 0;

class list 
{
private:
	class node //doubly linked list
	{
	public:
		int info; //information part
		node* next; //pointer to the next element
		node* prev; //pointer to the previous element

	};

	node* head; //pointer to the first element
	node* tail; //pointer to the last element

public:
	list() { //constructor
		head = NULL;
		tail = NULL;
		cnt = 0;
	}

	~list() { //destructor
		clear();
	}

	//initializing methods
	void push_back(int info); //adding to the end of the list
	void push_front(int info); //adding to the top of the list
	void pop_back(); //deleting the last element
	void pop_front(); //deleting the first element
	void insert(int info, int index); //adding an element by index (inserting before an element that was previously available by this index)
	int at(int index); //getting an item by index
	void remove(int index); //deleting an item by index
	size_t get_size(); //getting the list size
	void clear(); //deleting all list items
	void set(int info, int index); //replacing an element by index with the transmitted element
	bool isEmpty(); //checking for list emptiness
	friend ostream& operator << (ostream& stream, const list&);
	void insertList(const list& list2, int index); //inserting another list into the list starting from the index
};

void list::push_back(int info) { //adding to the end of the list
	node* cur = new node;
	cur->info = info;
	if (head == NULL) {
		cur->prev = NULL;
		cur->next = NULL;
		head = tail = cur;
		cnt++;
	}
	else {
		tail->next = cur;
		cur->prev = tail;
		cur->next = NULL;
		tail = cur;
		cnt++;
	}
}

void list::push_front(int info) { //adding to the top of the list
	node* cur = new node;
	cur->info = info;
	cur->next = NULL;
	cur->prev = NULL;
	if (head == NULL) { //the list is empty
		head = tail = cur;
		cnt++;
	}
	else {
		cur->next = head;
		head->prev = cur;
		head = cur; 
		cnt++;
	}
}

void list::pop_back() { //deleting the last element
	if (isEmpty() == 0)
		throw "The list is already empty";
	else {
		node* del = new node;
		if (head != NULL) { //the list is not empty
			if (head == tail) { //there is one item in the list
				head = tail = NULL;
				cnt--;
			}
			else {
				del = tail;
				tail = tail->prev;
				delete del;
				tail->next = NULL;
				cnt--;
			}
		}
	}
}

void list::pop_front() { //deleting the first element
	if (isEmpty() == 0)
		throw "The list is already empty";
	else {
		node* del = new node;
		if (head != NULL) { //the list is not empty
			if (head == tail) { //there is one item in the list
				head = tail = NULL;
				cnt--;
			}
			else {
				del = head;
				head = head->next;
				delete del;
				head->prev = NULL;
				cnt--;
			}
		}
	}
}

void list::insert(int info, int index) { //adding an element by index (inserting before an element that was previously available by this index)
	if (index < 1 || index > cnt) {
		throw out_of_range("Incorrect index");
	}
	else {
		if (index == 1) {
			push_front(info);
		}
		else {
			if (index == cnt + 1) {
				push_back(info);
			}
			else {
				int i = 1;
				node* buf = head;
				while (i > index) {
					buf = buf->next;
					i++;
				}
				node* cur = new node;
				cur->info = info;
				cur->prev = buf->prev;
				cur->next = buf;
				buf->prev = cur;
				cnt++;
			}
		}
	}
}

int list::at(int index) { //getting an item by index
	if (index < 1 || index > cnt + 1) {
		throw out_of_range("Incorrect index");
	}
	else {
		int i = 1;
		node* buf = head;
		while (i < index) {
			buf = buf->next;
			i++;
		}
		return buf->info;
	}
}

void list::remove(int index) { //deleting an item by index
	if (index < 1 || index > cnt + 1) {
		throw out_of_range("Incorrect index");
	}
	else {
		if (index == 1) {
			pop_front();
		}
		else {
			if (index == cnt + 1) {
				pop_back();
			}
			else {
				int i = 1;
				node* del = head;
				while (i < index) {
					del = del->next;
					i++;
				}
				(del->next)->prev = del->prev;
				(del->prev)->next = del->next;
				delete del;
				cnt--;
			}
		}
	}
}

size_t list::get_size() { //getting the list size
	return cnt;
}

void list::clear() { //deleting all list items
	while (cnt) {
		pop_front();
	}
}

void list::set(int info, int index) { //replacing an element by index with the transmitted element
	if (index < 1 || index > cnt + 1) {
		throw out_of_range("Incorrect index");
	}
	else {
		if (index == 1) head->info = info;
		else {
			if (index == cnt) tail->info = info;
			else {
				int i = 1;
				node* buf = head;
				while (i < index) {
					buf = buf->next;
					i++;
				}
				buf->info = info;
			}
		}
	}
}

bool list::isEmpty() { //checking for list emptiness
	if (cnt == 0) return 0;
	else return 1;
}

//friend
// 
// 
//
ostream& operator << (ostream& stream, const list& list) // for output
{
	list::node* print = list.head;
	while (print != NULL) {
		stream<< print->info << " ";
		print = print->next;
	}
	cout << endl;
	return stream;
}
//
//
//

void list::insertList(const list& list2, int index) { //inserting another list into the list starting from the index
	if (index < 1 || index > cnt + 1) {
		throw out_of_range("Incorrect index");
	}
	else {
		int i = 1;
		node* buf = head;
		while (i < index) {
			buf = buf->next;
			i++;
		}
		node* buf2 = list2.head;
		while (buf2 != NULL) {
			node* cur = new node;
			cur->info = buf2->info;
			cur->prev = buf->prev;
			cur->next = buf;
			(buf->prev)->next = cur;
			buf->prev = cur;
			buf2 = buf2->next;
			cnt++;
		}
	}
}

