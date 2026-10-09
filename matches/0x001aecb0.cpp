struct Src {
    int a;
    int b;
};
struct Obj {
    char pad[0x10];
    int a;
    int b;
};
struct Out {
    Obj* o;
    void* t;
};
extern int __stdcall Make(void (*)(), Src*);
extern void* __cdecl Alloc(unsigned int);
void CallbackA();
void CallbackB();
class T {
  public:
    void Reg(Obj*, void (*)(), int);
    void Run(Out* out, Src* s);
};
void T::Run(Out* out, Src* s) {
    int r = Make(CallbackA, s);
    if (!r) {
        out->o = 0;
        out->t = 0;
        return;
    }
    Obj* p = (Obj*)Alloc(0x18);
    Obj* o;
    if (p) {
        p->a = s->a;
        p->b = s->b;
        o = p;
    } else
        o = 0;
    Reg(o, CallbackB, r);
    out->t = this;
    out->o = o;
}