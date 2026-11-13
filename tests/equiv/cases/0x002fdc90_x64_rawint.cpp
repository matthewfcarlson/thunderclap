// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 6/6)
// FUN_002fdc90 @ 0x002fdc90
struct Source_2fdc90 { int FUN_0030f450(); };
struct Transform_2fdc90 { void FUN_0022b980(); char data[64]; };
struct Entry_2fdc90 { int a,b,c,d,e,f,g; unsigned char enabled; char pad[3]; Transform_2fdc90 transform; int last; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int bytes);
struct FUN_002ef7f0 {
 FUN_002ef7f0(int mode);   // (x64t7) SimState's constructor (0x002ef7f0) takes the mode word at 0x6c, an int (was a pointer)
 virtual void slot0();
 char base[128];
};
namespace physics {
struct SimStateArticulated : FUN_002ef7f0 {
 virtual void slot0();
 unsigned char enabled;
 char pad85[3];
 int field88;
 Entry_2fdc90* entries;
 int field90;
 unsigned char field94;
 void FUN_002fd8a0(Source_2fdc90* source);
 SimStateArticulated(Source_2fdc90* source, int mode);
};
}
physics::SimStateArticulated::SimStateArticulated(Source_2fdc90* source, int mode) : FUN_002ef7f0(mode) {
 field88=0; field90=0; field94=0; enabled=1;
 int count=source->FUN_0030f450();
 int* allocation=(int*)FUN_0008d6d0((unsigned int)count*100+4);
 Entry_2fdc90* result=0;
 if(allocation) {
  *allocation=count;
  result=(Entry_2fdc90*)(allocation+1);
  if(count>0) for(int i=0;i<count;++i) {
   Entry_2fdc90& item=result[i];
   item.a=0; item.b=0; item.c=0; item.d=0; item.e=0; item.f=0; item.g=0;
   item.last=0; item.enabled=1;
   item.transform.FUN_0022b980();
  }
 }
 entries=result;
 FUN_002fd8a0(source);
}
