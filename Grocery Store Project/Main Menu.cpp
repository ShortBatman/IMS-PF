#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string noSpaces(string name) {
	string newName;
	for (int i = 0; i < 100; i++) {
		if (name[i] == '\0') break;
		if (name[i] != ' ') {
			newName += name[i];
		}
	}
	return newName;
}

void delay() {
	cout << "\nPress Enter To Continue...";
	cin.ignore(1000, '\n');
	cin.get();					// waits for input
}

void clearScreen() {
	system("cls");
}

// Passing productCount as a reference so that it gets modified every time the file is loaded (awein hi just to be safe)

void loadfile(int& productCount, int productIds[], string productNames[], float productPrices[], int productQuantities[],int& salesCount, int saleProductIds[], float saleTotals[], int saleQuantities[]) {

	ifstream listFile("inventorylist.txt");
	if (listFile) {
		listFile >> productCount;
		listFile.ignore();			// product count number k agay jo \n hai usay ignore krny k liye

		for (int i = 0; i < productCount; i++) {
			listFile >> productIds[i];
			listFile.ignore();							// it clears '\n' and goes to the next line
			getline(listFile, productNames[i]);				// like getline(cin,name) is mein hum bata rhy k cin ni krna blky file read krna hai and ye next line bhi kr deta hai
			listFile >> productPrices[i];
			listFile >> productQuantities[i];
		}
		listFile.close();
	}
	else {
		cout << "\nLists File Failed to Open.\n";
	}
	
	ifstream salesFile("sales.txt");
	if (salesFile) {
		salesFile >> salesCount;
		for (int i = 0; i < salesCount; i++) {
			salesFile >> saleProductIds[i];
			salesFile >> saleQuantities[i];
			salesFile >> saleTotals[i];
		}
		salesFile.close();
	}
	else {
		cout << "\nSales File Failed to Open.\n";
	}
}

void savefile(int& productCount, int productIds[], string productNames[], float productPrices[], int productQuantities[], int& salesCount, int saleProductIds[], float saleTotals[], int saleQuantities[]) {
	
	ofstream listFile("inventorylist.txt");
	if (listFile) {
		listFile << productCount << endl;
		for (int i = 0; i < productCount; i++) {
			listFile << productIds[i] << endl;
			listFile << productNames[i] << endl;
			listFile << productPrices[i] << " " << productQuantities[i] << endl;  // because no next line while loading prices and quantities
		}
		listFile.close();
		cout << "\nInventory saved successfully!\n";
	}
	else {
		cout << "\nFailed to save inventory file.\n";
	}

	ofstream salesFile("sales.txt");
	if (salesFile) {
		salesFile << salesCount << endl;
		for (int i = 0; i < salesCount; i++) {
			salesFile << saleProductIds[i] << " " << saleQuantities[i] << " " << saleTotals[i] << endl;
		}
		salesFile.close();
		cout << "Sales saved successfully!\n";
	}
	else {
		cout << "\nFailed to save sales file.\n";
	}
}

// these functions are present in other cpp files

int productManagement();
int inventoryTracking();
int salesManagement();
int reports();

int productIds[100];					// arrays ill be using for product management
string productNames[100];
float productPrices[100];
int productQuantities[100];
int productCount = 0;

int saleProductIds[500];				// arrays ill be using for sales
int saleQuantities[500];
float saleTotals[500];
int salesCount = 0;


int main() {
	loadfile(productCount, productIds, productNames, productPrices, productQuantities, salesCount, saleProductIds, saleTotals, saleQuantities);
	int choice = 0;
	bool exit = false;
	system("color 4f");

	do {
		cout << setfill(' ');				// to reset the setfill ta k koi or character disturb na kry
		cout << endl;
		cout << setw(82) << setfill('-') << " Main Menu " << setw(74) << "" << setfill(' ') << endl << endl;
		cout << setw(88) << " 1. Product Management " << endl << endl;
		cout << setw(88) << " 2. Inventory Tracking " << endl << endl;
		cout << setw(86) << " 3. Sales Management " << endl << endl;
		cout << setw(77) << " 4. Reports " << endl << endl;
		cout << setw(83) << " 5. Save and exit " << endl << endl;
		cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			clearScreen();
			productManagement();
			break;
		case 2:
			clearScreen();
			inventoryTracking();
			break;
		case 3:
			clearScreen();
			salesManagement();
			break;
		case 4:
			clearScreen();
			reports();
			break;
		case 5:
			clearScreen();
			savefile(productCount, productIds, productNames, productPrices, productQuantities, salesCount, saleProductIds, saleTotals, saleQuantities);
			exit = true;

			cout << "\n\n************ Thank You! For using our service ************\n\n\n"; break;
		default:
			clearScreen();
			cout << "\nWrong Input. Please select the correct option.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!exit);
	cout << right;				// to reset the << left i used above
	return 0;
}