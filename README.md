# Bank Management System

A simple console-based Bank Management System written in C++ to handle basic banking operations such as creating accounts, depositing and withdrawing money, checking balances, and viewing transaction history.

---

## Features

- **Create Account**: Users can create a new bank account with a unique account number, account holder's name, and password.
- **Deposit Money**: Allows users to deposit money into their account.
- **Withdraw Money**: Allows users to withdraw money, provided sufficient balance is available.
- **Check Balance**: Displays the current balance of the user's account (authentication required).
- **View Transaction History**: Shows the list of all transactions for the account (authentication required).
- **Password Authentication**: Ensures that sensitive actions are secure.
- **Exit Option**: Allows users to terminate the program.

---

## Code Highlights

- **Object-Oriented Design**:
  - `BankAccount` class for individual accounts.
  - `Bank` class to manage multiple accounts using a `std::map`.
- **Error Handling**: 
  - Prevents invalid operations like duplicate account numbers or invalid deposits/withdrawals.
  - Authentication for balance checks and transaction history.
- **User-Friendly Console Interface**:
  - Menu-driven interface for easy navigation.

---

## How to Run

1. **Compile the Code**:
   Open a terminal and navigate to the directory containing the source code. Run the following command:
   ```bash
   g++ -o bank_system main.cpp
   ```

2. **Run the Program**:
   Execute the compiled file:
   ```bash
   ./bank_system
   ```

3. **Follow On-Screen Instructions**:
   The program will guide you through its features using a menu-driven interface.

---

## Example Usage

### Create an Account
- **Input**:
  ```
  Enter account number: 12345
  Enter account holder name: John Doe
  Set a password: secure123
  ```
- **Output**:
  ```
  Account created successfully.
  ```

### Deposit Money
- **Input**:
  ```
  Enter account number: 12345
  Enter deposit amount: $500
  ```
- **Output**:
  ```
  Deposited $500 into account 12345.
  ```

### Check Balance
- **Input**:
  ```
  Enter account number: 12345
  Enter password: secure123
  ```
- **Output**:
  ```
  Account 12345 has a balance of $500.
  ```

---

## Future Enhancements

- **Interest Calculation**: Add functionality to calculate interest on account balances.
- **Transfer Funds**: Allow money transfers between accounts.
- **Enhanced Security**: Implement better encryption for passwords.
- **Graphical User Interface (GUI)**: Create a GUI version for better user experience.

---

## Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

---
