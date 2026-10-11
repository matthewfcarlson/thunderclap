// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 80/84, incomplete)
// core::XboxSaveDrive::vfunc_9 @ 0x00279630
typedef unsigned int U; typedef unsigned char B;
struct SaveData { U data; U length; };
struct Large { U low, high; };
extern const char *DAT_004ce26c, *DAT_004ce270;
extern U *DAT_0052c270; extern U DAT_0052c27c;
extern void __cdecl FUN_0026b800(unsigned short *,int,U,int,int,int,int);
extern U __stdcall FUN_0035618d(const char *,const unsigned short *,U,U,char *,U);
extern U __stdcall FUN_003563f0(const char *,const unsigned short *);
extern int __stdcall FUN_00208b9c(const char *,Large *,Large *,Large *);
extern U __stdcall FUN_002109f1(const char *,U,U,U,U,U,U);
extern U __stdcall FUN_002101d4(U,U,U,U);
extern int __stdcall FUN_00210150(U);
extern int __stdcall FUN_0021007a(U,U,U,U *,U);
extern void __stdcall FUN_0020bbc2(U);
extern U __cdecl FUN_00278150(U);
namespace XAPILIB { U __stdcall GetLastError(); }
namespace core { struct XboxSaveDrive {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual U vfunc_5(SaveData *,U); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(U,U,B,SaveData *,U,U *,U *);
char pad[0xb0]; U error; char pad2[0x10]; U count; char pad3[0x12]; B letter; B pad4; U handles[4];
B FUN_002788c0(); U FUN_002787c0(U); B FUN_002789e0(U); B FUN_00278ef0(U,U,B); B FUN_00278a00(U,U *); B FUN_00279490(U,U);
}; }
int core::XboxSaveDrive::vfunc_9(U name,U mode,B writable,SaveData *data,U size,U *out,U *amount) {
 if(!FUN_002788c0()) return 0;
 char drive[4]; char path[260]; unsigned short title[256];
 drive[0]=letter; drive[1]=':'; drive[2]='\\'; drive[3]=0;
 FUN_0026b800(title,2,name,1,0,0x202,0);
 U access=writable?0xc0000000:0x80000000; U share=writable?3:1;
 U status=FUN_0035618d(drive,title,3,0,path,260);
 if(status!=0 && status!=3) {error=FUN_002787c0(status); return 0;}
 U pathLength=0; while(path[pathLength]) ++pathLength;
 bool changed=status==3 || (mode!=0 && mode!=1);
 if(mode==3) { if(status!=3) { U e=FUN_002787c0(FUN_003563f0(drive,title)); error=e; if(e) return 0; } }
 else if(mode==0 && status==3) {FUN_002789e0(status); return 0;}
 U result;
 do {
 if(changed) {
 Large available,total,freeTotal;
 if(!FUN_00208b9c(drive,&available,&total,&freeTotal)) break;
 U freeBytes=available.high?0xffffffff:available.low;
 if(freeBytes < vfunc_5(data,size)) {error=7; return 0;}
 if(!FUN_002789e0(FUN_0035618d(drive,title,1,0,path,260))) return 0;
 pathLength=0; while(path[pathLength]) ++pathLength;
 if(data->data) {
 const char *p=DAT_004ce26c; char *q=path+pathLength; do { *q++=*p; } while(*p++);
 U h=FUN_002109f1(path,0xc0000000,3,0,2,0x80,0);
 if(h==0xffffffff) break;
 result=0;
 U pos=FUN_002101d4(h,data->length,0,0);
 if(pos!=data->length || !FUN_00210150(h) || FUN_002101d4(h,0,0,0)!=0 || !FUN_0021007a(h,data->data,data->length,&result,0)) {FUN_0020bbc2(h); break;}
 FUN_0020bbc2(h);
 }
 }
 const char *p=DAT_004ce270; char *q=path+pathLength; do {*q++=*p;} while(*p++);
 U h=FUN_002109f1(path,0xc0000000,3,0,changed?1:3,0x80,0); *out=h;
 if(h==0xffffffff) break;
 if(changed) {
 U bytes=FUN_00278150(size);
 if(FUN_002101d4(h,bytes,0,0)!=bytes || !FUN_00210150(*out) || !FUN_00278ef0(*out,bytes,!writable)) {FUN_0020bbc2(*out); break;}
 }
 FUN_0020bbc2(*out);
 h=FUN_002109f1(path,access,share,0,3,0x80,0); *out=h;
 if(h==0xffffffff) {FUN_0020bbc2(h); break;}
 if(!FUN_00278a00(h,&result)) {FUN_0020bbc2(*out); return 0;}
 U savedSize=result;
 if(changed) {for(U i=0;i<4;++i) if(handles[i]==0xffffffff) {handles[i]=*out; break;}}
 else {
 bool valid=false;
 if(savedSize>=24) {
 if(!FUN_00279490(*out,0)) {FUN_0020bbc2(*out); return 0;}
 valid=(*DAT_0052c270==result);
 }
 if(!valid) {FUN_0020bbc2(*out); DAT_0052c27c=0; error=12; return 0;}
 }
 *amount=savedSize-((savedSize+0x2013)/0x2014)*20-4;
 ++count; error=0; return 1;
 } while(false);
 FUN_002789e0(XAPILIB::GetLastError()); return 0;
}
