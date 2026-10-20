// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 2/2)
// FUN_002e6570 @ 0x002e6570
#include "compat/ptr.h"
typedef unsigned int uint_2e6570;
extern void* __cdecl FUN_0008d6d0(hulk_uintptr size);
struct FUN_0027b070 {
    FUN_0027b070();
    virtual void baseSlot();
    char baseData[12];
};
struct StringPart { void FUN_0027b040(const char* text); };
namespace pure3d {
struct Language : FUN_0027b070 {
    virtual void slot();
    unsigned char flag;
    char padding[3];
    uint_2e6570 state;
    uint_2e6570 count;
    void* first;
    void* second;
    void* third;
    Language(const char* text, uint_2e6570 n, uint_2e6570 bytes);
};
Language::Language(const char* text, uint_2e6570 n, uint_2e6570 bytes) : FUN_0027b070() {
    flag=0; state=0; count=n; first=0; second=0; third=0;
    if(text) ((StringPart*)(baseData+4))->FUN_0027b040(text);
    uint_2e6570 size=n*4;
    unsigned char* p=(unsigned char*)FUN_0008d6d0(size);
    first=p;
    for(uint_2e6570 i=0;i<size;++i) p[i]=0;
    p=(unsigned char*)FUN_0008d6d0(size);
    second=p;
    for(uint_2e6570 j=0;j<size;++j) p[j]=0;
    p=(unsigned char*)FUN_0008d6d0(bytes & ~1u);
    third=p;
    for(uint_2e6570 k=0;k<bytes;++k) p[k]=0;
}
}
