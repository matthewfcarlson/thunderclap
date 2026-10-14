class Obj_31a400 {
  public:
    void* v;
    void* x;
    char pad[0x98];
    int state;
};
void __fastcall FUN_0031a400(Obj_31a400* self) {
    self->x = self->v;
    if (self->state == 1)
        self->state = 2;
}