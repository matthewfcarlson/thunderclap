// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FEThings::vfunc_48 @ 0x000de0c0
#include "decls/data/game/unknown.h"

struct Selector { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual int vfunc_8(); };
struct Destination { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, int); };
class FEThings { public: char pad0[0x175c]; Selector* selector; char pad1[0x2234-0x1760]; Destination* destination; void vfunc_48(int value); };
void FEThings::vfunc_48(int value) { if (!destination) return; if (!selector) { destination->vfunc_2((int)DAT_003f3f30, value); return; } int key = selector->vfunc_8(); destination->vfunc_2(key, value); }