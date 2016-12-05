#include "NativeEntity.h"

#include <iostream>
#include <string>

void printVector(std::vector<double> &temp)
{
    for (const auto& j : temp)
    {
        std::cout << j;
        if (j != temp.back()) std::cout << ", ";
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "NativeEntity DLL Test C++ Program." <<std::endl;

    NativeEntity* nativeObj = new NativeEntity();

    double myDouble = -1.1;
    int myInt = -1;
    char* myCharString = "c# empty charstring";
    std::string myString = "c# empty string";
    std::vector<double> myVector = { -1.1, -2.1, -3.1 };

    //Test Double
    std::cout << "C++TEST - Value for double: "<< myDouble << std::endl;
    std::cout << "C++TEST - C++ Value stored for the double: " << nativeObj->GetDouble() << std::endl;
    myDouble = nativeObj->GetDouble();
    std::cout << "C++TEST - Value for double after GetDouble: " << myDouble << std::endl;
    nativeObj->SetDouble(100.1);
    std::cout << "C++TEST - C++ Value stored for the double: " << nativeObj->GetDouble() << std::endl;
    std::cout << std::endl;

    //Test Int
    std::cout << "C++TEST - Value for int: " << myInt<< std::endl;
    std::cout << "C++TEST - C++ Value stored for the int: " << nativeObj->GetInt() << std::endl;
    myInt = nativeObj->GetInt();
    std::cout << "C++TEST - Value for int after GetInt: " << myInt << std::endl;
    nativeObj->SetDouble(100);
    std::cout << "C++TEST - C++ Value stored for the int: " << nativeObj->GetInt() << std::endl;
    std::cout << std::endl;

    //Test CharString
    std::cout << "C++TEST - Value for charstring: " << myCharString << std::endl;
    std::cout << "C++TEST - C++ Value stored for the charstring: " << nativeObj->GetCharString() << std::endl;
    myCharString = nativeObj->GetCharString();
    std::cout << "C++TEST - Value for charstring after SetCharString: " << myCharString << std::endl;
    nativeObj->SetCharString("one-hundred point one");
    std::cout << "C++TEST - C++ Value stored for the charstring: " << nativeObj->GetCharString() << std::endl;
    std::cout << std::endl;

    //Test String
    std::cout << "C++TEST - Value for string: " << myString << std::endl;
    std::cout << "C++TEST - C++ Value stored for the string: " << nativeObj->GetString() << std::endl;
    myString = nativeObj->GetString();
    std::cout << "C++TEST - Value for string after GetString: " << myString << std::endl;
    nativeObj->SetString("one-hundred point two");
    std::cout << "C++TEST - C++ Value stored for the string: " << nativeObj->GetString() << std::endl;
    std::cout << std::endl;

    //Test Vector
    std::cout << "C++TEST - Value for vector: ";
    printVector(myVector);
    std::vector<double> tempvector = nativeObj->GetVector();
    std::cout << "C++TEST - C++ Value stored for the vector: ";
    printVector(tempvector);
    myVector = nativeObj->GetVector();
    std::cout << "C++TEST - Value for vector after GetVector: ";
    printVector(myVector);
    nativeObj->SetVector(std::vector<double> { 100.1, 100.2, 100.3, 100.4 });
    std::vector<double> tempvector2 = nativeObj->GetVector();
    std::cout << "C++TEST - C++ Value stored for the vector: ";
    printVector(tempvector2);

}