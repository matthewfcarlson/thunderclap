struct Obj { char pad[0x14]; int value; };
Obj* __cdecl FUN_0034bd03();
void __cdecl FUN_0034773f(int param_1) {
    Obj* p = FUN_0034bd03();
    p->value = param_1;
}