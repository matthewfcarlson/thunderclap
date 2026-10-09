struct Obj { char pad[0x108]; int value; };
extern int __cdecl FUN_002e6c80(int, int, int);
void __cdecl FUN_002d6c90(Obj* self) { self->value = FUN_002e6c80(0,0,0); }