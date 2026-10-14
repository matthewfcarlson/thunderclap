typedef unsigned int uint_220bd0;
struct Obj_220bd0 {
    char pad[12];
    void* p;
};
struct Inner_220bd0 {
    char pad[8];
    int value;
};
void FUN_00220b20(Obj_220bd0*, uint_220bd0, int);
void FUN_00220bd0(Obj_220bd0* a, uint_220bd0 b, int c, uint_220bd0 d, uint_220bd0 e) {
    FUN_00220b20(a, ((c << 9 | d) << 9 | e) << 6 | b, *(int*)((char*)a->p + 8));
}