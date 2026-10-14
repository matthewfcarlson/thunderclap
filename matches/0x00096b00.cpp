struct Helper_96b00 {
    char pad[8];
    bool Check(void*);
};
struct Obj_96b00 {
    char pad0[8];
    Helper_96b00* helper;
    int state;
    char pad10[0x40];
    int a;
    int b;
    int c;
};
void __cdecl Target(Obj_96b00* self, int* out) {
    int n = self->state;
    --n;
    if (n != 0) {
        out[0] = self->a;
        out[1] = self->b;
        out[2] = self->c;
        return;
    }
    if (!self->helper->Check(out)) {
        out[0] = self->a;
        out[1] = self->b;
        out[2] = self->c;
    }
}