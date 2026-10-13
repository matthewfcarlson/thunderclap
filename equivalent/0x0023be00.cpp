// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 22/22)
// fight::BinReader::vfunc_8 @ 0x0023be00
extern "C" void* __cdecl memcpy(void*,const void*,unsigned);
void* __cdecl FUN_00238190(int);
void* __cdecl FUN_00266e00(void*, unsigned);
void __cdecl FUN_00267090(void*);
struct Stream {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual unsigned read(void*,unsigned);
};
namespace fight {
struct BinReader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual bool vfunc_8(int,int,char*,int);
 virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual bool vfunc_12(int,int,int*);
 char pad4[4]; Stream* stream; char padc[4]; int length; char pad14[12]; unsigned remaining;
};
bool BinReader::vfunc_8(int a,int b,char* output,int capacity) {
 if(length<0 && !vfunc_12(a,b,&length)) return false;
 bool success=true;
 if(length>0) {
 unsigned padded=((unsigned)length+3)&~3u;
 char* buffer=(char*)FUN_00266e00(FUN_00238190(1),padded+1);
 unsigned count=remaining;
 if(padded<count) count=padded;
 unsigned actual=stream->read(buffer,count);
 remaining-=count;
 success=actual==padded;
 if(output && capacity>0) {
 int copy=length<capacity?length:capacity;
 memcpy(output,buffer,(unsigned)copy);
 int end=length<capacity-1?length:capacity-1;
 output[end]=0;
 }
 FUN_00267090(buffer);
 } else if(output && capacity>0) output[0]=0;
 length=-1;
 return success;
}
}
