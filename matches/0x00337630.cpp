extern "C" const void* gVtbl[];

struct PtrObj {
  public:
    virtual void f(int);
};

struct Elem {
    void method();
    char data[0x288];
};

class Big {
  public:
    void Destroy();

  private:
    const void* slot0;
    char pad0[4];
    Elem mArray[32];
    int field5108;
    PtrObj* mPtr;
};

void Big::Destroy() {
    slot0 = gVtbl;
    PtrObj* p = mPtr;
    if (p) {
        p->f(1);
    }
    Elem* q = &mArray[32];
    for (int i = 0x20; i != 0; --i) {
        q -= 1;
        q->method();
    }
}
