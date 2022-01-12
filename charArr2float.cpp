#include <iostream>
#include <typeinfo>
#include <string>
#include <string.h>

int main()
{
    float f{};
    char numbers[20] = ""; // Maximum of 20-digit number (incl. separator)
    while (true)
    {
        std::cout << "Type in float number with ',', '.' or no separator: ";
        std::cin >> numbers;
        char* pos = &numbers[strlen(numbers)-1]; // pointer at the end of an array, separator: '.' or none
        if (strchr(numbers, ',') != NULL)
        {
            pos = strchr(numbers, ','); // pointer at the position of separator, separator: ','
        }

        // char[] to float
        float beforeComma{};
        float afterComma{};
        beforeComma = strtof(numbers, &pos); // float conversion to end of an array or ','
        //std::cout << beforeComma << '\n';
        
        if (strchr(numbers, ',') != NULL) // float conversion after ',' separator
        {
            char fraction[7]{""};
            memcpy(fraction, pos+1, 6); // 6th decimal place precision
            pos += 7; // Move position to end of a fraction array
            afterComma = strtof(fraction, &pos);
            
            //std::cout << afterComma << '\n';
            while (afterComma > 1)
            {
                afterComma /= 10;
            }
        }
        f = beforeComma + afterComma;
        
        std::cout << "Conversion Result: " << f << typeid(f).name() << '\n';
    }
    return 0;
}