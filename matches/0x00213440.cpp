class Obj_213440 {
  public:
    char pad[0x10];
    void* state;
};
struct State_213440 {
    char pad[0x48];
    unsigned int a;
    unsigned int b;
};
void __cdecl helper1(Obj_213440*);
void __cdecl helper2(Obj_213440*, int, int);
void __cdecl target(Obj_213440* self, int x, int y) {
    State_213440* s = (State_213440*)self->state;
    if (s->b >= s->a)
        helper1(self);
    helper2(self, x, y);
}