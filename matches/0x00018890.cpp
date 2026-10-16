class Obj {
  public:
    virtual void f();
    virtual void release();
};
struct Holder {
    Obj* p;
};
void __cdecl FUN_00018890(Holder* h) {
    if (h->p) {
        h->p->release();
        h->p = 0;
    }
}