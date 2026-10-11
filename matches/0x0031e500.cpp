extern void* g_a[];
extern void* g_b[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Item {
  public:
    virtual ~Item();
};
class Big {
  public:
    void Fin();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[4];
    Ref* m8;
    Ref* mc;
    Ref* m10;
    char pad2[0xc];
    Item* arr[5];
    Item* m34;
    Item* m38;
    Item* m3c;
    Item* m40;
    Item* m44;
    char pad3[0x144 - 0x48];
    Big* m144;
    void f();
};
void Obj::f() {
    Ref* a = m10;
    vptr = g_a;
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
    Big* p = m144;
    if (p) {
        p->Fin();
        operator delete(p);
    }
    vptr = g_b;
    Fin();
}
