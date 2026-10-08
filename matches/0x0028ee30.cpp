typedef unsigned int u32;
struct Receiver { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(u32,u32); };
struct ShaderIntBroadcast { char pad[8]; u32 mA; u32 mB; int vfunc_3(void* param); };
int ShaderIntBroadcast::vfunc_3(void* param) {
    if (param) {
        Receiver* r = *(Receiver**)((char*)param + 0x10);
        r->f6(mA, mB);
    }
    return (int)param;
}
