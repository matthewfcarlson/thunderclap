extern "C" char DAT_003f6098[];
extern "C" char DAT_00431700[];
class Ref {
  public:
    virtual void Release(int);
};
struct Obj {
    void* vptr;
    char pad[4];
    Ref* ref;
};
void __fastcall FUN_002f8820(Obj* p, void*) {
    p->vptr = (void*)((int)DAT_00431700);
    if (p->ref) {
        p->ref->Release(1);
        p->ref = 0;
    }
    p->vptr = (void*)((int)DAT_003f6098);
}