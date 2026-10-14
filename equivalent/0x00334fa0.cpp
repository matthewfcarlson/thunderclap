// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00334fa0 @ 0x00334fa0
struct Device_334fa0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(int);
};
extern void __cdecl FUN_00334960();
extern void __cdecl FUN_00334c70();
extern void __cdecl FUN_00334ef0();
extern void __cdecl FUN_00334f10();
extern void __cdecl FUN_00334c00();
extern void __cdecl FUN_00334f60();
struct State_334fa0 { void (__cdecl *callbacks[6])(); unsigned int reserved[13]; Device_334fa0* device; unsigned int rest[59]; };
extern void __cdecl thunk_FUN_00271230(Device_334fa0**,unsigned int,int,int,int,int,int,int);
int __stdcall FUN_00334fa0(State_334fa0* state,unsigned int arg,unsigned int unused) {
 unsigned int* words = reinterpret_cast<unsigned int*>(state);
 for(int i=0;i<79;++i) words[i]=0;
 thunk_FUN_00271230(&state->device,arg,0,0,1,0,1,1);
 state->device->v30(1);
 state->callbacks[0]=FUN_00334960;
 state->callbacks[1]=FUN_00334c70;
 state->callbacks[2]=FUN_00334ef0;
 state->callbacks[3]=FUN_00334f10;
 state->callbacks[4]=FUN_00334c00;
 state->callbacks[5]=FUN_00334f60;
 return 1;
}