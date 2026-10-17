// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00028ee0 @ 0x00028ee0
struct Obj;
struct Inner { Obj* FUN_000fdc40(); };
struct Obj { char pad[0x1ca0]; Inner* inner; };
struct Owner { Obj* FUN_00024280(unsigned int low, unsigned int high); unsigned int FUN_00028ee0(const char* name); };
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Final { unsigned int FUN_001034d0(); };
unsigned int Owner::FUN_00028ee0(const char* name) {
    __int64 id = FUN_002672f0(name, 0, 0);
    Obj* object = FUN_00024280((unsigned int)id, (unsigned int)(id >> 32));
    if (!object || !object->inner) return 0;
    Final* result = (Final*)object->inner->FUN_000fdc40();
    if (!result) return 0;
    return result->FUN_001034d0();
}