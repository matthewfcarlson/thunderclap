// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0610 @ 0x001e0610
struct Params { unsigned int a,b,c,d,e; };
struct Obj { void FUN_001e0610(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); };
typedef void (Obj::*Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl target(Obj* object, const Params* values, void* unused, Callback callback)
{
    (object->*callback)(values->a, values->b, values->c, values->d, values->e);
}
