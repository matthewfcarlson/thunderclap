typedef unsigned int u32;
extern void* __cdecl Alloc(unsigned int);
extern int ComboVtable;
class CComboMessageTrack {
  public:
    void Init();
};
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* TrackFactory::vfunc_5() {
    CComboMessageTrack* p = (CComboMessageTrack*)Alloc(0x54);
    if (p) {
        p->Init();
        *(u32*)p = (u32)&ComboVtable;
        *(u32*)((char*)p + 0xc) = 0;
        *(u32*)((char*)p + 0x50) = 0;
        *((char*)p + 0x10) = 0;
        *(u32*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}