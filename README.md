# 🏦 Bank Project (OOP)

## 🎯 Overview
This project simulates a **banking system** built with **Object-Oriented Programming (OOP)** concepts.  
It provides **login authentication**, **bitwise permissions**, and a **Main Menu** to perform multiple banking operations.  

🔐 If login fails three times, the system will lock for security reasons.  
The project also uses helper modules: **String**, **Util**, **Date**, and **Input Validation** libraries.

---

## 🌟 Key Features

### 🔓 Authentication
- Secure login with username & password.
- Locks automatically after **3 failed attempts**.
- Successful login records **user details + timestamp**.
- Loads the **Main Menu** after successful login.

### 🧩 Permission System
- Controlled using **bitwise flags**.
- Only authorized users can access sensitive actions.
- Example: Only admins can manage users & transfer money.

---

## 🖥️ Main Menu Functions

1. **Client Screen** → View list of all clients.  
2. **Add New Client** → Create new client records.  
3. **Delete Client** → Remove client from database.  
4. **Update Client Info** → Edit existing client details.  
5. **Find Client** → Search client by ID or Name.  
6. **Transactions**
   - Deposit
   - Withdraw
   - Total Balances
   - Transfer
   - Transfer Log  
7. **Manage Users**
   - List Users
   - Add User
   - Delete User
   - Update User
   - Find User  
8. **Login Register** → Track user login attempts.  
9. **Currency Exchange**
   - List Currencies
   - Find Currency
   - Update Exchange Rate
   - Currency Calculator  
10. **Logout** → Back to login screen.  

---

## 📦 Libraries / Modules

- **String** → Formatting & string validation.  
- **Util** → Helpers like logging & formatting.  
- **Date** → Handle time & login logs.  
- **Validate Input** → Check user inputs (valid numbers, valid dates).  

---

## ⚡ Usage Instructions

1. **Run the program** → Start the executable file.  
2. **Login**
   - Input username & password.
   - Program locks after 3 invalid attempts.
   - On success → Main Menu opens.  
3. **Permissions**
   - User permissions decide what features are available.
   - Admins = full control.  
4. **Navigate**
   - Choose menu option (clients, users, transactions, etc.).  
5. **Logout**
   - Return safely to login page.  

---

## 🔑 Permission Flags (Bitwise)

| Permission                | Value | Description                           |
|---------------------------|-------|---------------------------------------|
| View Clients              | 1     | Can list all clients                  |
| Add New Client            | 2     | Can add new clients                   |
| Delete Client             | 4     | Can remove clients                    |
| Update Client Info        | 8     | Can edit client details               |
| Find Client               | 16    | Can search for specific clients       |
| Transactions              | 32    | Can perform deposits/withdrawals      |
| Manage Users              | 64    | Can manage system users               |
| View Login Records        | 128   | Can access login logs                 |
| Currency Exchange         | 256   | Can manage currencies & rates         |
| **Full Access** (Admin)   | 511   | Complete control over the system      |

---

## 📝 Final Notes
This project highlights how **OOP principles** can be applied in building a secure, permission-based **Banking System**.  
It combines **authentication, transactions, and access control** in one integrated application.  

💡 Contributions & suggestions are welcome 🎉

