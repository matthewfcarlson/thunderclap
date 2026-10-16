// STATUS: equivalent (tools/equiv.py level 3: 2661 inputs, branch coverage 20/20)
// pure3d::CompositeDrawable::vfunc_6 @ 0x00298b30
#include "gen/pure3d.h"

namespace pure3d {
struct Drawable_298b30 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned arg, unsigned flag);
 unsigned char FUN_00284ae0();
};
struct State_298b30 { void FUN_00284820(unsigned); };
struct Entry_298b30 { unsigned a,b; Drawable_298b30* drawable; };
struct Hierarchy_298b30 { char pad[0x20]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Entry_298b30* entries; };
struct Alternate { char pad[8]; unsigned char count; char pad2[15]; unsigned char* indices; char pad3[8]; Drawable_298b30** entries; };
struct CompositeDrawable_nv_298b30 {
    unsigned char FUN_00284ae0();
};

}
void pure3d::CompositeDrawable::vfunc_6(int __p0, int __p1) { unsigned int arg = (unsigned int)__p0; unsigned int flag = (unsigned int)__p1;

 if (!(*(Alternate * *)&this->f_48)) {
  unsigned count = (*(Hierarchy_298b30 * *)&this->f_44)->count;
  for(unsigned i=0;i<count;++i) (*(Hierarchy_298b30 * *)&this->f_44)->entries[(*(Hierarchy_298b30 * *)&this->f_44)->indices[i]].drawable->vfunc_6(arg,flag);
  if((*(Drawable_298b30 * *)&this->f_4c)) (*(Drawable_298b30 * *)&this->f_4c)->vfunc_6(arg,flag);
  if((*(Drawable_298b30 * *)&this->f_50)) (*(Drawable_298b30 * *)&this->f_50)->vfunc_6(arg,flag);
 } else {
  unsigned count=(*(Alternate * *)&this->f_48)->count;
  for(unsigned i=0;i<count;++i) (*(Alternate * *)&this->f_48)->entries[(*(Alternate * *)&this->f_48)->indices[i]]->vfunc_6(arg,flag);
 }
 if((*(Drawable_298b30 * *)&this->f_4c)) {
  unsigned char enabled=((CompositeDrawable_nv_298b30*)((*(Drawable_298b30 * *)&this->f_4c)))->FUN_00284ae0();
  if(enabled==1 || (unsigned char)flag==1) (*(State_298b30 * *)&this->f_40)->FUN_00284820(0);
 }
}
