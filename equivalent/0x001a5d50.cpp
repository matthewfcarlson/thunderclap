// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_001a5d50 @ 0x001a5d50
struct Resource {
 virtual void unused();
 virtual void release();
 void FUN_0003dd00(int);
 void FUN_00222b90(int);
 void FUN_00222970(Resource*, int);
 void FUN_00298f90(int);
};
struct Manager {
 int FUN_00024230(Resource*);
 void FUN_0002a4b0(int,int);
};
struct Context { char pad[0x20]; Manager* manager; };
extern Context* DAT_004dd700;
struct Owner {
 unsigned char active, attached, flag2, flag3;
 Resource *first, *second, *third, *fourth, *fifth;
 void FUN_001a5d50();
};
void Owner::FUN_001a5d50() {
 if (!active) return;
 if (third) {
  third->FUN_0003dd00(0);
  int handle = DAT_004dd700->manager->FUN_00024230(third);
  if (third) { third->release(); third=0; }
  if (attached) {
   DAT_004dd700->manager->FUN_0002a4b0(handle,1);
   second->FUN_00222b90(1);
  }
 }
 if (flag3) fourth->FUN_00298f90(0);
 if (second) second->FUN_00222970(first,1);
 if (first) { first->release(); first=0; }
 if (second) { second->release(); second=0; }
 if (fourth) { fourth->release(); fourth=0; }
 if (fifth) { fifth->release(); fifth=0; }
 active=0; attached=0; flag2=0; flag3=0;
}
