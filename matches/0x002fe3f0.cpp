extern "C" char DAT_004319a4[];
struct Ref_2fe3f0 {
    virtual void a();
    virtual void release();
};
struct Obj_2fe3f0 {
    volatile unsigned vptr;
    char pad[0x84];
    Ref_2fe3f0* volatile ptr;
    void run();
};
extern void __fastcall FUN_002ef2c0(Obj_2fe3f0*);
void Obj_2fe3f0::run() {
    vptr = ((int)DAT_004319a4);
    Ref_2fe3f0* p = ptr;
    if (p) {
        p->release();
        ptr = 0;
    }
    FUN_002ef2c0(this);
}