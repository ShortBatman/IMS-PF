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

extern string noSpaces(string name);
extern void delay();
extern void clearScreen();

void addProduct() {
	int id = 0;
	string name = " ";
	string newName = " ", existingName = " ";
	float price = 0;
	int quantity = 0, nameLength = 0;
	bool productSame = false;
	
	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Add Product " << setw(71) << "" << setfill(' ') << endl << endl;
	do {
		productSame = false;
		cout << "\nEnter Product ID (Enter 0 to Exit): ";
		cin >> id;

		if (cin.fail() || id < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (id == 0) {
			clearScreen();
			cout << "\n\n******** Adding Product Cancelled ********\n\n";
			break;
		}
		
		for (int i = 0; i < productCount; i++) {
			if (id == productIds[i]) {
				productSame = true;
				break;
			}
		}
		if (productSame) {
			cout << "Error: Product Already Exists!\n";
			cin.ignore(1000, '\n');
			continue;
		}

		cout << "Enter Product's Name: ";
		cin.ignore();
		getline(cin, name);

		newName = noSpaces(name);

		for (int i = 0; i < productCount; i++) {
			existingName = noSpaces(productNames[i]);
			if (newName == existingName) {
				productSame = true;
				break;
			}
		}
		if (productSame) {
			cout << "Error: Product Already Exists!\n";
			cin.ignore(1000, '\n');
			continue;
		}

		cout << "Enter Product's Price: ";
		cin >> price;
		if (cin.fail() || price < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		cout << "Enter Product's Quantity: ";
		cin >> quantity;
		if (cin.fail() || quantity < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		else {
			cout << "\n\n******** Product Added Successfully ********\n\n\n";
			delay();
			clearScreen();
			cout << right;
			break;
		}
	} while (true);
	
	if (id != 0) {
		productIds[productCount] = id;
		productNames[productCount] = name;
		productPrices[productCount] = price;
		productQuantities[productCount] = quantity;
		productCount++;
	}
}

void updateProduct() {
	int id = 0;
	string name = " ";
	float price = 0;
	int quantity = 0;
	int productIndex = -1;
	bool idNotSame = true;

	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Update Product " << setw(71) << "" << setfill(' ') << endl << endl;
	do {
		idNotSame = true;
		cout << "\nEnter Product ID (Enter 0 to Exit): ";
		cin >> id;
		
		if (cin.fail() || id < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (id == 0) {
			clearScreen();
			cout << "\n\n******** Updating Product Cancelled ********\n\n";
			break;
		}

		for (int i = 0; i < productCount; i++) {
			if (id == productIds[i]) {
				productIndex = i;
				idNotSame = false;
				break;
			}
		}
		if (idNotSame) {
			cout << "Error: Product Does Not Exist!\n";
			cin.ignore(1000, '\n');
			continue;
		}
		cout << "\nProduct's Current Name: " << productNames[productIndex] << endl;
		cout << "Product's Current Price: " << productPrices[productIndex] << endl;
		cout << "Product's Current Quantity: " << productQuantities[productIndex] << endl;
		cout << endl << endl;

		cout << "Enter Product's New Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Product's New Price: ";
		cin >> price;
		if (cin.fail() || price < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		cout << "Enter Product's New Quantity: ";
		cin >> quantity;

		if (cin.fail() || quantity < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		else {
			cout << "\n\n******** Product Updated Successfully ********\n\n\n";
			delay();
			clearScreen();
			cout << right;
			break;
		}
	} while (true);

	if (id != 0) {
		productNames[productIndex] = name;
		productPrices[productIndex] = price;
		productQuantities[productIndex] = quantity;
	}
}

void deleteProduct() {
	int id = 0;
	string name = " ";
	float price = 0;
	int quantity = 0;
	int productIndex = -1;
	bool idNotSame = true;
	char del = ' ';

	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Delete Product " << setw(71) << "" << setfill(' ') << endl << endl;
	do {
		idNotSame = true;
		cout << "Enter Product ID (Enter 0 to Exit): ";
		cin >> id;

		if (cin.fail() || id < 0) {
			cout << "Invalid Input. Try Again.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (id == 0) {
			clearScreen();
			cout << "\n\n******** Deleting Product Cancelled ********\n\n";
			break;
		}
		for (int i = 0; i < productCount; i++) {
			if (id == productIds[i]) {
				productIndex = i;
				idNotSame = false;
				break;
			}
		}
		if (idNotSame) {
			cout << "Error: Product Does Not Exist!\n";
			cin.ignore(1000, '\n');
			continue;
		}

		cout << "\nProduct's Name: " << productNames[productIndex] << endl;
		cout << "Product's Price: " << productPrices[productIndex] << endl;
		cout << "Product's Quantity: " << productQuantities[productIndex] << endl;
		cout << "\nAre you sure you want to delete the product? press y to delete it: ";
		cin >> del;

		if (del == 'y' || del == 'Y') {
			for (int i = productIndex; i < productCount-1; i++) {
				productIds[i] = productIds[i + 1];
				productNames[i] = productNames[i + 1];
				productPrices[i] = productPrices[i + 1];
				productQuantities[i] = productQuantities[i + 1];
			}
			productCount--;
			cout << "\n\n******** Product Deleted Successfully ********\n\n\n";
			delay();
			clearScreen();
			cout << right;
			break;
		}
		else {
			cout << "\n\n******** Product Deletion Cancelled ********\n\n\n";
			delay();
			clearScreen();
			cout << right;
			break;
		}
	} while (true);
}

int productManagement() {
	
	int choicep = 0;
	bool exitp = false;

	do {
		cout << setfill(' ');
		cout << endl;
		cout << setw(85) << setfill('-') << " Product Management " << setw(71) << "" << setfill(' ') << endl << endl;
		cout << setw(81) << " 1. Add Product " << endl << endl;
		cout << setw(84) << " 2. Update Product " << endl << endl;
		cout << setw(84) << " 3. Delete Product " << endl << endl;
		cout << setw(87) << " 4. Exit to Main Menu " << endl << endl;
		cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choicep;

		switch (choicep) {
		case 1:
			clearScreen();
			addProduct();
			exitp = true;
			break;
		case 2:
			clearScreen();
			updateProduct();
			exitp = true;
			break;
		case 3:
			clearScreen();
			deleteProduct();
			exitp = true;
			break;
		case 4:
			clearScreen();
			exitp = true;
			break;
		default:
			clearScreen();
			cout << "\nWrong Input. Please select the correct option.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!exitp);
	return 0;
}