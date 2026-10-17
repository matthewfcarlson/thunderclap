// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f8b00 @ 0x000f8b00
struct Child { virtual void FUN_00000000(int); }; struct Object { virtual void FUN_00000000(); char pad[0x3c]; int value; char pad2[4]; Child *child; void FUN_000f8b00(int); }; void Object::FUN_000f8b00(int v) { value=v; if(child) child->FUN_00000000(v); FUN_00000000(); }