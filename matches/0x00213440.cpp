class Obj {
  public:
    char pad[0x10];
    void* state;
};
struct State {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void __cdecl helper1(Obj*);
void __cdecl helper2(Obj*, int, int);
void __cdecl target(Obj* self, int x, int y) {
    State* s = (State*)self->state;
    if (s->b >= s->a)
        helper1(self);
    helper2(self, x, y);
}