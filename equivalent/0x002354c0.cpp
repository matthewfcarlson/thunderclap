// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// fight::ParamValueNameList::vfunc_5 @ 0x002354c0
extern "C" int atexit(void (*)());

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};

extern unsigned DAT_004e5bd8;
extern Key DAT_004e5bd0;
void FUN_00364140();

class Sink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int a, int b, Key *k);
};

class ParamValueNameList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int a1, int a2, Sink *sink);
    virtual void v6();
    virtual Key *v7(int a1);
    int f4;
    int f8;
    int fc;
};

void ParamValueNameList::vfunc_5(int a1, int a2, Sink *sink)
{
    Key *k = v7(a1);
    if (k == 0) {
        if ((DAT_004e5bd8 & 1) == 0) {
            DAT_004e5bd8 |= 1;
            DAT_004e5bd0.FUN_0027af00();
            atexit(FUN_00364140);
        }
        k = &DAT_004e5bd0;
    }
    sink->v7(f8, fc, k);
}
