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
    p->vptr = (void*)0x431700;
    if (p->ref) {
        p->ref->Release(1);
        p->ref = 0;
    }
    p->vptr = (void*)0x3f6098;
}