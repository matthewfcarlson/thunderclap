// STATUS: equivalent (tools/equiv.py level 3: 225 inputs, branch coverage 6/6)
// FUN_001f2c00 @ 0x001f2c00
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct InitObject { void FUN_001ea8b0(int); };
struct Owner { void FUN_001f6990(); };
struct StateData { char data[8]; void FUN_0027af00(); void FUN_0027b040(int); };
struct CSoundTriggerExecutionState {
 virtual void slot0();
 int references;
 int field8, fieldC, field10;
 unsigned char active;
 char pad[3];
 StateData state;
 float duration;
 int field24;
};
void* __cdecl FUN_0008d750(int,int);
struct Target {
 Owner* owner;
 InitObject* init;
 int field8;
 CSoundTriggerExecutionState* entries;
 void FUN_001f2730();
 void FUN_001f2c00(int arg);
};
void Target::FUN_001f2c00(int arg) {
 init->FUN_001ea8b0(arg);
 owner->FUN_001f6990();
 void* storage=FUN_0008d750(0xfa4,6);
 CSoundTriggerExecutionState* result=0;
 if(storage) {
  *((int*)storage)=100;
  result=(CSoundTriggerExecutionState*)((int*)storage+1);
  for(int i=0;i<100;++i) {
   new (&result[i]) CSoundTriggerExecutionState;
   result[i].references=1;
   result[i].state.FUN_0027af00();
   result[i].field8=0; result[i].fieldC=0; result[i].field10=0;
   result[i].active=0; result[i].duration=100.0f; result[i].field24=0;
   result[i].state.FUN_0027b040(0);
  }
 }
 entries=result;
 for(int j=0;j<100;++j) {
  CSoundTriggerExecutionState* p=entries+j;
  p->field8=0; p->fieldC=0; p->field10=0; p->active=0;
  p->duration=100.0f; p->field24=0;
  p->state.FUN_0027b040(0);
 }
 FUN_001f2730();
}
