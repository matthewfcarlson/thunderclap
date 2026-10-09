struct Obj { char pad[0x1c]; int member; Obj* target(int flags); };
struct Helper { void call(); };
extern void __cdecl FUN_00247550(void*, Obj*);
Obj* Obj::target(int flags) {
    ((Helper*)&member)->call();
    if (flags & 1) FUN_00247550((void*)0x4e7898, this);
    return this;
}