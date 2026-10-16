// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 8/8)
// FUN_00245720 @ 0x00245720
#include "decls/data/engine/om.h"

struct Key_245720 { unsigned a,b; };
inline void* __cdecl operator new(unsigned,void* p) { return p; }
struct FUN_00244ea0 {
 virtual void retain();
 virtual void release();
 char pad[36];
 FUN_00244ea0(char* = ((char*)&DAT_004e5f18));
 void FUN_00245040(Key_245720*);
};
namespace audio { struct Clip: FUN_00244ea0 {
 virtual void retain();
 virtual void release();
 void* data;
}; }
extern void __cdecl FUN_0025ca90(Key_245720*, const char*);
extern audio::Clip* __cdecl FUN_00244fa0(Key_245720*,char*);
extern void* __cdecl FUN_00247530(char*);
extern void* __cdecl FUN_0025cab0(void*,const char*,int,int);
extern void* __cdecl FUN_00245390(void*,void*);
bool __cdecl target(audio::Clip** out, void* source, const char* name, void* option) {
 Key_245720 key;
 FUN_0025ca90(&key,name);
 *out=FUN_00244fa0(&key,((char*)((char*)&DAT_004e5f18 + 48)));
 if(*out) {
  (*out)->retain();
  if((*out)->data) return true;
 } else {
  void* memory=FUN_00247530(((char*)&DAT_004e5f18));
  audio::Clip* clip=memory ? new(memory) audio::Clip:0;
  if(clip) clip->data=0;
  *out=clip;
  (*out)->retain();
  (*out)->FUN_00245040(&key);
 }
 void* stream=FUN_0025cab0(source,name,0,2);
 void* data=FUN_00245390(stream,option);
 if(data) { (*out)->data=data; return true; }
 (*out)->release();
 *out=0;
 return false;
}