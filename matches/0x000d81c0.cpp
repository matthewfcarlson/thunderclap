class Chain_d81c0 {
  public:
    Chain_d81c0* A();
    void B(int);
    int C(int, int);
    void D(int);
};
class Manager_d81c0 {
  public:
    Chain_d81c0* Get();
};
class Obj_d81c0 {
  public:
    char pad[0x150];
    Manager_d81c0* m;
};
int __fastcall target(Obj_d81c0* self, void*, int x, int y) {
    self->m->Get()->A()->B(x);
    int r = self->m->Get()->C(x, y);
    self->m->Get()->A()->D(x);
    return r;
}