// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 21/26, incomplete)
// FUN_00086790 @ 0x00086790
struct Switch_86790 { void FUN_0008db60(int); };
struct Item_86790 { void FUN_000af0f0(void*); };
struct Source_86790 { void FUN_000ae840(); };
struct Input_86790 { void FUN_000af3c0(int); Item_86790* FUN_000af3a0(int); };
struct Pump_86790 { void FUN_000bd1b0(int); };
struct State_86790 { char pad[5]; unsigned char active; };
void FUN_002684c0();
State_86790* FUN_0008e090();
bool FUN_0008db80();
struct Renderer_86790 { char pad[0xd8]; int state; void FUN_0028f9a0(); void FUN_0028faf0(int); };
struct Manager_86790 { void FUN_000afe80(); };
struct Subsystem_86790 { char pad[0x18]; Manager_86790* manager; };
struct Root_86790 { char pad[0x54]; Subsystem_86790* subsystem; };
struct Animation { void FUN_001ec480(const char*,const char*); void FUN_001eb2a0(float,int); };
extern unsigned char DAT_004dd890, DAT_004dd841, DAT_004e222c, DAT_004e222d;
extern Renderer_86790* DAT_0052c2b4;
extern Root_86790* DAT_004dd700;
struct Object { char pad0[4]; int* result; char pad8[8]; Source_86790* source; Input_86790* input; char pad18[4]; Switch_86790* gate; Pump_86790* pump; char pad24[12]; Animation* animation; void FUN_00086790(); };
void Object::FUN_00086790() {
 gate->FUN_0008db60(1);
 if (!DAT_004dd890 && source && input) {
  bool done=false;
  while (!done) {
   FUN_002684c0();
   source->FUN_000ae840();
   input->FUN_000af3c0(0);
   if (!FUN_0008e090()->active || FUN_0008db80()) { gate->FUN_0008db60(0); return; }
   int data[41];
   input->FUN_000af3a0(0)->FUN_000af0f0(data);
   if (DAT_004dd841 || data[0]==1 || data[0]==2 || data[12]==1 || data[12]==2) done=true;
   pump->FUN_000bd1b0(1);
  }
 }
 for(int i=0;i<3;++i) {
  DAT_0052c2b4->state=-1;
  DAT_0052c2b4->FUN_0028f9a0();
  DAT_0052c2b4->FUN_0028faf0(1);
 }
 *result=4;
 DAT_004dd700->subsystem->manager->FUN_000afe80();
 DAT_004e222c=1;
 DAT_004e222d=1;
 animation->FUN_001ec480("start","poststart");
 animation->FUN_001eb2a0(0.01f,0);
 gate->FUN_0008db60(0);
}
