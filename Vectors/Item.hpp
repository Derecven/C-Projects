/*
* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 5/6/22
* Title: Vectors
* File: Item.hpp
* Description: Modular program that takes in items (class) and allows adding, searching and sorting
*/
#ifndef ITEM_HPP
#define ITEM_HPP


#include <iostream>
#include <string>

using namespace std;

class Item{

    private:
        unsigned long ID;
        string name;
        float cost;
        int quantity;

    public:
        Item() = default; //Constructor layout to populate object
        Item(string name, unsigned long ID, float cost, int quantity);
        void read(void);
        void print(void);
        void print(ofstream& outFile);

         //Getter methods
        string getName(void){return name;}
        float getID(void){return ID;}
        float getCost(void){return cost;}
        int getQuantity(void){return quantity;}
};

#endif // ITEM_HPP
