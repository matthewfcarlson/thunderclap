typedef unsigned int u32;
extern void* __cdecl operator_new(unsigned int);
class ShieldArcTrack { public: virtual void A(); virtual void B(); virtual void C(); virtual void D(); virtual void E(); u32 pad; void Init(); };
class Factory { public: virtual void A(); virtual void B(); virtual void C(); virtual void D(); virtual void E(); virtual ShieldArcTrack* Create(); };
ShieldArcTrack* Factory::Create() {
    ShieldArcTrack* p = (ShieldArcTrack*)operator_new(0x14);
    if (p) {
        p->Init();
        *(u32*)p = 0x4194dc;
        *(u32*)((char*)p + 0xc) = 0;
        *(u32*)((char*)p + 0x10) = 0x3fc90fdb;
        *(u32*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}