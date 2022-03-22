// REGEX
// Authors: Rafał Synoradzki, Radosław Gąsior
// Tasks done by Michał Roczek 22.03.2022 13:40

#include <iostream>
#include <string>
#include <regex> // regex C++ library
#include <fstream>

using namespace std;


void task1()
{
    //using std::regex
    //There's two regular expressions already declared for you - your task is to assign them accordingly to their purpose:
    //rx0 has to find every word that begins with an uppercase letter
    //rx1 has to find every word that contains "th" in it

    string text = "This above all: to thine own self be true, \n"
                  "And it must follow, as the night the day, \n"
                  "Thou canst not then be false to any man.";
    string rx0text = text;
    string rx1text = text;

    
    /* ---------------------------------------------- */
    regex rx0("([^ ]*[A-Z][^ ]*)"); // <-- assign a regular expression here
    regex rx1("([^ ]*[t][h][^ ]*)"); // <-- assign a regular expression here
    /* ---------------------------------------------- */


    smatch smatch1;

    // loop to write out the matched words into the console
    while(regex_search(rx0text, smatch1, rx0))
    {
        cout << smatch1.str(1) << endl;
        rx0text = smatch1.suffix().str();
    }
    cout << "----------" << endl;
    // loop to write out the matched words into the console
    while(regex_search(rx1text, smatch1, rx1))
    {
        cout << smatch1.str(1) << endl;
        rx1text = smatch1.suffix().str();
    }
    cout << "----------" << endl;
}

void task2()
{
    //using sregex_iterator
    //Here your task is to find out the number of occurrences of the words "ring" and "hobbit" within the text file
    //Those words can occur in the text in both upper- and lowercase letters, thus a certain regex constant has to be used here
    //Words like "rings" or "hobbits" are allowed, but words like "during" aren't

    string txt;
    ifstream file("lab2.txt");
    string rx3scheme = "([ ][Rr]ing[Ss]{0,1})|([Hh]obbit[Ss]{0,1})";

    /* ---------------------------------------------- */
    regex rx3(rx3scheme); // <-- assign a regular expression here
    /* ---------------------------------------------- */


    int sum_of_occurrences = 0;
    if(file.is_open())
    {
        while(getline(file, txt))
        {
            auto words_begin = std::sregex_iterator(txt.begin(), txt.end(), rx3);
            auto words_end = std::sregex_iterator();
            int line_occurrences = distance(words_begin, words_end);
            sum_of_occurrences += line_occurrences;
        }
        file.close();
    }
    cout << "Sum of occurrences: " << sum_of_occurrences << endl;
}

void task3()
{
    //using regex_replace
    //for the first text, you can use any regex you want to change anything in this sentence
    //for the second text, there are multiple digits inserted randomly in - your task is to use regex to remove them

    string before1 = "To be or not to be, that is the question";
    string before11 = "^";

    /* ---------------------------------------------- */
    regex rx3(before11); // <-- assign a regular expression here
    string after1 = regex_replace(before1, rx3, "CHANGE "); // <-- assign a value to the third argument of this function
    /* ---------------------------------------------- */

    cout << after1 << endl;
    cout << "-------------" << endl;

    string before2 = "Far ov8er the m13isty mounta2ins cold \n"
                     "To du3nge45ons dee45p an2d ca3verns 7old \n"
                     "We 2must awa4y, ere br7eak of d89ay";

    string before22 = "([0-9])";
    /* ---------------------------------------------- */
    regex rx4(before22); // <-- assign a regular expression here
    /* ---------------------------------------------- */


    string after2 = regex_replace(before2, rx4, "");
    cout << after2 << endl;
}

int main()
{
    cout << "Task 1: " << endl << endl;
     task1();
    cout << "Task 2: " << endl << endl;
     task2();
    cout << "Task 3: " << endl << endl;
     task3();
    return 0;
}

/*
 * |-----------------------------------------------------------|
 * |     U  S  E  F  U  L     L  I  N  K  S  :                 |
 * |     https://en.cppreference.com/w/cpp/regex               |
 * |     https://www.cplusplus.com/reference/regex/ECMAScript/ |
 * |-----------------------------------------------------------|
 */
