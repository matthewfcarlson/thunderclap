class Thing {
  public:
    virtual void f0();
    virtual void f1();
};
extern void __cdecl thunk(int);
class Obj {
  public:
    Thing* p;
    char pad[0x94];
    int x;
};
void __fastcall target(Obj* self) {
    if (self->p) {
        self->p->f1();
        self->p = 0;
    }
    thunk(self->x);
}