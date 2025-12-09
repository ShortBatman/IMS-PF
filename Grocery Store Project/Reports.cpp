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

void viewSalesReport() {
	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " All Sales " << setw(71) << "" << setfill(' ') << endl << endl;

	if (salesCount == 0) {
		cout << "\n\n********** No sales have been recorded yet **********\n\n";
		return;
	}

	cout << setw(20) << left << "Product ID" << setw(20) << left << "Name" << setw(20) << left << "Quantity" << setw(20) << left << "Total" << endl;

	cout << fixed << setprecision(2);			//rounds off after 3rd decimal place e.g 43.866 becomes 43.67
	for (int i = 0; i < salesCount; i++) {
		int id = saleProductIds[i];
		int qty = saleQuantities[i];
		float total = saleTotals[i];

		string name = "-";
		bool found = false;
		for (int j = 0; j < productCount && found == false; j++) {
			if (productIds[j] == id) {
				name = productNames[j];
				found = true;
			}
		}
		cout << setw(20) << left << id << setw(20) << left << name << setw(20) << left << qty << setw(20) << left << total << endl;
	}
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	delay();
	clearScreen();
	cout << right;
}

void showTopSelling() {
	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Top Selling " << setw(71) << "" << setfill(' ') << endl << endl;

	if (salesCount == 0) {
		cout << "\n\n********** No sales have been recorded yet **********\n\n";
		return;
	}

	int topProductId = -1;
	int topQuantity = 0;

	for (int i = 0; i < productCount; i++) {
		int currentId = productIds[i];
		int totalQtyForProduct = 0;

		for (int j = 0; j < salesCount; j++) {
			if (saleProductIds[j] == currentId) {
				totalQtyForProduct += saleQuantities[j];
			}
		}

		if (totalQtyForProduct > topQuantity) {
			topQuantity = totalQtyForProduct;
			topProductId = currentId;
		}
	}

	if (topQuantity == 0 || topProductId == -1) {
		cout << "\n\n********** No sales have been recorded yet **********\n\n";
		return;
	}

	string name = "";
	float price = 0;
	int quantityStock = 0;			//the quantity that is in stock

	bool found = false;
	for (int i = 0; i < productCount && found == false; i++) {
		if (productIds[i] == topProductId) {
			name = productNames[i];
			price = productPrices[i];
			quantityStock = productQuantities[i];
			found = true;
		}
	}

	cout << fixed << setprecision(2);

	cout << "Product ID: " << topProductId << endl;
	cout << "Name      : " << name << endl;
	cout << "Price     : " << price << endl;
	cout << "Sold Quantity  : " << topQuantity << endl;
	cout << "In Stock  : " << quantityStock << endl << endl;
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	delay();
	clearScreen();
	cout << right;
}

void showTotalRevenue() {
	cout << setfill(' ');
	cout << endl;
	cout << setw(85) << setfill('-') << " Total Revenue " << setw(71) << "" << setfill(' ') << endl << endl;
	if (salesCount == 0)
	{
		cout << "\nNo sales have been recorded yet\n";
		return;
	}
	float total = 0;

	for (int i = 0; i < salesCount; i++)
	{
		total += saleTotals[i];
	}
	cout << fixed << setprecision(2);
	cout << "Total Revenue earned from all sales: " << total << endl << endl;
	cout << setw(156) << setfill('-') << "-" << setfill(' ') << endl << endl;
	delay();
	clearScreen();
	cout << right;
}


int reports() {
	int choicer = 0;
	bool exitr = false;

	do {
		cout << endl;
		cout << setw(85) << setfill('-') << " Reports " << setw(71) << "" << setfill(' ') << endl << endl;
		cout << setw(84) << " 1. View All Sales " << endl << endl;
		cout << setw(94) << " 2. View Top Selling Product " << endl << endl;
		cout << setw(88) << " 3. View Total Revenue " << endl << endl;
		cout << setw(87) << " 4. Exit to Main Menu " << endl << endl;
		cout << setw(156) << setfill('-') << "-" << endl << endl;
		cout << "Enter your Choice: ";
		cin >> choicer;

		switch (choicer) {
		case 1:
			clearScreen();
			viewSalesReport();
			exitr = true;
			break;
		case 2:
			clearScreen();
			showTopSelling();
			exitr = true;
			break;
		case 3:
			clearScreen();
			showTotalRevenue();
			exitr = true;
			break;
		case 4:
			clearScreen();
			exitr = true;
			break;
		default:
			clearScreen();
			cout << "\nWrong Input. Please select the correct option.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!exitr);
	return 0;
}