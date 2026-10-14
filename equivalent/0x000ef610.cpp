// STATUS: equivalent (tools/equiv.py level 3: 2985 inputs, branch coverage 20/20)
// FUN_000ef610 @ 0x000ef610
struct TimerState { int state; bool FUN_000fb4b0(float dt); };
struct Entry_ef610 { char pad[0xe0]; TimerState timer; };
struct Context { char pad[0x17f8]; int flag; };
extern float (__fastcall *DAT_004de948)(void*);
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual Context* context();
 char pad0[0x448]; Entry_ef610* entries[128]; char pad1[0x42c]; int mode; float elapsed; float limit1False,limit1True,limit2False,limit2True;
 void FUN_000e54d0(); bool target();
};
bool Object::target() {
 volatile union { unsigned int word; unsigned char bytes[4]; } ready;
 ready.word=(unsigned int)this;
 ready.bytes[3]=1;
 void* timerContext=this;
 for(int i=0;i<128;++i) {
  Entry_ef610* entry=entries[i]; if(!entry) break;
  if(entry->timer.state==2) {
   float dt=DAT_004de948(timerContext);
   if(entry->timer.FUN_000fb4b0(dt)) ready.bytes[3]=0;
   timerContext=&entry->timer;
  }
 }
 int flag=context()->flag;
 if(mode==1 || mode==2) {
  float limit=mode==1 ? (flag ? limit1True:limit1False) : (flag ? limit2True:limit2False);
  if(ready.bytes[3] && limit<=elapsed) { FUN_000e54d0(); return false; }
 }
 elapsed=DAT_004de948((void*)flag)+elapsed;
 return true;
}
