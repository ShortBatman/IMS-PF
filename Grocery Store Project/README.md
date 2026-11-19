<div align="center">

# 🛒 IMS-PF
### Grocery Store Inventory Management System

*A console-based inventory, sales, and reporting tool written in C++*

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Type](https://img.shields.io/badge/Interface-Console-black?style=for-the-badge&logo=gnubash&logoColor=white)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![Purpose](https://img.shields.io/badge/Made%20for-Education-orange?style=for-the-badge)

</div>

---

## 📖 About

**IMS-PF** is a console-based Inventory Management System built for a grocery store. It was created as a **semester-end project for Programming Fundamentals** and covers the full day-to-day loop of a small shop: managing products, tracking stock, recording sales, and reviewing business reports. Everything is saved to plain text files, so your data is still there the next time you launch the program.

## ✨ Features

| | Module | What it does |
|---|---|---|
| 📦 | **Product Management** | Add, update, and delete products. Duplicate IDs and names are blocked. |
| 📊 | **Inventory Tracking** | View the full inventory in a clean table and search by product ID. Stock updates automatically after every sale. |
| 💰 | **Sales Management** | Multi-item transactions, itemized bills, stock validation to prevent overselling, and automatic stock reduction. |
| 📈 | **Reports** | Complete sales history, top-selling product by quantity, and total revenue. |
| 💾 | **Persistence** | Data is saved to text files on exit and loaded on startup. |

## 🗂️ Project Structure

```
IMS-PF/
├── Grocery Store Project/
│   ├── main.cpp                # Entry point and main menu
│   ├── productManagement.cpp   # Add / update / delete products
│   ├── inventoryTracking.cpp   # Inventory table and product search
│   ├── salesManagement.cpp     # Transactions and billing
│   ├── reports.cpp             # Sales history, top seller, revenue
│   ├── inventorylist.txt       # Saved inventory data
│   └── sales.txt               # Saved sales data
├── .gitattributes
└── README.md
```

## 🚀 Getting Started

### Prerequisites
- A C++ compiler such as **g++** (MinGW on Windows works well)
- **Windows**, since the program uses `system("cls")` and `system("color")`

### Build

```bash
git clone https://github.com/ShortBatman/IMS-PF.git
cd "IMS-PF/Grocery Store Project"
g++ main.cpp productManagement.cpp inventoryTracking.cpp salesManagement.cpp reports.cpp -o inventory_system
```

### Run

```bash
./inventory_system
```

On Windows you can also run `inventory_system.exe` directly.

## 🧭 How to Use

1. **Launch** the program. Saved inventory and sales are loaded automatically.
2. **Pick an option** from the main menu.
3. **Add your products** first, with unique IDs and names.
4. **Make a sale** by adding one or more items to a transaction. The bill is itemized and stock drops automatically.
5. **Check reports** for sales history, your best seller, and total revenue.
6. **Exit properly** from the menu so your data is saved.

> ⚠️ Close the program through the menu. Closing the console window directly may skip the save step.

## 🛡️ Built-in Safeguards

- ✅ Input validation on user entries
- ✅ Duplicate product ID and name prevention
- ✅ Overselling protection via stock checks
- ✅ Error handling for invalid choices

## ⚙️ Technical Notes

- **Language:** C++
- **Storage:** plain `.txt` files, no database needed
- **Capacity:** fixed arrays holding up to **100 products** and **500 sales**
- **Design:** split into separate modules for products, inventory, sales, and reports

## ⚠️ Limitations

- Windows only, because of `system("cls")` and `system("color")`
- Fixed-size storage (100 products, 500 sales)
- No user authentication
- Text-file storage instead of a real database

## 🔮 Future Enhancements

- [ ] Database integration (SQLite / MySQL)
- [ ] Cross-platform support (Linux and macOS)
- [ ] User authentication and roles
- [ ] Dynamic storage instead of fixed arrays
- [ ] Low-stock alerts

## 🤝 Contributing

This is an educational project and contributions are welcome. Fork the repo, create a branch, and open a pull request.

## 👤 Author

**ShortBatman**
GitHub: [@ShortBatman](https://github.com/ShortBatman)

---

<div align="center">

⭐ If this project helped you, consider giving it a star!

*Built with ☕ and C++ as a Programming Fundamentals project*

</div>
