extern "C" char DAT_00413738[];
typedef unsigned char u8_148320;
class GrappleExecuteTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual GrappleExecuteTrack* vfunc_5(u8_148320);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    char pad[0x2c];
};
struct Sub_148320 {
    char pad[0x24];
};
void __fastcall initA(Sub_148320*);
void __fastcall initB(void*);
void __fastcall initC(GrappleExecuteTrack*);
void __cdecl destroyThing(GrappleExecuteTrack*);
GrappleExecuteTrack* GrappleExecuteTrack::vfunc_5(u8_148320 param) {
    Sub_148320* p = (Sub_148320*)((char*)this + 0x24);
    *(int*)this = ((int)DAT_00413738);
    initA(p);
    initB((char*)this + 0x14);
    initC(this);
    if (param & 1)
        destroyThing(this);
    return this;
}
