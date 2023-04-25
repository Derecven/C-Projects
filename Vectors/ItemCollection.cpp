/*
* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 5/6/22
* Title: Vectors
* File: ItemCollection.cpp
* Description: Modular program that takes in items (class) and allows adding, searching and sorting
*/

#include "ItemCollection.hpp"

void ItemCollection::add(Item obj){
//Adds an item object to the item collection
    if((int)list.size() < MAX){
        list.push_back(obj);
    }
    else{
        cout << "No more allocated space in the list" << endl;
    }
}

void ItemCollection::print(){
//prints all items objects in the item collection
    for(vector<Item>::iterator p=list.begin(); p!= list.end(); ++p)
        p->print();
}

void ItemCollection::print(ofstream& outFile){
    for(int i=0;i<(int)list.size();++i){
        list[i].print(outFile);
    }
}

int ItemCollection::findMaxCost(vector<Item>& list, int cnt){
//finds the item with max val cost in an array of items
    int finger = 0;
    for(int i=1; i<cnt; ++i){ //
        if(list[finger].getCost() < list[i].getCost())
            finger = i;
    }
    return finger; //Returns index of the "largest" value cost in the given list
}


int ItemCollection::findMaxName(vector<Item>& list, int cnt){
//finds the item with the max val name in an array of items
    int finger = 0;
    for(int i=1; i<cnt; ++i){ //
        if(list[finger].getName() < list[i].getName())
            finger = i;
    }
    return finger; //Returns index of the "largest" value name in the given list based on ASCII val
}


Item ItemCollection::maxCost(){
//returns the highest costing item in a collection of items
    int ind = findMaxCost(list, list.size());
    return list[ind];
}


void ItemCollection::sortByName(){
//Sorts the Item list by name alphabetically
    int where;
    Item temp;

    for(int i = list.size(); i>0; i--){
        where = findMaxName(list, i);

        temp = list[where];
        list[where] = list[i-1];
        list[i-1] = temp;
    }
}


Item* ItemCollection::findByID(float targetID){
//Takes in target input (ID) to find within a collection of items
    for(int i = 0; i < (int)list.size(); ++i){
        if(list[i].getID() == targetID)
            return &list[i]; //returns the pointer
    }
    return NULL;
}


Item* ItemCollection::findByName(string targetName){
//Takes in target input (name) to find within a collection of items
    for(int i = 0; i < (int)list.size(); ++i){
        if(list[i].getName().compare(targetName) == 0)
            return &list[i]; //returns the pointer
    }
    return NULL;
}
