typedef unsigned char byte;
extern char gData;
struct Sub1 { void m(); };
struct Sub2 { void m(); };
struct Sub3 { void m(); };
void __cdecl f4(void*, void*);
struct SeqEventCrossFade {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventCrossFade* vfunc_4(byte p);
    char pad[0x2c - 4];
};
SeqEventCrossFade* SeqEventCrossFade::vfunc_4(byte p) {
    reinterpret_cast<Sub1*>((char*)this + 0x2c)->m();
    reinterpret_cast<Sub2*>((char*)this + 0x1c)->m();
    reinterpret_cast<Sub3*>(this)->m();
    if (p & 1) f4(&gData, this);
    return this;
}
