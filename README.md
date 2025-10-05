# 🏛 Citizen Data Management (CDM)

This project is a **C-based Citizen Data Management System** that integrates and analyzes **Aadhar, PAN, Bank, and LPG** records.  
It simulates a small-scale governance and financial linkage system, identifying inconsistencies, detecting fraudulent records, and generating useful reports.

---

## 🚀 Features

- **Aadhar but no PAN**: Displays citizens with an Aadhar card but no PAN card.  
- **Multiple PAN Detection**: Identifies citizens with duplicate/multiple PAN numbers.  
- **Multiple Bank Accounts**: Detects citizens holding multiple bank accounts linked with the same PAN.  
- **Wealth & LPG Analysis**: Lists citizens with local savings above a given amount and who also hold LPG connections.  
- **LPG Subsidy Tracker**: Displays subsidy details linked to LPG holders.  
- **Data Consistency Check**: Flags inconsistencies across Aadhar, PAN, Bank, and LPG datasets.  
- **Merged Data View**: Consolidates linked records across Aadhar, PAN, and Bank.  

---

## 🛠 Tech Stack & Tools

- **Language**: C  
- **Data Structures**: Singly Linked Lists for dynamic storage of Aadhar, PAN, Bank, and LPG records.  
- **Memory Management**: Dynamic allocation with `malloc` and `free`.  
- **Concepts Used**:  
  - Linked list traversal  
  - Searching & comparison  
  - Cross-dataset matching  
  - Modular functions  

---

## ⚙️ How It Works

1. Records for **Aadhar, PAN, Bank, and LPG** are hardcoded into linked lists.  
2. User is presented with a **menu-driven program** offering multiple analytical operations.  
3. Each option triggers specific functions that traverse linked lists, match records, and display results.  
4. Data such as **multiple PAN numbers**, **local savings with LPG**, and **inconsistencies** are reported clearly.  

---



