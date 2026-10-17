// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002d6ea0 @ 0x002d6ea0
struct Object { char pad[0x210]; int value; };
int __cdecl FUN_002e6a50(int, int);
void __cdecl FUN_002d6d00(int);
int __cdecl FUN_002d6ea0(Object* object)
{
    if (!object) return 0;
    int result = FUN_002e6a50(2, object->value);
    if (result) FUN_002d6d00(result);
    return result;
}
