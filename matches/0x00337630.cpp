extern "C" const void* gVtbl[];

struct PtrObj {
  public:
    virtual void f(int);
};

struct Elem_337630 {
    void method();
    char data[0x288];
};

class Big_337630 {
  public:
    void Destroy();

  private:
    const void* slot0;
    char pad0[4];
    Elem_337630 mArray[32];
    int field5108;
    PtrObj* mPtr;
};

void Big_337630::Destroy() {
    slot0 = gVtbl;
    PtrObj* p = mPtr;
    if (p) {
        p->f(1);
    }
    Elem_337630* q = &mArray[32];
    for (int i = 0x20; i != 0; --i) {
        q -= 1;
        q->method();
    }
}
