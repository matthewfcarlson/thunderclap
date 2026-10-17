// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024b080 @ 0x0024b080
struct Object { char pad[8]; int value; };
int __cdecl FUN_00258c80(int value);
int __cdecl FUN_0024b080(Object* object) {
    return FUN_00258c80(object->value);
}
