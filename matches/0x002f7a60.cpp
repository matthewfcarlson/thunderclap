struct Global {
    char pad[0x28];
    int a;
    char pad2[4];
    int b;
};
extern Global* g;
class Obj {
  public:
    char pad[0xe8];
    int a;
    int b;
};
void __fastcall target(Obj* self) {
    self->a = g->b;
    self->b = g->a;
}