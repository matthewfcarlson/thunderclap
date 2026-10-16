// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// fight::ParamValueScript::vfunc_5 @ 0x00234c30
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x00267090
void* __cdecl FUN_00238190(int a);
char* __cdecl FUN_00266e00(void* heap, int size);
void __cdecl thunk_FUN_00267090(void* p);
class Stream {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual bool Read(int a, int b, char* buf, int len);
    virtual void s9(); virtual void s10(); virtual void s11();
    virtual bool Measure(int a, int b, int* len);
};
namespace fight { class ParamValueScript {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2, Stream* in);
    virtual void vfunc_6(int a1, char* text, int len);
    char pad[4];
    int f8, fc;
}; }
bool fight::ParamValueScript::vfunc_5(int a1, int, Stream* in) {
    int len = 0;
    if (!in->Measure(f8, fc, &len)) return false;
    char* buf = FUN_00266e00(FUN_00238190(1), len + 1);
    buf[0] = 0;
    bool ok = in->Read(f8, fc, buf, len + 1);
    if (ok)
        vfunc_6(a1, buf, len);
    thunk_FUN_00267090(buf);
    return ok;
}
