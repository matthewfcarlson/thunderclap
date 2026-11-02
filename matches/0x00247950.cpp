class C_247950 {
    char pad[0x30];

  public:
    int state;
    char pad2[4];
    int value;
};
extern "C" void FUN_00247950(C_247950* self, int value) {
    if (self->state == 3 || self->state == 2) {
        self->state = 1;
        self->value = value;
    }
}