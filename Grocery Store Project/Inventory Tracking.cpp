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

void viewInventory() {
	cout << setfill(' ');
	cout << endl;
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	cout << setw(86) << setfill('-') << "**** Inventory ****" << setw(70) << "" << setfill(' ') << endl << endl;
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	cout << setw(40) << left << "**** Product ID ****" << setw(51) << left << "**** Name ****" << setw(35) << left << "**** Quantity ****" << setw(46) << left << "**** Price ****" << endl << endl;
	for (int i = 0; i < productCount; i++) {
		cout << "   " << setw(41) << left << productIds[i] << setw(54) << left << productNames[i] << setw(33) << left << productQuantities[i] << setw(32) << left << productPrices[i] << endl;
	}
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	delay();
	clearScreen();
	cout << right;
}

void searchProduct() {
	int id = 0;
	int productIndex = -1;
	bool idNotSame = true;

	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Search Product " << setw(71) << "" << setfill(' ') << endl << endl;
	do {
		idNotSame = true;
		cout << "\nEnter Product ID (Enter 0 to Exit): ";
		cin >> id;
		cout << endl;

		if (cin.fail() || id < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		
		if (id == 0) {
			clearScreen();
			cout << "******** Product Search Cancelled ********\n\n";
			break;
		}

		for (int i = 0; i < productCount; i++) {
			if (id == productIds[i]) {
				productIndex = i;
				idNotSame = false;
				break;
			}
		}
		if (!idNotSame) {
			cout << setw(20) << left << "Product ID" << setw(20) << left << "Name" << setw(20) << left << "Quantity" << setw(20) << left << "Price" << endl;

			cout << setw(20) << left << productIds[productIndex] << setw(20) << left << productNames[productIndex] << setw(20) << left << productQuantities[productIndex] << setw(20) << left << productPrices[productIndex] << endl;

			cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
			break;
		}
		else if (idNotSame) {
			cout << "Error: Product Does Not Exist!\n";
			cin.ignore(1000, '\n');
			continue;
		}
	} while (true);
	delay();
	clearScreen();
	cout << right;
}

int inventoryTracking() {
	int choicei = 0;
	bool exiti = false;

	do {
		cout << setfill(' ');
		cout << endl;
		cout << setw(85) << setfill('-') << " Inventory Tracking " << setw(71) << "" << setfill(' ') << endl << endl;
		cout << setw(84) << " 1. View Inventory " << endl << endl;
		cout << setw(84) << " 2. Search Product " << endl << endl;
		cout << setw(87) << " 3. Exit to Main Menu " << endl << endl;
		cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choicei;

		switch (choicei) {
		case 1:
			clearScreen();
			viewInventory();
			exiti = true;
			break;
		case 2:
			clearScreen();
			searchProduct();
			exiti = true;
			break;
		case 3:
			clearScreen();
			exiti = true;
			break;
		default:
			clearScreen();
			cout << "\nWrong Input. Please select the correct option.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!exiti);
	
	return 0;
}