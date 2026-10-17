// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00099710 @ 0x00099710
struct Object { char pad[4]; unsigned flags; void FUN_00099710(); void FUN_00099470(unsigned); }; extern unsigned DAT_004dd700; void Object::FUN_00099710() { if (flags & 0x10) FUN_00099470(DAT_004dd700); }