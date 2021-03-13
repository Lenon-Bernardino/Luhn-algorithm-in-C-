#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

string randomnew(int digits)
{
    srand(time(0));
    digits -= 1;
    string initial_string = "";
    for (int i = 0; i <= digits; i++)
    {
        initial_string.append(std::to_string(rand()%10));
    }
    return initial_string;
}

int main()
{
    cout << "                       ______\n";
    cout << "                    .-\"      \"-.\n";
    cout << "                   /            \\\n";
    cout << "       _          |              |          _\n";
    cout << "      ( \\         |,  .-.  .-.  ,|         / )\n";
    cout << "       > \"=._     | )(__/  \\__)( |     _.=\" <\n";
    cout << "      (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)\n";
    cout << "             \"=._ (_     ^^     _)\"_.=\"\n";
    cout << "                 \"=\\__|IIIIII|__/=\"\n";
    cout << "                _.=\"| \\IIIIII/ |\"=._\n";
    cout << "      _     _.=\"_.=\"\\          /\"=._\"=._     _\n";
    cout << "     ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )\n";
    cout << "      > _.=\"                            \"=._ <\n";
    cout << "     (_/                                    \\_)\n";
    cout << "     ===============LUHN ALGORITHM==============";
    cout << "\nPress enter to start";
    getchar();
    bool epic = true;
    while(epic == true) 
    {
    string credit_card = randomnew(16);
    cout << credit_card << "\n";
    std::string::size_type sz;
    string doubled_evens = "";
    for (std::string::size_type i = 0; i <= credit_card.size()-1; i++) 
    {
        std::string stringnumber(1, credit_card[i]);
        long number = std::stol(stringnumber, &sz);
        cout << "\nAt: " << number << "\n";
        cout << number << "\n";
        if (number % 2 == 0)
        {
            if (number*2 > 9)
            {
                int summed_digits = (number*2)/10 + (number*2)%10;
                doubled_evens += std::to_string(summed_digits);
            }
            else
            {
                doubled_evens += std::to_string(number * 2);
            }
        }
        else
        {
            doubled_evens += std::to_string(number);
        }
    }
    cout << doubled_evens;
    int final_number = 0;
    for(std::string::size_type i = 0; i <= doubled_evens.size()-1; i++)
    {
        std::string stringnumber(1, doubled_evens[i]);
        int number = std::stoi(stringnumber, &sz);
        final_number += number;
    }
    if (final_number % 10 == 0) 
    {
        cout << "\nFound valid credit card, press enter for next one: " << credit_card << "\n";
        getchar();
    }
    }
}
