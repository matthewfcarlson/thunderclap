// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d8cd0 @ 0x001d8cd0
struct Resource_1d8cd0 { virtual void slot0(); virtual void release(); };
struct Manager_1d8cd0 { void FUN_00029c00(unsigned int handle); };
struct Globals_1d8cd0 { char pad[0x20]; Manager_1d8cd0* manager; };
extern Globals_1d8cd0* DAT_004dd700;
struct Handle_1d8cd0 { char pad[0x10]; unsigned int value; };
struct Object {
 char pad0[0xa0]; Handle_1d8cd0* handle;
 char pad1[0x1fc-0xa4];
 Resource_1d8cd0* resource1;
 unsigned int x200, x204, x208, x20c, x210, x214, x218;
 Resource_1d8cd0* resource2;
 unsigned int x220, x224, x228, x22c, x230, x234;
 Resource_1d8cd0* resource3;
 void FUN_001d8100();
 void FUN_001d8cd0();
};
void Object::FUN_001d8cd0() {
 if (DAT_004dd700 && DAT_004dd700->manager) {
  DAT_004dd700->manager->FUN_00029c00(handle ? handle->value : 0);
 }
 if(resource1) { resource1->release(); resource1=0; }
 x208=0; x204=0; x200=0;
 x214=0; x210=0; x20c=0; x218=0;
 FUN_001d8100();
 if(resource2) { resource2->release(); resource2=0; }
 x220=0; x224=0; x228=0; x22c=0; x234=0;
 if(resource3) { resource3->release(); resource3=0; }
}
