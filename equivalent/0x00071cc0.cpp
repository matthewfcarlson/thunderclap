// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00071cc0 @ 0x00071cc0
void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_00068770();
void __cdecl FUN_00068780();
void __cdecl FUN_00068790();
extern unsigned int DAT_004dcfb4;
extern unsigned int DAT_004dcfb0;
extern unsigned int DAT_00496fb4;
class CCameraHintTrack;
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamEnumConstList { virtual void slot0(); char data[12]; unsigned int* list; int count; void (__cdecl *callback)(); char tail[4]; void FUN_00234cc0(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*, void**, int);
void FUN_00071cc0() {
 if (!DAT_004dcfb4) {
  void* entries[3];
  typedef fight::ParamFloatConstRange<CCameraHintTrack> FloatParam;
  typedef fight::ParamEnumConstList<CCameraHintTrack> EnumParam;
  FloatParam* a = (FloatParam*)FUN_0008d690(24);
  if (a) { a->FUN_00234960("timeBegin"); new (a) FloatParam; a->callback=FUN_00068770; }
  entries[0]=a;
  FloatParam* b = (FloatParam*)FUN_0008d690(24);
  if (b) { b->FUN_00234960("timeEnd"); new (b) FloatParam; b->callback=FUN_00068780; }
  entries[1]=b;
  EnumParam* c = (EnumParam*)FUN_0008d690(32);
  if (c) { c->FUN_00234cc0("hint"); new (c) EnumParam; c->list=&DAT_00496fb4; c->count=9; c->callback=FUN_00068790; }
  entries[2]=c;
  FUN_002347b0(&DAT_004dcfb0, entries,3);
 }
 ++DAT_004dcfb4;
}
