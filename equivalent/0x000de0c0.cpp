// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FEThings::vfunc_48 @ 0x000de0c0
#include "gen/global.h"

#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

struct Selector { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual int vfunc_8(); };
struct Destination { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, int); };

void FEThings::vfunc_48(int value) { if (!(*(Destination * *)&this->f_2234)) return; if (!(*(Selector * *)&this->f_175c)) { (*(Destination * *)&this->f_2234)->vfunc_2((hulk_intptr)DAT_003f3f30, value); return; } int key = (*(Selector * *)&this->f_175c)->vfunc_8(); (*(Destination * *)&this->f_2234)->vfunc_2(key, value); }
