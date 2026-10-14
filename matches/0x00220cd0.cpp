struct Obj_220cd0 {
    char pad0[0xc];
    int* p;
    char pad10[0x10];
    int value;
};
int __cdecl FUN_00220b20(Obj_220cd0*, int, int);
void __cdecl FUN_002207c0(Obj_220cd0*, int*, int);
int __cdecl FUN_00220cd0(Obj_220cd0* self) {
    int old = self->value;
    self->value = -1;
    int result = FUN_00220b20(self, 0x7fff94, self->p[2]);
    FUN_002207c0(self, &result, old);
    return result;
}