struct Obj_2d6c90 {
    char pad[0x108];
    int value;
};
extern "C" int __cdecl FUN_002e6c80(int, int, int);
extern "C" void __cdecl FUN_002d6c90(void * self) {
    ((Obj_2d6c90 *)self)->value = FUN_002e6c80(0, 0, 0);
}