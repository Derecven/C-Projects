/*
* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 5/6/22
* Title: Vectors
* File: ItemCollection.hpp
* Description: Modular program that takes in items (class) and allows adding, searching and sorting
*/
#ifndef ITEMCOLLECTION_HPP
#define ITEMCOLLECTION_HPP


#include "Item.hpp"
#include <vector>

#define MAX 100


class ItemCollection{
    private:
        vector <Item> list;
        int findMaxName(vector<Item>& list, int cnt);
        int findMaxCost(vector<Item>& list, int cnt);
    public:
        void add(Item obj);
        void print(void);
        void print(ofstream& outFile);
        void sortByName(void);
        Item* findByName(string targetName);
        Item* findByID(float targetID);
        Item maxCost();
        //int getCount(void){return count;} //getter for count
};


#endif // ITEMCOLLECTION_HPP
