extern "C" char DAT_004e5e88[];
struct Obj {
    char pad[0x1c];
    unsigned int count;
};
void __cdecl F1(void*, Obj*);
void __cdecl F2(void*, Obj*);
void __cdecl Target(void* a, Obj* b) {
    if (b->count > 1) {
        --b->count;
        return;
    }
    F1(a, b);
    F2((void*)((int)DAT_004e5e88), b);
}