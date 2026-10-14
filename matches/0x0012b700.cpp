extern void* g_vftable_12b700[];
struct Sub_12b700 {
    char c;
};
void __fastcall Fin(Sub_12b700*) throw();
class Base_12b700 {
  public:
    void* vptr;
    void Fin();
};
class Obj_12b700 : public Base_12b700 {
  public:
    char pad[0x1c];
    Sub_12b700 sub;
    void F();
    ~Obj_12b700() throw();
};
extern void __fastcall SubFini(Sub_12b700*) throw();
Obj_12b700::~Obj_12b700() throw() {
    vptr = g_vftable_12b700;
    SubFini(&sub);
    Fin();
}
