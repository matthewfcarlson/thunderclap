// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002e6570..0x002e6780 (kind game, layer engine, confidence medium), dominant class pure3d::Language
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f6a40e3d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6a40e3d {} using namespace fn_f6a40e3d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f6a40e3d {
typedef unsigned int uint_2e6570;
extern "C" void* __cdecl FUN_0008d6d0(uint_2e6570 size);
struct FUN_0027b070 {
    FUN_0027b070();
    virtual void baseSlot_00038290();
    char baseData[12];
};
struct StringPart { void FUN_0027b040(const char* text); };
namespace pure3d {
class Language : public FUN_0027b070 {
  public:
    virtual void m_vf1_000382a0();
    virtual Language* vfunc_2(int flag);
    virtual void m_vf3_0027afe0();
    virtual void m_vf4_0027aff0();
    Language(const char* text, uint_2e6570 n, uint_2e6570 bytes);
    unsigned char flag;
    char _m_pad_11[0x3];
    uint_2e6570 state;
    uint_2e6570 count;
    union { void* first; void* x; };
    union { void* second; void* y; };
    union { void* third; void* z; };
    void finish_0027afd0();
};
}
extern "C" char DAT_0042fd84[];
void __cdecl Release_0008d340(void*);
class Entity_2e6620 {
  public:
    ~Entity_2e6620();
};
class Language : public Entity_2e6620 {
  public:
    ~Language();
    char pad[0x1c];
    void* a;
    void* b;
    void* c;
};
class Hash {
  public:
    char pad[0x14];
    unsigned int divisor;
    unsigned int Calc(const char* s);
};
void release_0008d340(void*);
void destroy_00263f30(void*);
typedef int(__cdecl* CompareFn_2e6740)(const void*, const void*);
} // namespace fn_f6a40e3d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl bsearch(const void*, const void*, unsigned int, unsigned int, CompareFn_2e6740);
#endif
namespace fn_f6a40e3d {
extern "C" int __cdecl Compare(const void*, const void*);
class Container_2e6740 {
  public:
    char pad[0x18];
    int count;
    int* items;
    int Find(int key);
};


// 0x002e6570 FUN_002e6570 (172 B): equivalent/0x002e6570.cpp
// sym: ??0Language@pure3d@fn_f6a40e3d@@QAE@PBDII@Z @359c35f2016f @w2bcde4c23b70
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 2/2)
// FUN_002e6570 @ 0x002e6570
namespace pure3d {
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


// 0x002e6620 FUN_002e6620 (47 B): matches/0x002e6620.cpp
// sym: ??1Language@fn_f6a40e3d@@QAE@XZ
Language::~Language() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042fd84);
    Release_0008d340(a);
    Release_0008d340(b);
    Release_0008d340(c);
}


// 0x002e6650 FUN_002e6650 (44 B): matches/0x002e6650.cpp
// sym: ?Calc@Hash@fn_f6a40e3d@@QAEIPBD@Z
unsigned int Hash::Calc(const char* s) {
    unsigned int h = 0;
    char c = *s;
    while (c) {
        h = (h * 64 + c) % divisor;
        c = *++s;
    }
    return h;
}


// 0x002e66a0 FUN_002e66a0 (25 B): matches/0x002e66a0.cpp
// sym: ?FUN_002e66a0@fn_f6a40e3d@@YAIPAI0@Z
unsigned int FUN_002e66a0(unsigned int* a, unsigned int* b) {
    if (*a < *b)
        return 0xffffffff;
    return (unsigned int)(*b < *a);
}


// 0x002e66c0 pure3d::Language::vfunc_2 (68 B): matches/0x002e66c0.cpp
// sym: ?vfunc_2@Language@pure3d@fn_f6a40e3d@@UAEPAV123@H@Z
pure3d::Language* pure3d::Language::vfunc_2(int flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042fd84);
    release_0008d340(x);
    release_0008d340(y);
    release_0008d340(z);
    finish_0027afd0();
    if (flag & 1)
        destroy_00263f30(this);
    return this;
}


// 0x002e6740 FUN_002e6740 (60 B): matches/0x002e6740.cpp
// sym: ?Find@Container_2e6740@fn_f6a40e3d@@QAEHH@Z
int Container_2e6740::Find(int key) {
    int* base = items;
    int* end = base + count;
    int* p = (int*)bsearch(&key, base, (unsigned int)(end - base), 4, Compare);
    if (p)
        return (int)(p - items);
    return -1;
}

} // namespace fn_f6a40e3d
