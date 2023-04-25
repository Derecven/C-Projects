/*
* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 5/6/22
* Title: Vectors
* File: main.cpp
* Description: Modular program that takes in items (class) and allows adding, searching and sorting
*              Has capabilities of reading in an input file and creating output file from data
*              Uses a vector to manage the collection of items
*/

//LIBRARIES AND HEADER FILES
#include <iostream>
#include <string>
#include <fstream>
#include "Item.hpp"
#include "ItemCollection.hpp"
using namespace std;

#define ITEM_FILE_PATH "C:\\temp\\ItemFile.txt"

//PROTOTYPES
void displayMenu();
void writeItemDataToFile(ItemCollection& itemList, ofstream& outFile);
void readItemData(ItemCollection& itemList, ifstream& itemFile);

//MAIN
int main(void){
    ItemCollection itemList;
    int selection;
    int loop = 1;

    float ID_search;
    string name_search;

    Item temp;
    Item* itemFind1;
    Item* itemFind2;

    ifstream itemFile; //Input
    ofstream outFile;  //Output
    readItemData(itemList, itemFile); //Reads input file at set path and stores given items

    do{ //Loops displaying the menu and getting choices to execute
        displayMenu(); //Displays options to the user

        cin >> selection; //Takes in user choice
        if(selection < 0){
            cout << "Please enter a valid selection (1-7)" << endl;
        }
        else{
            switch(selection){
                case 1: //Add an new item to the list
                    cout << "Reading in item info from user... " << endl;
                    temp.read(); //Takes user input for item
                    itemList.add(temp); //Adds user to list. ++ count
                    break;
                case 2: //Print the item list
                    cout << endl << "*Item List*" << endl;
                    itemList.print();
                    break;
                case 3: //Print the item in the list with the highest cost
                    cout << endl << "Largest cost item: " << endl;
                    temp = itemList.maxCost();
                    temp.print();
                    break;
                case 4: //Sort the list and print items alphabetically by name
                    cout << endl << "*Sorted Item List*" << endl;
                    itemList.sortByName();
                    itemList.print();
                    break;
                case 5: //Find an item using item name
                    cout << "\nEnter the name to find item: ";
                    getline(cin>>ws, name_search);
                    itemFind1 = itemList.findByName(name_search);
                    if(itemFind1 == NULL){ //Error output
                        cout << "Item not found" << endl;
                    }else{
                        itemFind1->print();
                    }
                    break;
                case 6: //Find an item using item ID
                    cout << "\nEnter the ID to find item: ";
                    cin>>ID_search;
                    itemFind2 = itemList.findByID(ID_search);
                    if(itemFind2 == NULL){ //Error output
                        cout << "Item not found" << endl;
                    }else{
                        itemFind2->print();
                    }
                    break;
                case 7:
                    //Option 7: Quit
                    loop = 0;
                    cout << "Program has been closed. Saved data to file" << endl;
                    break;
                default:
                    cout << "Something went wrong. Please enter in a value (1-7)";
            }
        }
    }while(loop == 1); //Loops until user ends program

    writeItemDataToFile(itemList, outFile); //Will write data when done and program ends

    return 0;
}


void displayMenu(){
//Displays the program options to the user
    cout << "\n***Item Management System***" << endl;
    cout << "1. Add an new item to the list" << endl;
    cout << "2. Print the item list" << endl;
    cout << "3. Print the item in the list with the highest cost" << endl;
    cout << "4. Sort the list and print items alphabetically by name" << endl;
    cout << "5. Find an item using item name" << endl;
    cout << "6. Find an item using item ID" << endl;
    cout << "7. Quit and save to file." << endl;
    cout << "Selection: ";
}

void writeItemDataToFile(ItemCollection& itemList, ofstream& outFile){    //const as to not modify data, pass by reference
//Takes all entries in an item list and write them to a file
//    int cnt = itemList.getCount(); //Gets count to know where items end
    outFile.open(ITEM_FILE_PATH); //Opens file to write

    if(outFile.is_open()){

        //When the file stream is good, write data from collection to file
        itemList.print(outFile); //Writes line to output file for single item to output file
    }else{
        cout << "Error: Issue with file. Not open" << endl;
    }
    outFile.close(); //Closes the file when done
}

void readItemData(ItemCollection& itemList, ifstream& itemFile){
//Reads in the data to the file and also adds to the collection for reference
    itemFile.open(ITEM_FILE_PATH); //Get this file from the given const path if available. Opens file
    string name;
    unsigned long ID;
    float cost;
    int quantity;
    int fileLine = 1;
    Item temp;

	if(itemFile.is_open()){
    //If the file is open, read it entries from file and add them to collection
        while(!itemFile.eof()){
           getline(itemFile >> ws, name, ',');
           itemFile >> ID;
           itemFile.ignore(1);
           itemFile >> cost;
           itemFile.ignore(1);
           itemFile >> quantity;

           if(itemFile.good()){
                ++fileLine;
                Item temp(name, ID, cost, quantity); //Create Item obj and puts in vals
                itemList.add(temp); //Adds item to the item list, increments count. Uses collection's add
           }
           else if(itemFile.eof()){
                break; //ends the loop when it reaches end of file
           }
           else{
                itemFile.clear();

                if(fileLine != 0){
                    string temp;
                    getline(itemFile, temp); //reading from failure onward (rest of the line) to display
                    cout << "Error: File was unable to read. Check line: " << fileLine << " at " << temp << endl;
                    break;
                }else{
                    cout << endl << "Program did not find file at path: " << ITEM_FILE_PATH << endl;
                    cout << "Once you save file, it will be able to read it" << endl;
                    break; //stops an infinite loop
                }
           }
        }
    }else{
        cout << "Error: unable to read the file" << endl;

	}
	itemFile.close(); //Closes the file when done
}
