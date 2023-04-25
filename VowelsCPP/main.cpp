/* Intermediate Programming - C/C++
* Name: Patrick Silver
* Date: 3/21/22
* Title: VowelsCPP
* Description: Prompts user for a sentence and returns the # of keystrokes, vowels, and alphabetic characters
*           Modified to match C++ syntax
*          ***NEEDS WORK SINCE CPP IGNORES LEADING WHITE SPACE CH ON INPUT. DOES NOT LEAVE LOOP****
            *Changed \n to a '.'
*/
//LIBRARIES
#include <iostream>
using namespace std;

//PROTOTPYES
void printOutput(int, int, int);
void clearBuff();

//MAIN
int main(){
    int keystrokes = 0, vowels = 0, alpha_ch = 0, loop = 1;
    //Prompts user for a sentence and stores in buffer
    cout <<"Enter in the sentence with a period at the end and then hit the [Enter] key:" << endl;
    char ch;
    do{
        cin >> ch;
        char temp = tolower(ch); // Switches to lowercase for comparison

        switch(temp) {
            case '.': //Checks for newline, ends loop if found
                //TEMPORARILY SWITCHED \N as C++ ignores the white space
                loop = 0;
                break;
            case ' ': //Checks for spaces
                keystrokes++;
                break;
            //Checks for vowels
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                keystrokes++;
                alpha_ch++;
                break;
            default: //If nothing else applies, see if it is alphabetic
                if(isalpha(temp) != 0){
                    keystrokes++;
                    alpha_ch++;
                    break;
                }
                keystrokes++; //Added for any numerics or special characters
                break;
        }
    }while(loop == 1); //Loops until it hits new line

    //Output and reset buffer
    printOutput(keystrokes, vowels, alpha_ch);
    //clearBuff();

    return 0;
}

//Prints the output for all totals; keystrokes, vowels, alpha characters
void printOutput(int keystrokes, int vowels, int alpha_ch){
    cout << endl << "****RESULTS****" << endl;
    cout << "Total number of keystrokes:" << keystrokes << endl;
    cout << "Total number of vowels:" << vowels << endl;
    cout << "Total number of alphabetic characters:" << alpha_ch << endl;
}

//Clears the stdin buffer
void clearBuff(){
    char c;
    do{
        c=getchar();
    }while(c != '\n');
}
