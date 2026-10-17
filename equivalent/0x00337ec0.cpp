// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00337ec0 @ 0x00337ec0
struct Object { char pad[8]; unsigned int kind; int FUN_00337ec0(); }; int Object::FUN_00337ec0() { switch (kind) { case 0: return 1; case 1: case 3: return 16; case 2: case 5: case 7: case 9: return 8; case 4: return 4; case 6: case 8: return 12; default: return 0; } }