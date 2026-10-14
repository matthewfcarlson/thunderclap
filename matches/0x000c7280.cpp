extern "C" void _ReadWriteBarrier();
extern void* gV[];
class Ref_c7280 {
  public:
    virtual void F0();
    virtual void Release();
};
struct S_c7280 {
    char c[0x20];
    void Fini();
};
class Base_c7280 {
  public:
    void* vptr;
    void Fin();
};
class Obj_c7280 : public Base_c7280 {
  public:
    char pad[0x14 - 4];
    Ref_c7280* refs[9][2];
    char pad2[0x70 - 0x5c];
    S_c7280 arr[16];
    ~Obj_c7280();
};
Obj_c7280::~Obj_c7280() {
    vptr = gV;
    _ReadWriteBarrier();
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 2; j++)
            if (refs[i][j]) {
                refs[i][j]->Release();
                refs[i][j] = 0;
            }
    S_c7280* p = arr + 16;
    int n = 16;
    do {
        --p;
        p->Fini();
    } while (--n);
    Fin();
}
