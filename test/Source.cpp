/*#include <iostream>
#include <string>
using namespace std;

int main()
{


}


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
*/

/*

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cctype>

using namespace std;

string lower(string word);

struct word_count{
    string word;
    int count;
};

int b = 0;
const int ARRAY_SIZE = 50;

int main()
{
    word_count array[ARRAY_SIZE];

    bool inarray;
    int index = 0;
    string current;
    ifstream myfile("./words.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, current))
        {
            inarray = false;
            //change current to all lower case
            current = lower(current);

            for (int i = 0; i < b; i++)
            {
                if (current.compare(array[i].word) == 0)
                {
                    inarray = true;
                    index = i;
                    break;
                }
            }
            if (inarray == false)
            {
                array[b].word = current;
                array[b].count = 1;
                b++;
            }
            else
            {
                array[index].count += 1;
            }
        }

        for (int i = 0; i < b; i++)
        {
            cout << array[i].word << ' ' << array[i].count << endl;
        }

        myfile.close();
    }
   
}


string lower(string word)
{
    const char* cstr = word.c_str();
    char* lowerc = new char[word.length() + 1];
    for (int i = 0; i < word.length() + 1; i++)
    {
        lowerc[i] = tolower(cstr[i]);
    }

    string lowerword = lowerc;


    delete []lowerc;
    return lowerword;
}
*/

#include <string>
#include <iostream>

using namespace std;


bool isPalindrome(string s)
{
    for (int i = 0; i < s.length() / 2 + 1; i++)
    {
        if (s[i] != s[s.length() - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string longestPalindrome(string s) {
        int length = s.length();
        int iteration = 0;
        while (iteration < length)
        {
            for (int i = 0; i < iteration + 1; i++)
            {
                if (isPalindrome(s.substr(0 + i, length - iteration + i)))
                {
                    cout << s.substr(0 + i, length - iteration + i);
                }
            }
            iteration++;
        }
        cout << "None";
    }
}