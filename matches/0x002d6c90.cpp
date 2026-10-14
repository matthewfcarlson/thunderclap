struct Obj_2d6c90 {
    char pad[0x108];
    int value;
};
extern int __cdecl FUN_002e6c80(int, int, int);
void __cdecl FUN_002d6c90(Obj_2d6c90* self) {
    self->value = FUN_002e6c80(0, 0, 0);
}