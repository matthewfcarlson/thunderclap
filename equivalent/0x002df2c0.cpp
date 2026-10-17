// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// pure3d::ShadowSkin::vfunc_10 @ 0x002df2c0
namespace pure3d { struct ShadowSkin { char pad[0x48]; struct Link { struct Value { void FUN_002b57a0(); } *value; } *link; void vfunc_10(); }; }
void pure3d::ShadowSkin::vfunc_10() { link->value->FUN_002b57a0(); }