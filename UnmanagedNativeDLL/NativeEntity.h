#pragma once

#include <vector>

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the EXAMPLEUNMANAGEDDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// EXAMPLEUNMANAGEDDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef EXAMPLEUNMANAGEDDLL_EXPORTS
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllexport)
#else
#define EXAMPLEUNMANAGEDDLL_API __declspec(dllimport)
#endif





class EXAMPLEUNMANAGEDDLL_API NativeEntity {
public:
    NativeEntity();

    //gets
    double GetDouble();
    int GetInt();
    char* GetCharString();
    std::string GetString();
    std::vector<double> GetVector();

    //sets
    void SetDouble(double nDouble);
    void SetInt(int nInt);
    void SetCharString(char* nCharString);
    void SetString(std::string nString);
    void SetVector(std::vector<double> &nVec);

private:
    double mDouble;
    int mInt;
    char* mCharString;
    std::string mString;
    std::vector<double> mVec;
};