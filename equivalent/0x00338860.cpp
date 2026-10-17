// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00338860 @ 0x00338860
struct Object { char pad[0x85a]; char field; void FUN_00338860(int value); };
void __stdcall FUN_00338710(int, void *, int);
void Object::FUN_00338860(int value) { FUN_00338710(value, &field, 0); }