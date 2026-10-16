// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0031f410 @ 0x0031f410
#include "decls/data/engine/pure3d/scenegraph.h"

struct Ref_31f410 { virtual void retain(); };
struct Matrix { unsigned data[16]; };
namespace pure3d { struct pddiBaseContext; }
struct Helper_31f410 { Helper_31f410* FUN_00328250(pure3d::pddiBaseContext*); };
extern Helper_31f410* __cdecl FUN_0008d690(unsigned);
struct FUN_0031bac0 { FUN_0031bac0(); virtual void baseSlot(); };
namespace pure3d {
struct pddiBaseContext : FUN_0031bac0 {
virtual void vfunc_0();
char pad4[8]; Ref_31f410* first; Ref_31f410* second;
unsigned state[18]; Matrix matrix; char pad9c[32]; unsigned bc,c0;
char padc4[56]; unsigned values[12]; char pad12c[24]; Helper_31f410* helper; unsigned char flag148,flag149;
void vfunc_100(); void vfunc_101(); void vfunc_103();
pddiBaseContext(Ref_31f410*,Ref_31f410*);
};
pddiBaseContext::pddiBaseContext(Ref_31f410* a,Ref_31f410* b) {
first=0;second=0;matrix=(*(Matrix*)&DAT_004c9f38);
helper=0;flag148=0;flag149=0;
first=a;a->retain();second=b;b->retain();
for(int j=0;j<18;++j) state[j]=0;
vfunc_100();vfunc_101();
Helper_31f410* h=FUN_0008d690(4);helper=h?h->FUN_00328250(this):0;
bc=0;c0=0;for(int k=0;k<12;++k) values[k]=0;
vfunc_103();
}
}
