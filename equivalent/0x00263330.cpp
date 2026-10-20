// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 18/18)
// audio::HalRsdFileStream::vfunc_11 @ 0x00263330
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

extern void* __cdecl FUN_00247530(void*);
extern void __cdecl FUN_00263470(void*);
extern void __cdecl FUN_00263480(unsigned*,void*);
struct File_263330 {
 virtual void f0(); virtual void f1(); virtual void f2();
 virtual void read(void*,unsigned,int);
 virtual void f4(); virtual void seek(unsigned);
 virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual bool ready(); virtual void f21(); virtual void f22(); virtual unsigned char status(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void mode(int);
};
namespace audio {
struct HalRsdFileStream_nv_263330 {
    void FUN_002630c0();
};

}
void audio::HalRsdFileStream::vfunc_11() {
 switch(this->f_44) {
 case 5:
  if((*(File_263330 * *)&this->f_20)->ready()) { this->f_2c-=this->f_3c; this->f_44=6; }
  break;
 case 3:
  if((*(File_263330 * *)&this->f_20)->ready()) { FUN_00263470((*(void * *)&this->f_24)); FUN_00263480(&(*(unsigned int *)&this->f_28),(*(void * *)&this->f_24)); (*(unsigned char *)&this->f_40)=1; ((HalRsdFileStream_nv_263330*)this)->FUN_002630c0(); }
  break;
 case 1:
  if(!(*(File_263330 * *)&this->f_20)->ready()) break;
  if((*(File_263330 * *)&this->f_20)->status()!=1) { this->f_44=2; break; }
  (*(File_263330 * *)&this->f_20)->mode(1);
  if((*(unsigned char *)&this->f_40)) { ((HalRsdFileStream_nv_263330*)this)->FUN_002630c0(); break; }
  { unsigned* p=(unsigned*)FUN_00247530(((char*)((char*)&DAT_004e7b08 + 72)));
    if(p) for(unsigned i=0;i<0x69;++i) p[i]=0;
    (*(void * *)&this->f_24)=p; this->f_44=3;
    (*(File_263330 * *)&this->f_20)->seek((*(unsigned int *)&this->f_30));
    (*(File_263330 * *)&this->f_20)->read((*(void * *)&this->f_24),0x1a4,1);
  }
  break;
 }
}
