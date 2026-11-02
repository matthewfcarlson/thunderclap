class Obj {
  public:
    virtual void First();
    virtual void Second();
};

struct Holder {
    Obj* mOld;
};

extern "C" void FUN_00059c50(Holder* h, Obj* n) {
    if (n)
        n->First();
    if (h->mOld)
        h->mOld->Second();
    h->mOld = n;
}
