// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0024b0c0 @ 0x0024b0c0
struct Object { char pad[8]; void *value; };
int __cdecl FUN_00258cb0(void *, int);
int __cdecl FUN_0024b0c0(Object *object, int arg) {
    return FUN_00258cb0(object->value, arg);
}
