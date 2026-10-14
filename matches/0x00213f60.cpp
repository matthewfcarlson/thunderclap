struct Obj_213f60 {
    char pad[0x30];
    unsigned char flag;
    char gap[3];
    int a;
    int b;
    int c;
};
int target(Obj_213f60* self, int p2, int p3, int p4) {
    if (p2 == 0 || p3 == 0) {
        p3 = 0;
        p2 = 0;
    }
    self->c = p2;
    self->a = p4;
    self->b = p4;
    self->flag = (unsigned char)p3;
    return 1;
}