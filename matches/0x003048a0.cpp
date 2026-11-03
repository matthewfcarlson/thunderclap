// cl-flags: /O2 /GR /GX
#include "gen/owners.h"


extern "C" void* __cdecl AllocFunc(int size);
extern "C" void __cdecl FreeFunc(void* ptr);
extern "C" void* __cdecl memcpy(void* dst, const void* src, size_t size);

void owners::Buffer_3048a0::FUN_003048a0(int newCapacity) {
    if (newCapacity == 0)
        newCapacity = 2;
    if (mCapacity >= newCapacity)
        return;

    void* newData = AllocFunc(newCapacity);
    if (mSize > 0) {
        if (mFlag) {
            for (int i = 0; i < mSize; ++i) {
                ((char*)newData)[i] = ((char*)mData)[i];
            }
        } else {
            memcpy(newData, mData, mSize);
        }
    }

    FreeFunc(mData);
    mData = newData;
    mCapacity = newCapacity;
}