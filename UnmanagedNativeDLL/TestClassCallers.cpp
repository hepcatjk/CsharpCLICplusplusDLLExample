#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include "TestClassCallers.h"


extern "C" EXAMPLEUNMANAGEDDLL_API NativeEntity* CreateTestClass()
{
    return new NativeEntity();
}

extern "C" EXAMPLEUNMANAGEDDLL_API void DisposeTestClass(NativeEntity* pObject)
{
    if(pObject != NULL)
    {
        delete pObject;
        pObject = NULL;
    }
}

extern "C" EXAMPLEUNMANAGEDDLL_API double CallGetDouble(NativeEntity* pObject)
{
    if (pObject != NULL)
    {
        return pObject->GetDouble();
    }

    return NULL;
}


extern "C"  EXAMPLEUNMANAGEDDLL_API int CallGetInt(NativeEntity* pObject)
{
    if (pObject != NULL)
    {
        return pObject->GetInt();
    }

    return NULL;
}

extern "C"  EXAMPLEUNMANAGEDDLL_API char* CallGetCharString(NativeEntity* pObject)
{
    if (pObject != NULL)
    {
        return pObject->GetCharString();
    }

    return NULL;
}


extern "C"  EXAMPLEUNMANAGEDDLL_API std::string CallGetString(NativeEntity* pObject)
{
    if (pObject != NULL)
    {
        return pObject->GetString();
    }

    return NULL;
}


extern "C"  EXAMPLEUNMANAGEDDLL_API std::vector<double> CallGetVector(NativeEntity* pObject)
{
    if (pObject != NULL)
    {
        return pObject->GetVector();
    }

    return std::vector<double>();
}

extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetDouble(NativeEntity* pObject, double nDobule)
{
    if (pObject != NULL)
    {
        pObject->SetDouble(nDobule);
    }
}

extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetInt(NativeEntity* pObject, int nInt)
{
    if (pObject != NULL)
    {
        pObject->SetInt(nInt);
    }
}


extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetCharString(NativeEntity* pObject, char* nCharString)
{
    if (pObject != NULL)
    {
        pObject->SetCharString(nCharString);
    }
}

extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetString(NativeEntity* pObject, std::string nString)
{
    if (pObject != NULL)
    {
        pObject->SetString(nString);
    }
}


extern "C"  EXAMPLEUNMANAGEDDLL_API void CallSetVector(NativeEntity* pObject, std::vector<double> &nVec)
{
    if (pObject != NULL)
    {
        pObject->SetVector(nVec);
    }
}
