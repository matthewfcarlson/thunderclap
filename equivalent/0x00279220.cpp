// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/16, incomplete)
// core::XboxSaveDrive::vfunc_18 @ 0x00279220
extern "C" void __cdecl FUN_0026b800(char *, int, const char *, int, int, int, int);
extern "C" void __stdcall FUN_00356611(int);
extern "C" int __stdcall FUN_003564c0(const char *, char *);
extern "C" void * __cdecl thunk_FUN_00271f20(void *, const void *, unsigned int);
struct Slot_279220 { char path[0x204]; int handle; };
struct XboxSaveDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
 virtual void vfunc_16(); virtual void vfunc_17();
 virtual int vfunc_18(const char *, const char *, int *, unsigned char);
 virtual int vfunc_19(int *, const char *);
 char pad[0xda]; unsigned char driveLetter; char pad2[0x11]; Slot_279220 slots[4];
 bool FUN_002788c0();
 int FUN_00278d30(const char *, char *, int, char *);
};
int XboxSaveDrive::vfunc_18(const char *name, const char *source, int *index, unsigned char reuse) {
 if (!FUN_002788c0()) return 0;
 char path[0x208]; char output[0x308];
 path[0]=driveLetter; path[1]=':'; path[2]='\\'; path[3]=0;
 FUN_0026b800(path+4,2,name,1,0,0x202,0);
 int slot=-1;
 if (!reuse && slots[*index].handle!=-1) {
  slot=*index;
  if (slots[slot].handle!=-1) { FUN_00356611(slots[slot].handle); slots[slot].handle=-1; }
 } else {
  for (unsigned i=0;i<4;i++) if (slots[i].handle==-1) { slot=i; break; }
 }
 Slot_279220 *s=&slots[slot];
 s->handle=FUN_003564c0(path,output);
 thunk_FUN_00271f20(s->path,path+4,0x202);
 *index=slot;
 int result=FUN_00278d30(source,output,s->handle,s->path);
 if (result==0) return 1;
 if (result==1) { s->handle=-1; return 0; }
 return vfunc_19(index,source);
}