// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00204440 @ 0x00204440
struct Obj { char pad[0x5a4]; unsigned char flags[1024]; unsigned int FUN_00204440(int index); }; unsigned int Obj::FUN_00204440(int index) { if (index < 0 || index >= 1024) return (unsigned int)index & 0xffffff00u; unsigned char value = flags[index]; return value == 1 || value == 3; }