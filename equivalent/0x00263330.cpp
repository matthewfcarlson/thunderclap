// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// audio::HalRsdFileStream::vfunc_11 @ 0x00263330
extern char DAT_004e7b50;
extern void* __cdecl FUN_00247530(void*);
extern void __cdecl FUN_00263470(void*);
extern void __cdecl FUN_00263480(unsigned*,void*);
struct File {
 virtual void f0(); virtual void f1(); virtual void f2();
 virtual void read(void*,unsigned,int);
 virtual void f4(); virtual void seek(unsigned);
 virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual bool ready(); virtual void f21(); virtual void f22(); virtual unsigned char status(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void mode(int);
};
namespace audio {
struct HalRsdFileStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
 char pad[0x1c]; File* file; void* header; unsigned info; unsigned remaining; unsigned offset; unsigned unused34; unsigned unused38; unsigned consumed; unsigned char initialized; char pad41[3]; unsigned state;
 void FUN_002630c0();
};
void HalRsdFileStream::vfunc_11() {
 switch(state) {
 case 5:
  if(file->ready()) { remaining-=consumed; state=6; }
  break;
 case 3:
  if(file->ready()) { FUN_00263470(header); FUN_00263480(&info,header); initialized=1; FUN_002630c0(); }
  break;
 case 1:
  if(!file->ready()) break;
  if(file->status()!=1) { state=2; break; }
  file->mode(1);
  if(initialized) { FUN_002630c0(); break; }
  { unsigned* p=(unsigned*)FUN_00247530(&DAT_004e7b50);
    if(p) for(unsigned i=0;i<0x69;++i) p[i]=0;
    header=p; state=3;
    file->seek(offset);
    file->read(header,0x1a4,1);
  }
  break;
 }
}
}
