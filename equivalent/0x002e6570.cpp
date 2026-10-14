// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 2/2)
// FUN_002e6570 @ 0x002e6570
typedef unsigned int uint;
extern void* __cdecl FUN_0008d6d0(uint size);
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
    uint state;
    uint count;
    void* first;
    void* second;
    void* third;
    Language(const char* text, uint n, uint bytes);
};
Language::Language(const char* text, uint n, uint bytes) : FUN_0027b070() {
    flag=0; state=0; count=n; first=0; second=0; third=0;
    if(text) ((StringPart*)(baseData+4))->FUN_0027b040(text);
    uint size=n*4;
    unsigned char* p=(unsigned char*)FUN_0008d6d0(size);
    first=p;
    for(uint i=0;i<size;++i) p[i]=0;
    p=(unsigned char*)FUN_0008d6d0(size);
    second=p;
    for(uint j=0;j<size;++j) p[j]=0;
    p=(unsigned char*)FUN_0008d6d0(bytes & ~1u);
    third=p;
    for(uint k=0;k<bytes;++k) p[k]=0;
}
}
