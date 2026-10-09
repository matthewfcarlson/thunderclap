typedef unsigned int uint;
int FUN_0024c310(int);
int FUN_0024c2f0(void*);
struct Base { virtual void f0(); virtual void f1(); virtual int f2(); };
struct HalRadicalAdpcmDecodeStream { virtual void v0(); virtual void v1(); virtual void v2(); virtual uint v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); Base* member4; uint vfunc_3(); };
uint HalRadicalAdpcmDecodeStream::vfunc_3() {
    uint a = member4->f2();
    uint b = FUN_0024c310(a);
    void* p = (char*)this + 8;
    uint c = FUN_0024c2f0(p);
    uint d = FUN_0024c310((int)p);
    return c * b / d;
}