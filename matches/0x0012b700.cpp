extern void* g_vftable[];
struct Sub {
    char c;
};
void __fastcall Fin(Sub*) throw();
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x1c];
    Sub sub;
    void F();
    ~Obj() throw();
};
extern void __fastcall SubFini(Sub*) throw();
Obj::~Obj() throw() {
    vptr = g_vftable;
    SubFini(&sub);
    Fin();
}
