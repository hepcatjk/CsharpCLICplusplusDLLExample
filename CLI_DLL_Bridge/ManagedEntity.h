#pragma once

#include "NativeEntity.h"
#include <vector>
namespace EntityLibrary {
    using namespace System;


    public ref class ManagedEntity {
    public:
        ManagedEntity();
        ~ManagedEntity();

        //Gets
        double GetDouble();
        int GetInt();
        String^ GetCharString();
        String^ GetString();
        array<double>^ GetVector();

        //Sets
        void SetDouble(double nDouble);
        void SetInt(int nInt);
        void SetCharString(String^ nCharString);
        void SetString(String^ nString);
        void SetVector(array<double>^ nVec);


    private:
        NativeEntity* nativeObj; // Our native object is thus being wrapped
    };

}