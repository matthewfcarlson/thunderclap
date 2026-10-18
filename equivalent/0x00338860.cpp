// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00338860 @ 0x00338860
// FUN_00338860 @ 0x00338860
struct Object { char pad[0x85a]; char field; int FUN_00338860(int value); };
int __stdcall FUN_00338710(int, void *, int);
int Object::FUN_00338860(int value) { return FUN_00338710(value, &field, 0); }
