#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

extern int productIds[100];
extern string productNames[100];
extern float productPrices[100];
extern int productQuantities[100];
extern int productCount;

extern int saleProductIds[500];
extern int saleQuantities[500];
extern float saleTotals[500];
extern int salesCount;

extern void delay();
extern void clearScreen();

void calculateBill() {
	int numItems = 0;
	bool exitinner = false;
	
	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Sales Management " << setw(71) << "" << setfill(' ') << endl << endl;

	do {
		cout << "Enter the Number of Different Products in the Bill (Enter 0 to Exit): ";
		cin >> numItems;
		
		if (cin.fail() || numItems < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (numItems == 0) {
			clearScreen();
			break;
		}
		else break;
	} while (true);

	int startIndex = salesCount;			//if no sale is recorded then salesCount will remain same as startIndex and is sy we can check whether koi sale hui ya ni hui
	float billTotal = 0;

	for (int i = 0; i < numItems; i++) {
		if (exitinner) break;
		int id = 0;
		int quantity = 0;
		int prodIndex = -1;
		bool found = false;
		bool exits = false;

		do {
			cout << "\nEnter the Product ID (Press 0 to Exit): ";
			cin >> id;

			if (cin.fail() || id < 0) {
				cout << "Invalid Input. Try again\n";
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			
			if (id == 0) {
				clearScreen();
				exitinner = true;
				break;
			}

			found = false;
			for (int j = 0; j < productCount && found == false; j++) {
				if (productIds[j] == id) {
					prodIndex = j;
					found = true;
				}
			}

			if (!found) {
				cout << "The Product does not exist\n";
				cin.ignore(1000, '\n');
				continue;
			}

			cout << "Product's Name: " << productNames[prodIndex] << endl;
			cout << "Product's Price: " << productPrices[prodIndex] << endl;
			cout << "Available Quantity: " << productQuantities[prodIndex] << endl;

			cout << "Enter the quantity of the Product: ";
			cin >> quantity;

			if (cin.fail() || quantity <= 0) {
				cout << "Invalid Input. Try again\n";
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			//we need to check if the quantity entered iS greater than the quantity the product already has
			if (quantity > productQuantities[prodIndex]) {
				cout << "\nNot enough stock is available\n";
				cin.ignore(1000, '\n');
				continue;
			}

			float linetotal = productPrices[prodIndex] * quantity;
			billTotal = linetotal + billTotal;				//linetotal is the bill of a single product (for loop ki aik iteration)

			saleProductIds[salesCount] = id;
			saleQuantities[salesCount] = quantity;
			saleTotals[salesCount] = linetotal;
			salesCount++;

			productQuantities[prodIndex] = productQuantities[prodIndex] - quantity;				// product ki quantity update kr rhy

			exits = true;
			cout << right;
		} while (!exits);
	}

	clearScreen();

	if (salesCount == startIndex) {
		cout << "\n\n******** Recording a Sale Cancelled ********\n\n";
		return;
	}

	cout << setw(15) << left << "ID" << setw(15) << left << "Quantity" << setw(15) << left << "Price" << setw(15) << left << "Total" << setw(25) << left << "Product Name" << endl;
	cout << setfill('-') << setw(156) << "-" << setfill(' ') << endl;

	cout << fixed << setprecision(2);

	for (int i = startIndex; i < salesCount; i++) {						// starting from startIndex ta k sirf new sales print ho
		int id = saleProductIds[i];
		int qty = saleQuantities[i];
		float linetotal = saleTotals[i];

		string name = "-";
		float price = 0;
		bool found = false;

		for (int j = 0; j < productCount && found == false; j++) {		// itna complex loop is liye lagaya cus cout k sath setw etc bhi hai so coudlnt have used a simple loop like we used in previous modules
			if (productIds[j] == id) {
				name = productNames[j];
				price = productPrices[j];
				found = true;
			}
		}

		cout << setw(15) << left << id << setw(15) << left << qty << setw(15) << left << price << setw(15) << left << linetotal << setw(25) << left << name << endl;
	}

	cout << setfill('-') << setw(156) << "-" << setfill(' ') << endl;
	cout << "Grand Total: " << billTotal << endl << endl;
	delay();
	clearScreen();
	cout << right;
}

int salesManagement() {
	int choices = 0;
	bool exits = false;

	do {
		cout << endl;
		cout << setw(85) << setfill('-') << " Sales Management " << setw(71) << "" << setfill(' ') << endl << endl;
		cout << setw(81) << " 1. Record Sale " << endl << endl;
		cout << setw(87) << " 2. Exit to Main Menu " << endl << endl;
		cout << setw(156) << setfill('-') << "-" << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choices;

		switch (choices) {
		case 1:
			clearScreen();
			calculateBill();
			exits = true;
			break;
		case 2:
			clearScreen();
			exits = true;
			break;
		default:
			clearScreen();
			cout << "\nWrong Input. Please select the correct option.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!exits);


	return 0;
}