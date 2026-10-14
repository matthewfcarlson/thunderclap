// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_000711c0 @ 0x000711c0
inline void* operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_00068310();
void __cdecl FUN_00068320();
void __cdecl FUN_00068330();
void __cdecl FUN_0006b7b0();
void* __cdecl FUN_0008d690(unsigned int);
extern int DAT_004dcf5c;
extern int DAT_004dcf58;
struct ParamBase_711c0 {
 virtual void placeholder();
 char padding[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
class CMoveAddYTrack;
namespace fight { template<class T> struct ParamFloatConstRange : ParamBase_711c0 { virtual void placeholder(); }; }
void __cdecl FUN_002347b0(int*,ParamBase_711c0**,int);
void FUN_000711c0() {
 if (DAT_004dcf5c == 0) {
 ParamBase_711c0* items[4];
 ParamBase_711c0* p;
 p = (ParamBase_711c0*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<CMoveAddYTrack>; p->callback=FUN_00068310; } items[0]=p;
 p = (ParamBase_711c0*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeEnd"); new(p) fight::ParamFloatConstRange<CMoveAddYTrack>; p->callback=FUN_00068320; } items[1]=p;
 p = (ParamBase_711c0*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("distance"); new(p) fight::ParamFloatConstRange<CMoveAddYTrack>; p->callback=FUN_00068330; } items[2]=p;
 p = (ParamBase_711c0*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("direction"); new(p) fight::ParamFloatConstRange<CMoveAddYTrack>; p->callback=FUN_0006b7b0; } items[3]=p;
 FUN_002347b0(&DAT_004dcf58,items,4);
 }
 ++DAT_004dcf5c;
}
