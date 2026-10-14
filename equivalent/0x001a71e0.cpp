// STATUS: equivalent (tools/equiv.py level 3: 167 inputs, branch coverage 240/244, incomplete)
// FUN_001a71e0 @ 0x001a71e0
typedef void (*Callback_1a71e0)();
void* __cdecl FUN_0008d690(unsigned);
namespace hulkfight { namespace scenario { class NISAnimationTrack; } }
struct ParamBase_1a71e0 { virtual void slot0(); char padding[12]; void FUN_00234960(const char*); void FUN_002349e0(const char*); void FUN_00234cc0(const char*); void FUN_00234860(const char*); void FUN_002348e0(const char*); };
namespace fight {
template<class T> struct ParamFloatConstRange: ParamBase_1a71e0 { virtual void slot0(); Callback_1a71e0 callback; unsigned extra; };
template<class T> struct ParamString: ParamBase_1a71e0 { virtual void slot0(); Callback_1a71e0 callback; unsigned extra; };
template<class T> struct ParamBool: ParamBase_1a71e0 { virtual void slot0(); Callback_1a71e0 callback; unsigned extra; };
template<class T> struct ParamIntConstRange: ParamBase_1a71e0 { virtual void slot0(); Callback_1a71e0 callback; unsigned extra; };
template<class T> struct ParamEnumConstList: ParamBase_1a71e0 { virtual void slot0(); void* list; unsigned count; Callback_1a71e0 callback; unsigned extra; };
}
using namespace fight;
typedef hulkfight::scenario::NISAnimationTrack Track;
extern unsigned DAT_004e175c, DAT_004e1758, DAT_003fb8f8, DAT_003fb8fc;
extern char DAT_004c167c[], DAT_00496f9c[], DAT_00496fa4[];
void __cdecl FUN_002347b0(void*, ParamBase_1a71e0**, unsigned);
#define DECL(a) void FUN_##a();
DECL(001a20f0) DECL(001a2100) DECL(001a2120) DECL(001a2140) DECL(001a2160) DECL(001a2180) DECL(001a36f0) DECL(001a21b0) DECL(001a21d0) DECL(001a2200) DECL(001a2220) DECL(001a2240) DECL(001a2260) DECL(001a2280) DECL(001a22a0) DECL(001a22c0) DECL(001a3750) DECL(001a22e0) DECL(001a2300) DECL(001a2320) DECL(001a2340)
#define GROUPDECL(a,b,c,d,e) DECL(a) DECL(b) DECL(c) DECL(d) DECL(e)
GROUPDECL(001a2360,001a2380,001a37b0,001a3810,001a23c0)
GROUPDECL(001a23e0,001a2400,001a3870,001a38d0,001a2440)
GROUPDECL(001a2460,001a2480,001a3930,001a3990,001a24c0)
GROUPDECL(001a24e0,001a2500,001a3a00,001a3a70,001a2540)
GROUPDECL(001a2560,001a2580,001a3ae0,001a3b50,001a25c0)
GROUPDECL(001a25e0,001a2600,001a3bc0,001a3c30,001a2640)
GROUPDECL(001a2660,001a2680,001a3ca0,001a3d10,001a26c0)
GROUPDECL(001a26e0,001a2700,001a3d80,001a3df0,001a2740)
GROUPDECL(001a2760,001a2780,001a3e60,001a3ed0,001a27c0)
GROUPDECL(001a27e0,001a2800,001a3f40,001a3fb0,001a2840)
GROUPDECL(001a2860,001a2880,001a4020,001a4090,001a28c0)
GROUPDECL(001a28e0,001a2900,001a4100,001a4170,001a2940)
GROUPDECL(001a2960,001a2980,001a41e0,001a4250,001a29c0)
GROUPDECL(001a29e0,001a2a00,001a42c0,001a4330,001a2a40)
GROUPDECL(001a2a60,001a2a80,001a43a0,001a4410,001a2ac0)
GROUPDECL(001a2ae0,001a2b00,001a4480,001a44f0,001a2b40)
GROUPDECL(001a2b60,001a2b80,001a4560,001a45d0,001a2bc0)
GROUPDECL(001a2be0,001a2c00,001a4640,001a46b0,001a2c40)
GROUPDECL(001a2c60,001a2c80,001a4720,001a4790,001a2cc0)
GROUPDECL(001a2ce0,001a2d00,001a4800,001a4870,001a2d40)
#define MAKE(T,init,text,fn) { T<Track>* p=(T<Track>*)FUN_0008d690(sizeof(T<Track>)); if(p) { p->init(text); p->T<Track>::T(); p->callback=FUN_##fn; } params[n++]=p; }
#define F(text,fn) MAKE(ParamFloatConstRange,FUN_00234960,text,fn)
#define S(text,fn) MAKE(ParamString,FUN_002349e0,text,fn)
#define B(text,fn) MAKE(ParamBool,FUN_00234860,text,fn)
#define I(text,fn) MAKE(ParamIntConstRange,FUN_002348e0,text,fn)
#define E(text,fn,listdata,num) { ParamEnumConstList<Track>* p=(ParamEnumConstList<Track>*)FUN_0008d690(sizeof(ParamEnumConstList<Track>)); if(p) { unsigned count=num; p->FUN_00234cc0(text); p->ParamEnumConstList<Track>::ParamEnumConstList(); p->list=listdata; p->count=count; p->callback=FUN_##fn; } params[n++]=p; }
#define GROUP(k,a,b,c,d,e) B("is_Skeleton_" #k,a) B("drop_Weapon_" #k,b) S("animation" #k,c) S("character" #k,d) I("which_Drawable_" #k,e)
void __cdecl FUN_001a71e0() {
 if(!DAT_004e175c) { ParamBase_1a71e0* params[121]; unsigned n=0;
 F("timeBegin",001a20f0) F("timeEnd",001a2100) F("speed",001a2120) F("initFrame",001a2140) F("startFrame",001a2160) F("endFrame",001a2180)
 S("origin_Locator",001a36f0) E("originType",001a21b0,DAT_004c167c,4) F("orientation",001a21d0) B("use_Camera",001a2200)
 E("blendInTransition",001a2220,DAT_00496f9c,DAT_003fb8f8) E("blendInBlend",001a2240,DAT_00496fa4,DAT_003fb8fc) F("blendInDuration",001a2260)
 E("blendOutTransition",001a2280,DAT_00496f9c,DAT_003fb8f8) E("blendOutBlend",001a22a0,DAT_00496fa4,DAT_003fb8fc) F("blendOutDuration",001a22c0)
 S("filename",001a3750) B("screw_Sound_Sync",001a22e0) B("draw_The_Hulk",001a2300) B("load_The_File",001a2320) I("which_Inventory",001a2340)
 GROUP(0,001a2360,001a2380,001a37b0,001a3810,001a23c0)
 GROUP(1,001a23e0,001a2400,001a3870,001a38d0,001a2440)
 GROUP(2,001a2460,001a2480,001a3930,001a3990,001a24c0)
 GROUP(3,001a24e0,001a2500,001a3a00,001a3a70,001a2540)
 GROUP(4,001a2560,001a2580,001a3ae0,001a3b50,001a25c0)
 GROUP(5,001a25e0,001a2600,001a3bc0,001a3c30,001a2640)
 GROUP(6,001a2660,001a2680,001a3ca0,001a3d10,001a26c0)
 GROUP(7,001a26e0,001a2700,001a3d80,001a3df0,001a2740)
 GROUP(8,001a2760,001a2780,001a3e60,001a3ed0,001a27c0)
 GROUP(9,001a27e0,001a2800,001a3f40,001a3fb0,001a2840)
 GROUP(10,001a2860,001a2880,001a4020,001a4090,001a28c0)
 GROUP(11,001a28e0,001a2900,001a4100,001a4170,001a2940)
 GROUP(12,001a2960,001a2980,001a41e0,001a4250,001a29c0)
 GROUP(13,001a29e0,001a2a00,001a42c0,001a4330,001a2a40)
 GROUP(14,001a2a60,001a2a80,001a43a0,001a4410,001a2ac0)
 GROUP(15,001a2ae0,001a2b00,001a4480,001a44f0,001a2b40)
 GROUP(16,001a2b60,001a2b80,001a4560,001a45d0,001a2bc0)
 GROUP(17,001a2be0,001a2c00,001a4640,001a46b0,001a2c40)
 GROUP(18,001a2c60,001a2c80,001a4720,001a4790,001a2cc0)
 GROUP(19,001a2ce0,001a2d00,001a4800,001a4870,001a2d40)
 FUN_002347b0(&DAT_004e1758,params,121);
 } ++DAT_004e175c;
}
