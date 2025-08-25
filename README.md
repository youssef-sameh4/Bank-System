# 🏦 Bank Project (OOP)

## 📌 Project Overview
This project simulates a basic **banking system** using **Object-Oriented Programming (OOP)** principles.  
It includes a **login system**, **permissions with bitwise AND**, and a **Main Menu** with multiple banking operations.  

🔒 If a user enters incorrect login credentials three times, the system locks for security.

The project also uses helper libraries: **String Library**, **Util Library**, **Date Library**, and **Validate Input Library**.

---

## ✨ Features

### 🔑 Login System
- Requires username and password.
- Locks after **3 failed attempts**.
- Successful login records **login time** and user details.
- Displays the **Main Menu**.

### 🛡️ Permissions (Bitwise AND)
- Each menu option is protected with a **bitwise AND flag**.
- Only users with correct permissions can access sensitive features.
- Example: Only admins can manage users or transfer funds.

---

## 📋 Main Menu Options

1. **Client Screen** → View all clients.  
2. **Add New Client** → Add clients (name, account number, balance).  
3. **Delete Client** → Remove a client.  
4. **Update Client Info** → Edit client details.  
5. **Find Client** → Search by ID or name.  
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
   - Update User Info
   - Find User  
8. **Login Register** → Manage usernames & passwords.  
9. **Currency Exchange**
   - List Currencies
   - Find Currency
   - Update Rate
   - Currency Calculator  
10. **Logout** → Return to login screen.  

✅ Each submenu allows returning to the **Main Menu**.

---

## 📚 Libraries Used

- **String Library** → String validation & formatting.  
- **Util Library** → Helper functions (logging, formatting).  
- **Date Library** → Date/time handling, login logs.  
- **Validate Input Library** → Validates user input (e.g., positive numbers, valid dates).  

---

## 🚀 How to Use

1. **Start the application** → Run the executable.  
2. **Login**  
   - Enter username & password.  
   - 3 wrong attempts → Program locks.  
   - Success → Time logged & Main Menu displayed.  
3. **Permissions**  
   - User role defines available actions.  
   - Example: Only admins can manage users.  
4. **Main Menu** → Choose an option (clients, transactions, users, etc.).  
5. **Logout** → Return to login screen.  

---

## ✅ Conclusion
This project demonstrates how **OOP principles** can be applied in a real-world banking system with focus on **security** and **user permissions**.  

Feel free to **explore, contribute, and suggest improvements** 🎉  

---

👨‍💻 Developed with ❤️ for learning and practice.



