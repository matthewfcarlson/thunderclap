// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00078610 @ 0x00078610
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00077ed0(); void __cdecl FUN_00077ee0(); void __cdecl FUN_00077ef0();
extern int DAT_004dd03c;
extern char DAT_004dd038, DAT_0049b6b4;
void __cdecl FUN_002347b0(void*, void**, int);
class CExplosionTrack;
namespace fight {
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234960(const char*); };
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; void* list; int count; void (__cdecl *callback)(); char tail[4]; void FUN_00234cc0(const char*); };
template<class T> struct ParamVector { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00234e50(const char*); };
}
void FUN_00078610() {
 if (DAT_004dd03c == 0) {
 void* items[3];
 fight::ParamFloatConstRange<CExplosionTrack>* a = (fight::ParamFloatConstRange<CExplosionTrack>*)FUN_0008d690(24);
 if(a) { a->FUN_00234960("timeBegin"); new(a) fight::ParamFloatConstRange<CExplosionTrack>; a->callback=FUN_00077ed0; }
 items[0]=a;
 fight::ParamEnumConstList<CExplosionTrack>* b=(fight::ParamEnumConstList<CExplosionTrack>*)FUN_0008d690(32);
 if(b) { b->FUN_00234cc0("explosion"); new(b) fight::ParamEnumConstList<CExplosionTrack>; b->list=&DAT_0049b6b4; b->count=13; b->callback=FUN_00077ee0; }
 items[1]=b;
 fight::ParamVector<CExplosionTrack>* c=(fight::ParamVector<CExplosionTrack>*)FUN_0008d690(24);
 if(c) { c->FUN_00234e50("offset"); new(c) fight::ParamVector<CExplosionTrack>; c->callback=FUN_00077ef0; }
 items[2]=c;
 FUN_002347b0(&DAT_004dd038,items,3);
 }
 ++DAT_004dd03c;
}