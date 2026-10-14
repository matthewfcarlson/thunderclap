extern "C" void __cdecl FUN_002164b0(void*, int);
struct Obj_217100 {
    char pad[0x38];
    int field;
};
struct Holder_217100 {
    char pad[0x10];
    Obj_217100* obj;
};
void __cdecl FUN_00217100(Holder_217100* a, unsigned char* b, int c) {
    Obj_217100* p = a->obj;
    if (p->field != 0) {
        b[5] &= 0xfb;
        return;
    }
    FUN_002164b0(p, c);
}