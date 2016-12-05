#include "ManagedEntity.h"

using namespace EntityLibrary;
using namespace System;
using namespace System::Runtime::InteropServices;	// needed for Marshal


ManagedEntity::ManagedEntity() {
    nativeObj = new NativeEntity();
}


ManagedEntity::~ManagedEntity() {
    delete nativeObj;

}


double ManagedEntity::GetDouble()
{
    double tempDouble = nativeObj->GetDouble();
    return tempDouble;
}


int ManagedEntity::GetInt()
{
    int tempInt = nativeObj->GetInt();
    return tempInt;
}


String^ ManagedEntity::GetCharString()
{
    char* pchValue = nativeObj->GetCharString();
    String^ tempString = Marshal::PtrToStringAnsi(static_cast<IntPtr>(pchValue));
    return tempString;
}


String^ ManagedEntity::GetString()
{
    String^  tempString = gcnew String( nativeObj->GetString().c_str());
    return tempString;
}


array<double>^ ManagedEntity::GetVector()
{
    std::vector<double> tempVec = nativeObj->GetVector();
    const int SIZE = tempVec.size();
    array<double> ^tempArr = gcnew array<double>(SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        tempArr[i] = tempVec[i];
    }
    return tempArr;
}

void ManagedEntity::SetDouble(double nDouble)
{
    nativeObj->SetDouble(nDouble);
}


void ManagedEntity::SetInt(int nInt)
{
    nativeObj->SetInt(nInt);
}


void ManagedEntity::SetCharString(String^ nCharString)
{
    IntPtr pString = Marshal::StringToHGlobalAnsi(nCharString);
    try
    {
        char* pchString = static_cast<char *>(pString.ToPointer());
        nativeObj->SetCharString(pchString);
    }
    finally
    {
        Marshal::FreeHGlobal(pString);
    }
}


void ManagedEntity::SetString(String^ nString)
{
    IntPtr pString = Marshal::StringToHGlobalAnsi(nString);
    try
    {
        char* pchString = static_cast<char *>(pString.ToPointer());
        nativeObj->SetString(pchString);
    }
    finally
    {
        Marshal::FreeHGlobal(pString);
    }
}




void ManagedEntity::SetVector(array<double>^ nVec) 
{
    std::vector<double> tempVec;

    for each (double elem in nVec)
        tempVec.push_back(elem);

    nativeObj->SetVector(tempVec);
}