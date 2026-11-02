typedef unsigned int uint_220bd0;
struct Obj_220bd0 {
    char pad[12];
    void* p;
};
struct Inner_220bd0 {
    char pad[8];
    int value;
};
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
extern "C" int FUN_00220bd0(void * a, unsigned int b, int c, unsigned int d, unsigned int e) {
    return FUN_00220b20((Obj_220bd0 *)((Obj_220bd0 *)a), ((c << 9 | d) << 9 | e) << 6 | b, (int)(*(int*)((char*)((Obj_220bd0 *)a)->p + 8)));
}