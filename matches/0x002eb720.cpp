struct Val_2eb720 {
    char bytes[10];
};
struct Obj_2eb720 {
    char p0[8];
    int flags;
    char p1[10];
    short count;
    char p2[0x34];
    int data;
    Val_2eb720 val;
};
void F(void* p, Obj_2eb720* o, int data, int count, Val_2eb720* v) {
    if (!p || !o)
        return;
    if (data)
        o->data = data;
    if (v)
        o->val = *v;
    if (v && !count)
        count = 1;
    o->count = count;
    o->flags |= 0x10;
}