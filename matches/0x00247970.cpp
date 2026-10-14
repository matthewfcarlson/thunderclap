class Obj_247970 {
  public:
    char pad[0x30];
    int state;
    char pad2[4];
    int value;
};
void f(Obj_247970* self, int value) {
    if (self->state == 1 || self->state == 0) {
        self->state = 3;
        self->value = value;
    }
}