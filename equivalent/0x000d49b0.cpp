// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 17/20, incomplete)
// FUN_000d49b0 @ 0x000d49b0
struct Vec_d49b0 {
 float x,y,z;
 bool FUN_0022d2b0(Vec_d49b0* other, float tolerance);
};
extern float DAT_004a06e4;
void __stdcall FUN_000d49b0(Vec_d49b0* target, Vec_d49b0* current) {
 if(current->FUN_0022d2b0(target, 0.00001f)) return;
 for(int i=0;i<3;++i) {
  float* a = i==0 ? &current->x : i==1 ? &current->y : &current->z;
  float* b = i==0 ? &target->x : i==1 ? &target->y : &target->z;
  double delta = (double)*b - (double)*a;
  float lower = -DAT_004a06e4;
  if (!(delta >= lower)) {
   if(delta > DAT_004a06e4) delta=DAT_004a06e4;
   else delta=lower;
  } else if (!(delta <= DAT_004a06e4)) delta=DAT_004a06e4;
  *a = (float)(delta + *a);
 }
}