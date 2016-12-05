#include "NativeEntity.h"
#include <string>
#include <iostream>

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>
#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain(
    HMODULE		/*hModule*/,
    DWORD		ul_reason_for_call,
    LPVOID		/*lpReserved*/)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


NativeEntity::NativeEntity() {
    mDouble = 0.0; 
    mInt = 0;
    static char s_chString[] = "blank_char";
    mCharString = s_chString;
    mString = "blank_string";
    mVec = {0.0, 1.1, 2.2};
}

double NativeEntity::GetDouble() 
{ 
    std::cout << "Unmanaged NativeEnity - GetDouble() was called:  "<< mDouble << std::endl;
    return mDouble; 
}


int NativeEntity::GetInt()
{ 
    std::cout << "Unmanaged NativeEnity - GetInt() was called:  " << mInt << std::endl;
    return mInt; 
}


char* NativeEntity::GetCharString() 
{
    std::cout << "Unmanaged NativeEnity - GetCharString() was called:  " << mCharString << std::endl;
    return mCharString; 
}


std::string NativeEntity::GetString() 
{ 
    std::cout << "Unmanaged NativeEnity - GetString() was called:  " << mString << std::endl;
    return mString; 
}


std::vector<double> NativeEntity::GetVector() 
{ 
    std::cout << "Unmanaged NativeEnity - GetVector() was called:  ";
    for (const auto& i : mVec)
    {
        std::cout << i;
        if (i != mVec.back()) std::cout << ", ";
    }
    std::cout<< std::endl; 
    return mVec; 
}


void NativeEntity::SetDouble(double nDouble) 
{
    std::cout << "Unmanaged NativeEnity - SetDouble() was called with old value: " << mDouble << " new value: "<< nDouble << std::endl;
    mDouble = nDouble; 
}


void NativeEntity::SetInt(int nInt)
{ 
    std::cout << "Unmanaged NativeEnity - SetInt() was called with old value: " << mInt << " new value: " << nInt << std::endl;
    mInt = nInt; 
}


void NativeEntity::SetCharString(char* nCharString) 
{ 
    std::cout << "Unmanaged NativeEnity - SetCharString() was called with old value: " << mCharString << " new value: " << nCharString << std::endl;
    mCharString = nCharString;
}


void NativeEntity::SetString(std::string nString) 
{ 
    std::cout << "Unmanaged NativeEnity - SetString() was called with old value: " << mString << " new value: " << nString << std::endl;
    mString = nString;
}


void NativeEntity::SetVector(std::vector<double> &nVec) 
{ 
    std::cout << "Unmanaged NativeEnity - SetVector() was called with old value:  ";
    for (const auto& i : mVec) 
    {
        std::cout << i;
        if (i != mVec.back()) std::cout << ", ";
    }
    std::cout << " new value: ";
    for (const auto& j : nVec)
    {
        std::cout << j;
        if (j != nVec.back()) std::cout << ", ";
    }

    std::cout << std::endl;
    mVec = nVec;
}
