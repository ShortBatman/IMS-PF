# Inventory Management System

A comprehensive console-based inventory management system built in C++ for managing products, tracking inventory, recording sales, and generating business reports.

## Features

### 1. Product Management
- **Add Products**: Register new products with unique IDs, names, prices, and quantities
- **Update Products**: Modify existing product information including name, price, and stock quantity
- **Delete Products**: Remove products from the inventory with confirmation
- **Duplicate Prevention**: Automatic validation to prevent duplicate product IDs or names

### 2. Inventory Tracking
- **View Complete Inventory**: Display all products with their details in a formatted table
- **Search Products**: Quick lookup of products by ID with detailed information display
- **Real-time Stock Updates**: Inventory automatically updates after each sale

### 3. Sales Management
- **Record Sales**: Process multi-item transactions with automatic bill calculation
- **Stock Validation**: Prevents overselling by checking available quantities
- **Detailed Receipts**: Generate itemized bills with product details and grand totals
- **Automatic Inventory Updates**: Stock levels decrease automatically after each sale

### 4. Reports & Analytics
- **View All Sales**: Complete sales history with product details and quantities
- **Top Selling Product**: Identifies the best-performing product by total quantity sold
- **Total Revenue**: Calculates cumulative revenue from all recorded sales

### 5. Data Persistence
- **Auto-save Functionality**: All data is saved to text files upon exit
- **Auto-load on Startup**: Previous session data loads automatically when the program starts
- **Separate File Storage**: Inventory and sales data stored in separate files for organization

## File Structure

```
├── main.cpp                    # Main program and menu system
├── productManagement.cpp       # Product CRUD operations
├── inventoryTracking.cpp       # Inventory viewing and search
├── salesManagement.cpp         # Sales recording and billing
├── reports.cpp                 # Report generation and analytics
├── inventorylist.txt          # Persistent storage for products
└── sales.txt                  # Persistent storage for sales data
```

## Installation & Setup

### Prerequisites
- C++ compiler (GCC, MSVC, or similar)
- Windows OS (for `system("cls")` and `system("color")` commands)

### Compilation
Compile all source files together:
```bash
g++ main.cpp productManagement.cpp inventoryTracking.cpp salesManagement.cpp reports.cpp -o inventory_system
```

### Running the Program
```bash
./inventory_system
```

## Usage Guide

### Starting the Program
1. Run the executable
2. The main menu will display with 5 options

### Adding a Product
1. Select "Product Management" from main menu
2. Choose "Add Product"
3. Enter unique Product ID
4. Enter Product Name
5. Enter Price (must be positive)
6. Enter Initial Quantity (must be positive)

### Recording a Sale
1. Select "Sales Management" from main menu
2. Choose "Record Sale"
3. Enter number of different products in the transaction
4. For each product:
   - Enter Product ID
   - Enter quantity to sell
5. System displays complete bill with grand total

### Viewing Reports
1. Select "Reports" from main menu
2. Choose from:
   - View all sales history
   - View top-selling product
   - View total revenue

### Saving Data
1. Select "Save and exit" from main menu
2. All data automatically saves to text files

## Data Files Format

### inventorylist.txt
```
[Product Count]
[Product ID]
[Product Name]
[Price] [Quantity]
...
```

### sales.txt
```
[Sales Count]
[Product ID] [Quantity Sold] [Line Total]
...
```

## Technical Details

### Data Structures
- **Arrays**: Used for storing product and sales data
- **Maximum Capacity**: 100 products, 500 sales records
- **External Variables**: Shared across modules using `extern` keyword

### Input Validation
- Type checking for all numeric inputs
- Range validation (no negative values)
- Duplicate checking for product IDs and names
- Stock availability verification

### Error Handling
- Invalid input recovery with `cin.clear()` and `cin.ignore()`
- File operation validation
- User-friendly error messages

## Limitations

- Console-based interface (no GUI)
- Windows-specific commands for screen clearing and colors
- Fixed array sizes (100 products, 500 sales)
- Single-user system (no concurrent access)
- Text file storage (no database integration)

## Future Enhancements

- Database integration for better data management
- Cross-platform compatibility
- User authentication system
- Export reports to PDF/Excel
- Barcode scanning support
- Multi-currency support
- Low stock alerts
- Sales analytics with graphs

## Author

Created as a programming fundamentals project demonstrating file handling, modular programming, and data management in C++.

## License

This project is open source and available for educational purposes.

## Contributing

Feel free to fork this repository and submit pull requests for any improvements.
