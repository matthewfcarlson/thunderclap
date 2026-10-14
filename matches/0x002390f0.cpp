extern "C" char DAT_00428330[];
class Obj_2390f0 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8();
    virtual void F9();
    virtual void F10();
    virtual void F11();
    void Init();
};
class Track {
  public:
    virtual void T0();
    virtual void T1();
    virtual void T2();
    virtual void T3();
    virtual void T4();
    virtual void T5();
    virtual void T6();
    virtual void T7();
    virtual void T8();
    virtual void T9();
    virtual void T10();
    virtual void T11();
};
extern Obj_2390f0* __cdecl Alloc(int);
class PrintTrack : public Track {
  public:
    char pad[0x1c];
    Obj_2390f0* member;
    Obj_2390f0* vfunc_10(Obj_2390f0*, Obj_2390f0*, Obj_2390f0*);
};
Obj_2390f0* PrintTrack::vfunc_10(Obj_2390f0* a, Obj_2390f0* b, Obj_2390f0* p) {
    Obj_2390f0* q = Alloc(0x24);
    if (q) {
        q->Init();
        *(PrintTrack**)((char*)q + 0x1c) = this;
        *(unsigned int*)q = ((int)DAT_00428330);
        *(Obj_2390f0**)((char*)q + 0x20) = 0;
        if (p)
            p->F0();
        Obj_2390f0* old = *(Obj_2390f0**)((char*)q + 0x20);
        if (old)
            old->F1();
        *(Obj_2390f0**)((char*)q + 0x20) = p;
        return q;
    }
    return 0;
}