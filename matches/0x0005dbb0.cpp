extern void* gA[];
struct S {
    int a;
    void Fini();
};
struct T {
    int a;
    void Fini();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x18 - 4];
    S s18;
    char pad2[0x34 - 0x1c];
    T t34;
    char pad3[0x40 - 0x38];
    T t40;
    ~Obj();
};
Obj::~Obj() {
    vptr = gA;
    t40.Fini();
    t34.Fini();
    s18.Fini();
    Fin();
}
