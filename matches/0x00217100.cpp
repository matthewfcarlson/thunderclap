extern "C" void __cdecl FUN_002164b0(void*, int);
struct Obj { char pad[0x38]; int field; };
struct Holder { char pad[0x10]; Obj* obj; };
void __cdecl FUN_00217100(Holder* a, unsigned char* b, int c) {
    Obj* p = a->obj;
    if (p->field != 0) { b[5] &= 0xfb; return; }
    FUN_002164b0(p, c);
}