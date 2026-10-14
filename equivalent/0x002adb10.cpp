// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 4/4)
// FUN_002adb10 @ 0x002adb10
struct Output {
 virtual void init(int a, int count, int format, int zero1, int zero2);
 virtual void append(void* data);
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual int finish();
};
extern unsigned char __cdecl FUN_002d7f30(void*, int);
extern int __cdecl FUN_002d7ed0(void*, int);
extern int __cdecl FUN_002d7ef0(void*, int);
extern int __cdecl FUN_002d7eb0(void*, int);
extern void* __cdecl FUN_00266e00(int, int);
extern void __cdecl FUN_002d7440(void*, void*, int);
extern void __cdecl FUN_00266f00(int, void*);
// equiv-conv: FUN_002adb10 eax esi edi
int FUN_002adb10(int index, void* source, Output* output) {
 unsigned char type = FUN_002d7f30(source,index);
 int format = type == 6 ? 32 : 24;
 int a = FUN_002d7ed0(source,index);
 int count = FUN_002d7ef0(source,index);
 output->init(a,count,format,0,0);
 int size = FUN_002d7eb0(source,index);
 void* buffer = FUN_00266e00(1,size);
 for(int i=count; i>0; --i) {
  FUN_002d7440(source,buffer,0);
  output->append(buffer);
 }
 FUN_00266f00(1,buffer);
 volatile int result = output->finish();
 return result;
}