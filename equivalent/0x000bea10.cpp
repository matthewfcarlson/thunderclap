// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000bea10 @ 0x000bea10
struct Obj { void FUN_000bea10(int,int,int,int,int,int); };
void __cdecl FUN_000bea10(Obj *object, int *values, int unused, void (Obj::*callback)(int,int,int,int,int,int))
{
    (object->*callback)(values[0],values[1],values[2],values[3],values[4],values[5]);
}
