struct Obj {
    char pad[0x3c];
    unsigned int n;
};
extern "C" void __cdecl FUN_00267070(void*);
extern "C" void __cdecl FUN_00267090(void*);
void __cdecl FUN_001e8830(void* unused, Obj* obj, void* arg) {
    if (obj->n > 4)
        FUN_00267070(arg);
    else
        FUN_00267090(arg);
}