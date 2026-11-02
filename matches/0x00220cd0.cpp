struct Obj_220cd0 {
    char pad0[0xc];
    int* p;
    char pad10[0x10];
    int value;
};
extern "C" int __cdecl FUN_00220b20(void *, unsigned int, unsigned int);
void __cdecl FUN_002207c0(Obj_220cd0*, int*, int);
extern "C" int __cdecl FUN_00220cd0(void * self) {
    int old = ((Obj_220cd0 *)self)->value;
    ((Obj_220cd0 *)self)->value = -1;
    int result = FUN_00220b20((Obj_220cd0 *)((Obj_220cd0 *)self), 0x7fff94, (int)(((Obj_220cd0 *)self)->p[2]));
    FUN_002207c0(((Obj_220cd0 *)self), &result, old);
    return result;
}