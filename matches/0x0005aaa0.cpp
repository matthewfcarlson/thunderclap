extern void* gA[];
struct S {
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
    char pad0[0x10 - 4];
    S s10;
    char pad[4];
    S s18;
    char pad2[0x40 - 0x1c];
    S s40;
    ~Obj();
};
Obj::~Obj() {
    vptr = gA;
    s40.Fini();
    s18.Fini();
    s10.Fini();
    Fin();
}
