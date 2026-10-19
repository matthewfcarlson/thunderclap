struct Src_1aecb0 {
    int a;
    int b;
};
struct Obj_1aecb0 {
    char pad[0x10];
    int a;
    int b;
};
struct Out_1aecb0 {
    Obj_1aecb0* o;
    void* t;
};
extern void* __cdecl Alloc(unsigned int);
void CallbackA();
void CallbackB();
class T_1aecb0 {
  public:
    void Reg(Obj_1aecb0*, void (*)(), int);
    int Make(void (*)(), Src_1aecb0*);
    void Run(Out_1aecb0* out, Src_1aecb0* s);
};
void T_1aecb0::Run(Out_1aecb0* out, Src_1aecb0* s) {
    int r = Make(CallbackA, s);
    if (!r) {
        out->o = 0;
        out->t = 0;
        return;
    }
    Obj_1aecb0* p = (Obj_1aecb0*)Alloc(0x18);
    Obj_1aecb0* o;
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