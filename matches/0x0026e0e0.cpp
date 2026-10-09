struct Obj {
    char pad10[0x10];
    char field10[1];
    char pad68[0x68 - 0x11];
    char field68[1];
    char padC0[0xc0 - 0x69];
    int state;
};
void cleanup(void*);
void __fastcall target(Obj* self) {
    int x = self->state;
    if (x == 3) {
        cleanup(&self->field68);
        self->state = 0;
    } else if (x == 1 || x == 2) {
        cleanup(&self->field10);
        cleanup(&self->field68);
        self->state = 0;
    }
}