#include "compat/ptr.h"
#include "gen/owners.h"
struct Sub_2c3930 {
    char p[8];
};
struct Entity_2c3930 {
    Entity_2c3930();
    virtual void h();
    int x;
    Sub_2c3930 s;
};
struct ILanguageChangeCallback_2c3930 {
    virtual void f();
};
extern "C" void* FUN_0008d6d0(hulk_uintptr);
struct TextBible : Entity_2c3930, ILanguageChangeCallback_2c3930 {
    virtual void g();
    int* mBegin;
    int* mEnd;
    int* mCap;
    int pad2;
    short mA;
    short mB;
    TextBible(int a, int n);
};
TextBible::TextBible(int a, int n) {
    mBegin = 0;
    mEnd = 0;
    mCap = 0;
    mA = -1;
    mB = 0;
    if (a)
        ((owners::Target_27b040 *)&s)->FUN_0027b040((hulk_uintptr)a);
    if (n) {
        mBegin = (int*)FUN_0008d6d0(n * 4);
        if (mBegin) {
            mCap = mBegin + n;
            mEnd = mBegin;
            return;
        }
    } else
        mBegin = 0;
    mEnd = 0;
    mCap = 0;
}