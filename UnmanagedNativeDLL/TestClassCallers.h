#ifndef __TestClassCallers_h__
#define __TestClassCallers_h__

#include "NativeEntity.h"		// needed for EXAMPLEUNMANAGEDDLL_API

#ifdef __cplusplus
extern "C" {
#endif

    extern EXAMPLEUNMANAGEDDLL_API NativeEntity* CreateTestClass();
    extern EXAMPLEUNMANAGEDDLL_API void DisposeTestClass(NativeEntity* pObject);

    extern EXAMPLEUNMANAGEDDLL_API double CallGetDouble(NativeEntity* pObject);
    extern EXAMPLEUNMANAGEDDLL_API int CallGetInt(NativeEntity* pObject);
    extern EXAMPLEUNMANAGEDDLL_API char* CallGetCharString(NativeEntity* pObject);
    extern EXAMPLEUNMANAGEDDLL_API std::string CallGetString(NativeEntity* pObject);
    extern EXAMPLEUNMANAGEDDLL_API std::vector<double> CallGetVector(NativeEntity* pObject);

    extern EXAMPLEUNMANAGEDDLL_API void CallSetDouble(NativeEntity* pObject, double nDobule);
    extern EXAMPLEUNMANAGEDDLL_API void CallSetInt(NativeEntity* pObject, int nInt);
    extern EXAMPLEUNMANAGEDDLL_API void CallSetCharString(NativeEntity* pObject, char* nCharString);
    extern EXAMPLEUNMANAGEDDLL_API void CallSetString(NativeEntity* pObject, std::string nString);
    extern EXAMPLEUNMANAGEDDLL_API void CallSetVector(NativeEntity* pObject, std::vector<double> &nVec);

#ifdef __cplusplus
}
#endif

#endif // __TestClassCallers_h__

