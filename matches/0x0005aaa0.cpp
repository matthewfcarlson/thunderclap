extern void* gA_5aaa0[];
struct S_5aaa0 {
    int a;
    void Fini();
};
class Base_5aaa0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_5aaa0 : public Base_5aaa0 {
  public:
    char pad0[0x10 - 4];
    S_5aaa0 s10;
    char pad[4];
    S_5aaa0 s18;
    char pad2[0x40 - 0x1c];
    S_5aaa0 s40;
    ~Obj_5aaa0();
};
Obj_5aaa0::~Obj_5aaa0() {
    vptr = gA_5aaa0;
    s40.Fini();
    s18.Fini();
    s10.Fini();
    Fin();
}
