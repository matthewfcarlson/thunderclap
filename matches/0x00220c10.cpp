typedef unsigned int uint_220c10;
struct Obj_220c10 {
    char pad[12];
    struct Inner_220c10* p;
};
struct Inner_220c10 {
    char pad[8];
    int value;
};
void FUN_00220b20(Obj_220c10*, uint_220c10, int);
void FUN_00220c10(Obj_220c10* a, uint_220c10 b, int c, uint_220c10 d) {
    FUN_00220b20(a, (c << 18 | d) << 6 | b, a->p->value);
}
