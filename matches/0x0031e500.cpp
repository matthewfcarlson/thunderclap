extern void* g_a_31e500[];
extern void* g_b_31e500[];
void operator delete(void*);
class Ref_31e500 {
  public:
    virtual void F0();
    virtual void Release();
};
class Item_31e500 {
  public:
    virtual ~Item_31e500();
};
class Big_31e500 {
  public:
    void Fin();
};
class Base_31e500 {
  public:
    void* vptr;
    void Fin();
};
class Obj_31e500 : public Base_31e500 {
  public:
    char pad[4];
    Ref_31e500* m8;
    Ref_31e500* mc;
    Ref_31e500* m10;
    char pad2[0xc];
    Item_31e500* arr[5];
    Item_31e500* m34;
    Item_31e500* m38;
    Item_31e500* m3c;
    Item_31e500* m40;
    Item_31e500* m44;
    char pad3[0x144 - 0x48];
    Big_31e500* m144;
    void f();
};
void Obj_31e500::f() {
    Ref_31e500* a = m10;
    vptr = g_a_31e500;
    a->Release();
    mc->Release();
    for (int i = 0; i < 5; i++)
        if (arr[i])
            delete arr[i];
    if (m34)
        delete m34;
    if (m38)
        delete m38;
    if (m3c)
        delete m3c;
    if (m40)
        delete m40;
    if (m44)
        delete m44;
    Big_31e500* p = m144;
    if (p) {
        p->Fin();
        operator delete(p);
    }
    vptr = g_b_31e500;
    Fin();
}
