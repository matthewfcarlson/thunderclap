struct Obj {
    char pad0[0xc];
    int* p;
    char pad10[0x10];
    int value;
};
int __cdecl FUN_00220b20(Obj*, int, int);
void __cdecl FUN_002207c0(Obj*, int*, int);
int __cdecl FUN_00220cd0(Obj* self) {
    int old = self->value;
    self->value = -1;
    int result = FUN_00220b20(self, 0x7fff94, self->p[2]);
    FUN_002207c0(self, &result, old);
    return result;
}