// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001f0f90 @ 0x001f0f90
struct Obj { void invoke(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
typedef void (Obj::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_001f0f90(Obj* obj, const unsigned* values, unsigned unused, Callback callback) {
    (obj->*callback)(values[0], values[1], values[2], values[3], values[4], values[5]);
}