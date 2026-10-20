// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 4/4)
// COccupationAgent::vfunc_7 @ 0x00103790
#include "gen/global.h"

 struct AgentVtable { void *slots[8]; void (__fastcall *f8)(COccupationAgent *, void *, int); }; struct OccupationDisplay { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual int f6(const char *, unsigned int); char pad[0xe4]; unsigned char flag; }; struct OccupationOther { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(int); };  
void COccupationAgent::vfunc_7(int value) { if ((char)value) { AgentVtable *table = *(AgentVtable **)this; OccupationDisplay *d = (*(OccupationDisplay * *)&this->f_58); int result = d->f6(d->flag ? "Occ-L" : "Occ", d->flag ? 0xffffff00 : 0xffffffff); table->f8(this, 0, result); (*(OccupationOther * *)&this->f_5c)->f7(value); } (*(OccupationOther * *)&this->f_5c)->f7(value); }
