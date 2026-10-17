// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00012610 @ 0x00012610
struct Triple { unsigned int x, y, z; };
struct Object { char pad[0xb8]; Triple value; void FUN_00012610(Triple* result); };
void Object::FUN_00012610(Triple* result) { result->x = value.x; result->y = value.y; result->z = value.z; }