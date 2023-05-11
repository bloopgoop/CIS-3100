//Author: Kevin Zhu
//CIS 3100
//Assignment 4

#include <iostream>
#include <ctime>
#include <random>
using namespace std;

const int WHITEBALLS = 69;
const int WHITEPICKS = 5;
const int REDBALLS = 26;

void populate(int array[], int size);
int takeout(int array[], int size);
int b_search(int array[], int size, int value);

int main()
{
    int white_pool[WHITEBALLS];
    int red_pool[REDBALLS];
    int hand[WHITEPICKS];
    int value;

    int games;
    cout << "How many games would you like to play? ";
    cin >> games;

 
    for (int i = 1; i <= games; i++) //loop games times
    {
        cout << "Game " << i << '\n' << "White balls are: ";

        //fill arrays
        populate(white_pool, WHITEBALLS);
        populate(red_pool, REDBALLS);

        //simulate picking out white ball, and putting it into the hand
        for (int round = 0; round <= 4; round ++)
        {
            value = takeout(white_pool, WHITEBALLS - round);
            hand[round] = value;
            cout << hand[round] << ' ';
        }

        //pick one random red ball
        random_device engine;
        uniform_int_distribution<int> randomInt(0, REDBALLS - 1); //this statement defines a distribution object named randomInt
        int index = randomInt(engine);

        cout << "Power Ball is: ";
        cout << red_pool[index] << "\n\n";
    }
    return 0;
}

void populate(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
}


int takeout(int array[], int size)
{
    random_device engine;
    uniform_int_distribution<int> randomInt(0, size - 1); //this statement defines a distribution object named randomInt
    int index = randomInt(engine);

    //take the random index's value and store it in value
    int value = array[index];

    //consolidate the values (move everything to the left one sizeof(int))
    for (int i = index; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    //set last item of sub-array to -1 (int size is variable and will be changed in main)
    array[size - 1] = -1;

    return value;
}


int b_search(int array[], int size, int value) //returns the index of the found value, else returns -1
{
    int left = 0;
    int right = size;
    int middle = (right + left) / 2;
    bool found = false;


    while (!found && left <= right)
    {
        if (array[middle] == value)
        {
            found = true;
        }
        else if (value < array[middle])
        {
            right = middle - 1;
            middle = (right + left) / 2;
        }
        else
        {
            left = middle + 1;
            middle = (right + left) / 2;
        }
    }

    if (found)
    {
        return middle;
    }
    else
    {
        cout << value << " not found\n";
        return -1;
    }
}