// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 2/2)
// pure3d::scenegraph::Scenegraph::vfunc_8 @ 0x00296160
#include "gen/pure3d.h"

#include "decls/data/engine/pure3d/prop.h"

struct Device {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(int); virtual void vfunc_16(int); virtual void vfunc_17(); virtual int vfunc_18(int);
};
struct Child {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(int, int, int);
};
namespace pure3d { namespace scenegraph {

}}
void pure3d::scenegraph::Scenegraph::vfunc_8(int a, int b) {
 if ((*(Child *volatile *)&this->f_40)) {
  (*(*(Device***)&DAT_0052c2ac))->vfunc_15(0);
  void **savedTable = *(void ***)(*(Child *volatile *)&this->f_40);
  typedef void (Child::*Method)(int, int, int);
  ((*(Child *volatile *)&this->f_40)->*(*(Method*)&savedTable[8]))((*(*(Device***)&DAT_0052c2ac))->vfunc_18(0), b, a);   // WRONG: a and b swapped
  (*(*(Device***)&DAT_0052c2ac))->vfunc_16(0);
 }
}
