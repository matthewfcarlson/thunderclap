// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 20/20)
// pure3d::CompositeDrawable::vfunc_6 @ 0x00298b30
namespace pure3d {
struct Drawable {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned arg, unsigned flag);
 unsigned char FUN_00284ae0();
};
struct State_298b30 { void FUN_00284820(unsigned); };
struct Entry_298b30 { unsigned a,b; Drawable* drawable; };
struct Hierarchy_298b30 { char pad[0x20]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Entry_298b30* entries; };
struct Alternate { char pad[8]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Drawable** entries; };
struct CompositeDrawable : Drawable {
 char pad[0x3c]; State_298b30* state; Hierarchy_298b30* hierarchy; Alternate* alternate; Drawable* first; Drawable* second;
 virtual void vfunc_6(unsigned arg, unsigned flag);
};
void CompositeDrawable::vfunc_6(unsigned arg, unsigned flag) {
 if (!alternate) {
  unsigned count = hierarchy->count;
  for(unsigned i=0;i<count;++i) hierarchy->entries[hierarchy->indices[i]].drawable->vfunc_6(arg,flag);
  if(first) first->vfunc_6(arg,flag);
  if(second) second->vfunc_6(arg,flag);
 } else {
  unsigned count=alternate->count;
  for(unsigned i=0;i<count;++i) alternate->entries[alternate->indices[i]]->vfunc_6(arg,flag);
 }
 if(first) {
  unsigned char enabled=first->FUN_00284ae0();
  if(enabled==1 || (unsigned char)flag==1) state->FUN_00284820(0);
 }
}
}
