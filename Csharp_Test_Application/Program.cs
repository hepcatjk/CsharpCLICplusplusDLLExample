using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EntityLibrary;

namespace SimpleClient
{

    class Program
    {
        static void Main(string[] args)
        {
            var entity = new ManagedEntity();

            double myDouble = -1.1;
            int myInt = -1;
            string myCharString = "c# empty charstring";
            string myString = "c# empty string";
            double[] myArray = { -1.1, -2.1, -3.1 };


            //Test Double
            System.Console.WriteLine("C# - Value for double: {0}", myDouble);
            System.Console.WriteLine("C# - C++ Value stored for the double: {0}", entity.GetDouble());
            myDouble = entity.GetDouble();
            System.Console.WriteLine("C# - Value for double after GetDouble: {0}", myDouble);
            entity.SetDouble(100.1);
            System.Console.WriteLine("C# - C++ Value stored for the double: {0} \n", entity.GetDouble());

            //Test Int
            System.Console.WriteLine("C# - Value for int: {0}", myInt);
            System.Console.WriteLine("C# - C++ Value stored for the int: {0}", entity.GetInt());
            myInt = entity.GetInt();
            System.Console.WriteLine("C# - Value for int after GetInt: {0}", myInt);
            entity.SetInt(100);
            System.Console.WriteLine("C# - C++ Value stored for the int: {0} \n", entity.GetInt());

            //Test CharString
            System.Console.WriteLine("C# - Value for charstring: {0}", myCharString);
            System.Console.WriteLine("C# - C++ Value stored for the charstring: {0}", entity.GetCharString());
            myCharString = entity.GetCharString();
            System.Console.WriteLine("C# - Value for charstring after GetCharString: {0}", myCharString);
            entity.SetCharString("one-hundred point one");
            System.Console.WriteLine("C# - C++ Value stored for the charstring: {0} \n", entity.GetCharString());

            //Test String
            System.Console.WriteLine("C# - Value for string: {0}", myString);
            System.Console.WriteLine("C# - C++ Value stored for the string: {0}", entity.GetString());
            myString = entity.GetString();
            System.Console.WriteLine("C# - Value for string after GetString: {0}", myString);
            entity.SetString("one-hundred point two");
            System.Console.WriteLine("C# - C++ Value stored for the string: {0} \n", entity.GetString());

            //Test Array
            System.Console.WriteLine("C# - Value for array: {0}", string.Join(", ", myArray)); 
            System.Console.WriteLine("C# - C++ Value stored for the string: {0}", string.Join(", ", entity.GetVector()));
            myArray = entity.GetVector();
            System.Console.WriteLine("C# - Value for array after GetVector: {0}", string.Join(", ", myArray));
            entity.SetVector(new double[] { 100.1, 100.2, 100.3, 100.4 });
            System.Console.WriteLine("C# - C++ Value stored for the string: {0}", string.Join(", ", entity.GetVector()));


            //array,comma trick needs .NET 4+ if it does not work use code below to print array to console
            // foreach (var item in myArray)
            // {
            //     Console.Write("{0}", item);
            //     if (item != myArray.Last())
            //         Console.Write(",");
            // }

        }
    }
}