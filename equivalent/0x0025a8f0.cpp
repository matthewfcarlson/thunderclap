// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 20/20)
// audio::Mix::vfunc_5 @ 0x0025a8f0
typedef unsigned int uint;
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern bool __cdecl FUN_0025abd0(void*, uint*);
extern void* __cdecl FUN_00241670();
extern void* __cdecl FUN_00247530(void*);
namespace audio {
struct MixBuss {
 virtual void vfunc_0(); virtual bool vfunc_1(void*);
 char pad[0x14-4]; uint link; float volume,pitch; uint a,b; unsigned char flag;
};
struct Mix {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(void*);
 char pad[0x30-4]; uint a,b,list;
};
}
extern bool __cdecl FUN_0025a610(uint*, audio::MixBuss*, uint*);
bool audio::Mix::vfunc_5(void* stream) {
 uint version,count;
 if (!FUN_0025abd0(stream,&version) || version != 1) return false;
 if (!FUN_0025abd0(stream,&a)) return false;
 if (!FUN_0025abd0(stream,&b)) return false;
 if (!FUN_0025abd0(stream,&count)) return false;
 for(uint i=0;i<count;++i) {
 void* memory=FUN_00247530(FUN_00241670());
 MixBuss* buss=0;
 if(memory) {
 buss=new(memory) MixBuss;
 buss->volume=1.0f; buss->pitch=1.0f; buss->a=0; buss->b=0; buss->flag=0;
 }
 if(!buss->vfunc_1(stream)) return false;
 if(!FUN_0025a610(&list,buss,&buss->link)) return false;
 }
 return true;
}