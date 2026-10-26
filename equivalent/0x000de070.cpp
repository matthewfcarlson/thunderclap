// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FEThings::vfunc_49 @ 0x000de070
#include "compat/ptr.h"
#include "gen/global.h"

struct Provider { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual const char* vfunc_8(); }; struct Receiver { virtual void vfunc_0(); virtual void vfunc_1(const char*, void*); };  
void FEThings::vfunc_49(hulk_intptr __p0) { void * value = (void *)__p0;
 Receiver* r = (*(Receiver * *)&this->f_2234); if (!r) return; Provider* p = (*(Provider * *)&this->f_175c); if (!p) { r->vfunc_1("none", value); return; } const char* text = p->vfunc_8(); (*(Receiver * *)&this->f_2234)->vfunc_1(text, value); }
