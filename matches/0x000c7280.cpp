extern "C" void _ReadWriteBarrier();
extern void* gV[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct S {
    char c[0x20];
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x14 - 4];
    Ref* refs[9][2];
    char pad2[0x70 - 0x5c];
    S arr[16];
    ~Obj();
};
Obj::~Obj() {
    vptr = gV;
    _ReadWriteBarrier();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 2; j++)
            if (refs[i][j]) {
                refs[i][j]->Release();
                refs[i][j] = 0;
            }
    S* p = arr + 16;
    int n = 16;
    do {
        --p;
        p->Fini();
    } while (--n);
    Fin();
}
