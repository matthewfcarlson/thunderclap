// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00068410 @ 0x00068410
struct Object { char pad[0x20]; unsigned int flags; bool FUN_00068410(bool enabled); }; bool Object::FUN_00068410(bool enabled) { if (enabled) flags |= 1; else flags &= ~1u; return true; }