// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_101 @ 0x0031f190
#include "gen/pure3d.h"

void* __cdecl FUN_0008d690(unsigned int);
struct StackA { char pad[8]; unsigned int index; char* data; StackA* FUN_0031ed40(int); };
struct StackB { char pad[8]; unsigned int index; char* data; StackB* FUN_0031ee00(int); };
struct StackC { char pad[8]; unsigned int index; char* data; StackC* FUN_0031eef0(int); };
struct StackD { char pad[8]; unsigned int index; char* data; StackD* FUN_0031efd0(int); };
struct StackE { char pad[8]; unsigned int index; char* data; StackE* FUN_0031f0a0(int); };
namespace pure3d {  }
void pure3d::pddiBaseContext::vfunc_101() {
 StackA* aa = (StackA*)FUN_0008d690(16); if(aa) aa = aa->FUN_0031ed40(4); (*(StackA * *)&this->f_34) = aa; (*(char * *)&this->f_48) = aa->data + aa->index * 0x34;
 StackB* bb = (StackB*)FUN_0008d690(16); if(bb) bb = bb->FUN_0031ee00(4); (*(StackB * *)&this->f_38) = bb; (*(char * *)&this->f_4c) = bb->data + bb->index * 0x1c;
 StackC* cc = (StackC*)FUN_0008d690(16); if(cc) cc = cc->FUN_0031eef0(4); (*(StackC * *)&this->f_3c) = cc; (*(char * *)&this->f_50) = cc->data + cc->index * 0x3ec;
 StackD* dd = (StackD*)FUN_0008d690(16); if(dd) dd = dd->FUN_0031efd0(4); (*(StackD * *)&this->f_40) = dd; (*(char * *)&this->f_54) = dd->data + dd->index * 20;
 StackE* ee = (StackE*)FUN_0008d690(16); if(ee) ee = ee->FUN_0031f0a0(4); (*(StackE * *)&this->f_44) = ee; (*(char * *)&this->f_58) = ee->data + ee->index * 36;
}
