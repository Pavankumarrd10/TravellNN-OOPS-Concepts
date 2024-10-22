 # TravelInn OOPs Project
## Overview
The TravelInn project is a console-based application built in C++ to simulate a travel booking system. It employs core Object-Oriented Programming (OOP) principles such as classes, inheritance, polymorphism, and exception handling. The project allows users to register as customers or admins, update their profiles, and generate booking receipts. Admins have the ability to manage bookings and notifications, while customers can receive updates and access their travel information.

## Flowchart
![Screenshot (5)](https://github.com/user-attachments/assets/2641207e-ba61-42e9-b58b-2efb15138a11)


## Features
### User Registration & Profile Management:
Two types of users: 
Admins and Customers.
Users can update their profiles and change passwords.
Receipt generation for customers.

### Error Handling:
Custom exceptions are raised for application errors like invalid user actions.

### Notifications:
Customers receive notifications about hotel bookings and changes.


## Functions & OOP Concepts
### 1. Classes
User: The base class, with common properties for all users (customers and admins).
Customer and Admin: Derived classes that implement specific functionalities.
### 2. Inheritance
The Customer and Admin classes inherit from the User class, promoting code reuse.
### 3. Polymorphism
The User class uses virtual functions (printDetails() and updateProfile()) that are overridden in derived classes.
### 4. Exception Handling
The ApplicationException class handles errors and provides detailed messages.
### Key Functions:
printDetails(): Displays user information.
updateProfile(): Allows users to modify their details, such as changing passwords.
notifyUpdates(): Sends updates to customers about hotel bookings.
generateReceipt(): Provides booking information for a customer.
### Input and Output
Input
User inputs data for registration and profile updates.
Admins input hotel and notification details.
Output
Receipt generation for customers.
Console-based notifications and error messages.

## Real-World Application
This project can be extended to develop a fully functioning travel booking management system. It could solve problems such as:

### Efficient User Management: Managing both customers and admins within the same platform.
### Booking Automation: Automating hotel bookings and receipt generation.
### Error Handling: Using custom exception handling for invalid operations or missing data.
In a larger system, this could be used for managing flights, hotels, and travel packages for a travel agency.


