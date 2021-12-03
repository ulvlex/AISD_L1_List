#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int value; int index;
	list my_list;
	int choice;

	do {
		cout << "Choose\n1: adding to the end of the list\n2: adding to the top of the list\n3: deleting the last element\n4: removing the first element\n";
		cout << "5: adding an element by index (inserting before an element that was previously available by this index)\n6: getting an element by index\n";
		cout << "7: deleting an element by index\n8: getting the list size\n9: deleting all list items\n10: substitution of an element by index for the transmitted element\n";
		cout << "11: checking for the emptiness of the list\n12: list output\n13: inserting another list into the list starting from the index\n14: exit"<< endl;
		cin >> choice;

		if (choice < 1 || choice > 14) {
			throw "incorrect input";
			break;
		}

		switch (choice) {
		case 1:
			cout << "Enter the value of the element: ";
			cin >> value;
			my_list.push_back(value);
			cout << "Done" << endl;
			break;
		case 2:
			cout << "Enter the value of the element: ";
			cin >> value;
			my_list.push_front(value);
			cout << "Done" << endl;
			break;
		case 3:
			my_list.pop_back();
			cout << "Done" << endl;
			break;
		case 4:
			my_list.pop_front();
			cout << "Done" << endl;
			break;
		case 5:
			cout << "Enter the value of the element: ";
			cin >> value;
			cout << "Enter the index: ";
			cin >> index;
			my_list.insert(value, index);
			cout << "Done" << endl;
			break;
		case 6:
			cout << "Enter the index: ";
			cin >> index;
			cout << "The desired element:" << my_list.at(index) << endl;
			break;
		case 7:
			cout << "Enter the index: ";
			cin >> index;
			my_list.remove(index);
			cout << "Done" << endl;
			break;
		case 8:
			cout << "List size: " << my_list.get_size() << endl;
			break;
		case 9:
			my_list.clear();
			cout << "The list is cleared" << endl;
			break;
		case 10:
			cout << "Enter the value of the element: ";
			cin >> value;
			cout << "Enter the index: ";
			cin >> index;
			my_list.set(value, index);
			cout << "Done" << endl;
			break;
		case 11:
			if (my_list.isEmpty() == 0) cout << "The list is empty" << endl;
			else cout << "The list is not empty" << endl;
			break;
		case 12:
			cout << my_list;
			break;
		case 13:
			list new_list;
			int size;
			cout << "Enter the size of the inserted list: ";
			cin >> size;
			if (size < 1) throw "Incorrect size";
			else {
				for (int i = 0; i < size; i++)
				{
					cout << i + 1 << "element: ";
					cin >> value;
					new_list.push_back(value);
				}
				cout << "Enter the index: ";
				cin >> index;
				my_list.insertList(new_list, index);
				cout << my_list;
			}
		}
	} while (choice != 14);

	return 0;
}