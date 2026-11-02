typedef unsigned int uint_220c10;
struct Obj_220c10 {
    char pad[12];
    struct Inner_220c10* p;
};
struct Inner_220c10 {
    char pad[8];
    int value;
};
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
extern "C" int FUN_00220c10(void * a, unsigned int b, int c, unsigned int d) {
    return FUN_00220b20((Obj_220c10 *)((Obj_220c10 *)a), (c << 18 | d) << 6 | b, (int)(((Obj_220c10 *)a)->p->value));
}
