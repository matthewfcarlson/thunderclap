// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// pure3d::pddiBaseContext::vfunc_101 @ 0x0031f190
void* __cdecl FUN_0008d690(unsigned int);
struct StackA { char pad[8]; unsigned int index; char* data; StackA* FUN_0031ed40(int); };
struct StackB { char pad[8]; unsigned int index; char* data; StackB* FUN_0031ee00(int); };
struct StackC { char pad[8]; unsigned int index; char* data; StackC* FUN_0031eef0(int); };
struct StackD { char pad[8]; unsigned int index; char* data; StackD* FUN_0031efd0(int); };
struct StackE { char pad[8]; unsigned int index; char* data; StackE* FUN_0031f0a0(int); };
namespace pure3d { struct pddiBaseContext { char pad[0x34]; StackA* a; StackB* b; StackC* c; StackD* d; StackE* e; char* topA; char* topB; char* topC; char* topD; char* topE; void vfunc_101(); }; }
void pure3d::pddiBaseContext::vfunc_101() {
 StackA* aa = (StackA*)FUN_0008d690(16); if(aa) aa = aa->FUN_0031ed40(4); a = aa; topA = aa->data + aa->index * 0x34;
 StackB* bb = (StackB*)FUN_0008d690(16); if(bb) bb = bb->FUN_0031ee00(4); b = bb; topB = bb->data + bb->index * 0x1c;
 StackC* cc = (StackC*)FUN_0008d690(16); if(cc) cc = cc->FUN_0031eef0(4); c = cc; topC = cc->data + cc->index * 0x3ec;
 StackD* dd = (StackD*)FUN_0008d690(16); if(dd) dd = dd->FUN_0031efd0(4); d = dd; topD = dd->data + dd->index * 20;
 StackE* ee = (StackE*)FUN_0008d690(16); if(ee) ee = ee->FUN_0031f0a0(4); e = ee; topE = ee->data + ee->index * 36;
}