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
    char pad[0x18 - 4];
    S s18;
    char pad2[0x38 - 0x1c];
    S s38;
    ~Obj();
};
Obj::~Obj() {
    vptr = gA;
    s38.Fini();
    s18.Fini();
    Fin();
}
