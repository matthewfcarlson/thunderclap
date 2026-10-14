class Thing_2d5090 {
  public:
    virtual void f0();
    virtual void f1();
};
extern void __cdecl thunk(int);
class Obj_2d5090 {
  public:
    Thing_2d5090* p;
    char pad[0x94];
    int x;
};
void __fastcall target(Obj_2d5090* self) {
    if (self->p) {
        self->p->f1();
        self->p = 0;
    }
    thunk(self->x);
}