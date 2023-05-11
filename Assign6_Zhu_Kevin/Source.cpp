//Author: Kevin Zhu
//Assignment 6

#include "header.h"

int main()
{
    string infile;
    cout << "Enter the source data file name: ";
    cin >> infile;

    int phrase_length = 0;
    cout << "How many adjacent words in a phrase, enter 1-5: ";
    cin >> phrase_length;

    string outfile;
    cout << "Enter the phrase frequency file name: ";
    cin >> outfile;

    ifstream text(infile);
    if (!text)
    {
        cout << "Error opening " << infile << endl;
        return 1;
    }

    //fr this time.
    // im going to read all the words and store them in a vector.
    // then modify each element with removePunctuation
    // then I will start to populate vector of MyStrings

    vector<string> words;
    string word;
    string line = "";
    string delimiter = " ";
    size_t pos = 0;
    while (getline(text, line))
    {
        //skip over empty lines
        while (line.length() == 0)
            getline(text, line);

        //split line with delimiter being ' '
        while ((pos = line.find(delimiter)) != string::npos)
        {
            word = line.substr(0, pos);
            //check for single punctuations
            cout << word << ' ';
            if (isChar(word))
            {
                if (isAcceptable(word[0]))
                {
                    words.push_back(word);
                }
            }
            //if not a char, then its a word
            else
            {
                words.push_back(word);
            }
            line.erase(0, pos + delimiter.length());
        }
        //add the last word
        if (isChar(line))
        {
            if (isAcceptable(line[0]))
            {
                words.push_back(word);
            }
        }
        else
            words.push_back(line);
    }

    //now we have a vector of words
    for (int i = 0; i < words.size(); i++)
    {
        words[i] = removePunctuation(words[i]);
        cout << words[i] << " ";
    }

    text.close();


    /*
        //initialize an array of strings and set value = ""
        string *phrase = new string[phrase_length];
        for (int i; i < phrase_length; i++)
        {
            phrase[i] = "";
        }

        int initial_byte = 0;
        string word = "";
        char ch;
        bool prev_was_white = false;
        vector<MyString> phrases;
        bool checkedAll = false;

        while (text)
        {
            initial_byte = text.tellg();
            cout << initial_byte << endl;
            text.seekg(initial_byte, ios::beg);

            int nth_word = 0;
            while (nth_word < phrase_length)
            {
                text.get(ch);
                if (text.eof())
                {
                    checkedAll = true;
                    text.seekg(0, initial_byte);
                    break;
                }
                if ((ch == ' ') || (ch == '\n'))
                {
                    if (!prev_was_white)
                    {
                        nth_word++;
                        prev_was_white = true;
                    }
                }
                else
                {
                    phrase[nth_word] += ch;
                    prev_was_white = false;
                }
            }
            string whole_phrase = "";
            phrase[0] = removePunctuation(phrase[0]);
            whole_phrase += phrase[0];
            for (int i = 1; i < phrase_length; i++)
            {
                phrase[i] = removePunctuation(phrase[i]);
                whole_phrase += " ";
                whole_phrase += phrase[i];
            }

            MyString s(whole_phrase);
            //search vector array for existing phrase
            bool found = false;
            for (int i = 0; i < phrases.size(); i++)
            {
                if (s == phrases[i])
                {
                    found = true;
                    phrases[i]++;
                }
            }
            if (found == false)
            {
                phrases.push_back(s);
            }

            if (checkedAll == true)
            {
                break;
            }
        }

        for (int i = 0; i < phrases.size(); i++)
        {
            cout << phrases[i];
        }

        delete[] phrase;
        */
}