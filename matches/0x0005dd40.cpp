extern void* gA_5dd40[];
struct S_5dd40 {
    int a;
    void Fini();
};
class Base_5dd40 {
  public:
    void* vptr;
    void Fin();
};
class Obj_5dd40 : public Base_5dd40 {
  public:
    char pad[0x18 - 4];
    S_5dd40 s18;
    char pad2[0x38 - 0x1c];
    S_5dd40 s38;
    ~Obj_5dd40();
};
Obj_5dd40::~Obj_5dd40() {
    vptr = gA_5dd40;
    s38.Fini();
    s18.Fini();
    Fin();
}
