#include <iostream>
#include <cmath>
#include <vector>

// ------template function------
template<typename T>
bool binarySearch(T arr[], int size, T target)
{
    int left{};
    int right = size - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target) {
            return true;
        }
        else if (arr[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return false;
}

// ---- template specialization for <int> datatype (using linear search)
template<>
bool binarySearch<int>(int arr[], int size, int target)
{
    std::cout << "*With using linear search\n";
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// ------template class------
template <class T>
class ArrayConversion {
public:
    ArrayConversion() {}

    ArrayConversion(std::vector<T>& input) : innitialArray(input) {}

    std::vector<T> Converting(const std::vector<T>& input)
    {
        std::vector<T> output;
        output.reserve(input.size());

        try {
            for (auto& element : input) {
                if constexpr (std::is_same_v<T, char> || std::is_same_v<T, std::string>) {
                    throw std::invalid_argument("Invalid type. Cannot convert char or string.");
                }
                else {
                    output.push_back(std::exp(element));
                }
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        return output;
    }

    void PrintArray(std::vector<T>& array) {
        for (auto& element : array) {
            std::cout << element << " ";
        }
    }
private:
    std::vector<T> innitialArray;
};


int main()
{
    // -------------------------------------FUNCTION TASK
    std::cout << "--------TASK 1--------\n";

    int intArr[] = { 1, 2, 3, 4, 5 };
    double doubleArr[] = { 1.4, 2.2, 3.9, 4.3, 5.6 };
    char charArr[] = { 'a', 'c', 'd', 'g', 'y' };

    int choice;
    std::cout << "1. Int Array \n";
    std::cout << "2. Double Array \n";
    std::cout << "3. Char Array \n";
    std::cout << "\nChoose an array: "; std::cin >> choice;
    std::cout << "----------------------\n";

    switch (choice)
    {
    case 1:
    {
        int intVal{};
        std::cout << "Int Array contains \n{1, 2, 3, 4, 5}\n";
        std::cout << "\nEnter num to find: ";
        std::cin >> intVal;
        bool foundIntValue = binarySearch(intArr, sizeof(intArr) / sizeof(int), intVal);
        std::cout << "----------------------\n";
        std::cout << (foundIntValue ? "\nCongratulations, num found!\n\n" : "\nSorry, Int num not found.\n\n");
        break;
    }
    case 2:
    {
        double doubleVal{};
        std::cout << "Double Array contains \n{ 1.4, 2.2, 3.9, 4.3, 5.6 }\n";
        std::cout << "\nEnter num to find: ";
        std::cin >> doubleVal;
        bool foundDoubleValue = binarySearch(doubleArr, 5, doubleVal);
        std::cout << (foundDoubleValue ? "\nCongratulations, num found!\n\n" : "\nSorry, Double num not found.\n\n");
        break;
    }
    case 3:
    {
        char charValue{};
        std::cout << "Char Array contains \n{'a', 'c', 'd', 'g', 'y'}\n";
        std::cout << "\nEnter char to find: ";
        std::cin >> charValue;
        bool foundCharValue = binarySearch(charArr, 5, charValue);
        std::cout << (foundCharValue ? "\nCongratulations, character found!\n\n" : "\nSorry, Character not found.\n\n");
        break;
    }
    default:
        std::cout << "Invalid choice, try again. \n";
    }

    // ----------------------------------------CLASS TASK
    std::cout << "\n--------TASK 2--------\n";

    std::vector<int> intInput = { 1, 2, 3 };
    ArrayConversion<int> intConvertArray(intInput);
    std::vector<int> intOutput = intConvertArray.Converting(intInput);

    std::cout << "Innitial Int Array: " << std::endl;
    intConvertArray.PrintArray(intInput); std::cout << "\n";

    std::cout << "\nExponentyal Int Array: " << std::endl;
    intConvertArray.PrintArray(intOutput); std::cout << "\n";
    std::cout << "----------------------\n";

    // ------------------------------------------------------------------------------------
    std::cout << "\n";
    std::vector<char> charInput = { 'a', 'b', 'c' };
    ArrayConversion<char> charConvertArray(charInput);
    std::vector<char> charOutput = charConvertArray.Converting(charInput);

    std::cout << "Innitial Char Array: " << std::endl;
    charConvertArray.PrintArray(charInput); std::cout << "\n";

    std::cout << "\nExponentyal Char Array: " << std::endl;
    charConvertArray.PrintArray(charOutput); std::cout << "\n";
    std::cout << "----------------------\n";
    // ------------------------------------------------------------------------------------


    std::vector<float> floatInput = { 1.3, 2.7, 3.4 };
    ArrayConversion<float> floatConvertArray(floatInput);
    std::vector<float> floatOutput = floatConvertArray.Converting(floatInput);

    std::cout << "Innitial Double Array: " << std::endl;
    floatConvertArray.PrintArray(floatInput); std::cout << "\n";

    std::cout << "\nExponentyal Double Array: " << std::endl;
    floatConvertArray.PrintArray(floatOutput); std::cout << "\n";
    std::cout << "----------------------\n";


    std::vector<long> longInput = { 1L, 2L, 3L };
    ArrayConversion<long> longConvertArray(longInput);
    std::vector<long> longOutput = longConvertArray.Converting(longInput);

    std::cout << "Innitial Long Array: " << std::endl;
    longConvertArray.PrintArray(longInput); std::cout << "\n";

    std::cout << "\nExponentyal Long Array: " << std::endl;
    longConvertArray.PrintArray(longOutput); std::cout << "\n";

    std::cout << "\n\n";

    system("pause"); return 0;
}
