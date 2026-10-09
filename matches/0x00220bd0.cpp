typedef unsigned int uint;
struct Obj {
    char pad[12];
    void* p;
};
struct Inner {
    char pad[8];
    int value;
};
void FUN_00220b20(Obj*, uint, int);
void FUN_00220bd0(Obj* a, uint b, int c, uint d, uint e) {
    FUN_00220b20(a, ((c << 9 | d) << 9 | e) << 6 | b, *(int*)((char*)a->p + 8));
}