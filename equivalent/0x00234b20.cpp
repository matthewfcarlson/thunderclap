// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// fight::ParamValueStringList::vfunc_5 @ 0x00234b20
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

class Reader {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual bool Read(int a, int b, char* dst, int size);
};

class ParamValueStringList {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(void* a, void* unused, Reader* reader);
    virtual bool f6(void* a, const char* text);
    int pad[1];
    int key0;
    int key1;
};

bool ParamValueStringList::vfunc_5(void* a, void* unused, Reader* reader) {
    char text[0x400] = "";
    unsigned int cookie = DAT_004d9968;
    bool ok = reader->Read(key0, key1, text, 0x400);
    if (ok)
        f6(a, text);
    __security_check_cookie(cookie);
    return ok;
}
