// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// pure3d::ShadowSkin::vfunc_10 @ 0x002df2c0
// pure3d::ShadowSkin::vfunc_10 @ 0x002df2c0
namespace pure3d { struct ShadowSkin { char pad[0x48]; struct Link { struct Value { void FUN_002b57a0(int); } *value; } *link; void vfunc_10(int); }; }
void pure3d::ShadowSkin::vfunc_10(int a0) { link->value->FUN_002b57a0(a0); }
