/*
* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 5/6/22
* Title: Vectors
* File: Item.cpp
* Description: Modular program that takes in items (classes) and allows adding, searching and sorting
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Item.hpp"



Item::Item(string name, unsigned long ID, float cost, int quantity){
//Implementation of an Item object, assigns given variables to values
    this -> ID = ID;
    this -> name = name;
    this -> cost = cost;
    this -> quantity = quantity;
}

void Item::read(void){
//Prompts user to enter in Item info and stores in appropriate values
    cout<<"\n*Enter Item Info*"<<endl;
    cout<<"Item Name: "<<endl;
    getline(cin>>ws,name);
    cout<<"Item ID: ";
    cin >> ID;
    cout<<"Item Cost: "<<endl;
    cin>>cost;
    cout<<"Item Quantity: "<<endl;
    cin>>quantity;
    cout<<endl;
}

void Item::print(void){
//Function to print the values of a single item object. Standard C out
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Cost: " << cost << endl;
    cout << "Quantity: " << quantity << endl << endl;
}

void Item::print(ofstream& outFile){
//Function to print values of a single item. Custom output file stream
//Puts it in single line format so it will be readable by program on later input
    outFile<< name << ", " << ID << ", " << cost << ", " << quantity << '\n';
}




