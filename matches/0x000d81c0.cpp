class Chain_d81c0 {
  public:
    Chain_d81c0* A();
    void B();
    int C();
    void D();
};
class Manager_d81c0 {
  public:
    Chain_d81c0* Get(int);
    Chain_d81c0* Get2(int, int);
};
class Obj_d81c0 {
  public:
    char pad[0x150];
    Manager_d81c0* m;
};
int __fastcall target(Obj_d81c0* self, void*, int x, int y) {
    Chain_d81c0* a = self->m->Get(x);
    a = a->A();
    a->B();
    Chain_d81c0* b = self->m->Get2(x, y);
    int r = b->C();
    a = self->m->Get(x);
    a = a->A();
    a->D();
    return r;
}