// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_002495e0 @ 0x002495e0
// FUN_002495e0 @ 0x002495e0
struct Object { char pad[24]; char data; };
int __cdecl FUN_00248bf0(void *);
int __cdecl FUN_002495e0(Object *object) {
    return FUN_00248bf0(&object->data);
}
