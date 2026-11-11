// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003340b0..0x00334940 (kind game, layer platform/xbox, confidence high), dominant class movie::RenderStrategyBink
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/game/global.h"
#include "gen/movie.h"
#define TREE_TU_BEGIN namespace fn_f9e99c55 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9e99c55 {} using namespace fn_f9e99c55;
#include "platform/xbox/movie.h"

// ---- declarations shared by the functions below
namespace fn_f9e99c55 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_004342bc[];
extern "C" char DAT_004342c4[];
struct V {
    virtual void f();
    virtual void g();
};
struct X_3340b0 {
    void** v;
    int a;
    int b;
    char p0[4];
    V* p;
    char pad[0x20];
    V* q;
};
class IB_334110 {
  public:
    void helper();
};
class RenderStrategyBink_334110 : public movie::RenderStrategy, public IB_334110 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Inner_3341c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o(int);
};
struct Mid_3341c0 {
    char pad[0x10];
    Inner_3341c0* q;
};
struct Entry_3341c0 {
    Mid_3341c0* p;
    char pad[16];
};
class RenderStrategyBink_3341c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[0x30 - 4];
    int index;
    Entry_3341c0 entries[1];
    char flag;
};
typedef unsigned char u8_3345f0;
class RenderStrategyBink_3345f0 {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual RenderStrategyBink_3345f0* f2(u8_3345f0);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
extern "C" hulk_intptr __cdecl allocate(void*, unsigned int);
struct RenderStrategyBink_nv_334910 {
    int finish();
};


// 0x003340b0 FUN_003340b0 (77 B): matches/0x003340b0.cpp
// sym: ?FUN_003340b0@fn_f9e99c55@@YIXPAUX_3340b0@1@@Z
// data: global_3340b0 = DAT_004cdbb0
void __fastcall FUN_003340b0(X_3340b0* x) {
    x->v = (void**)((hulk_intptr)DAT_004342c4);
    x->a = (int)((hulk_intptr)DAT_004342bc);
    if (x->p) {
        x->p->g();
        x->p = 0;
    }
    if (x->q) {
        x->q->g();
        x->q = 0;
    }
    DAT_004cdbb0 = x->b;
    x->a = (int)((hulk_intptr)DAT_0042af64);
    x->v = (void**)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_f9e99c55

// 0x00334100 movie::RenderStrategyBink::vfunc_0 (4 B): matches/0x00334100.cpp
// sym: ?vfunc_0@RenderStrategyBink@movie@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void movie::RenderStrategyBink::vfunc_0() {
    ++this->f_0c;
}

namespace fn_f9e99c55 {

// 0x00334110 movie::RenderStrategyBink::vfunc_1 (8 B): matches/0x00334110.cpp
// sym: ?vfunc_1@RenderStrategyBink_334110@fn_f9e99c55@@UAEXXZ
// Same code shape as 0x0026d270 (propagated; names are from that function)
void RenderStrategyBink_334110::vfunc_1() {
    IB_334110::helper();
}

} // namespace fn_f9e99c55

// 0x00334120 movie::RenderStrategyBink::vfunc_3 (8 B): matches/0x00334120.cpp
// sym: ?vfunc_3@RenderStrategyBink@movie@@UAEXXZ
void movie::RenderStrategyBink::vfunc_3() {
    this->f_30 = 0;
}


// 0x00334130 movie::RenderStrategyBink::vfunc_4 (133 B): equivalent/0x00334130.cpp [wrapped: conflict: movie::RenderStrategyBink]
// sym: ?vfunc_4@RenderStrategyBink@movie@fn_00334130@@UAEIPAUOutput_334130@3@@Z @7819e374f81f @waed8b40f1e69
namespace fn_00334130 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// movie::RenderStrategyBink::vfunc_4 @ 0x00334130
struct Surface_334130 { char pad[0x48]; unsigned value48; unsigned pad4c; unsigned value50; };
struct Provider_334130 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual Surface_334130* slot13(unsigned, unsigned); };
struct Resource_334130 { char pad[0x10]; Provider_334130* provider; };
struct Entry_334130 { Resource_334130* resource; unsigned a,b,c,d; };
struct Output_334130 { unsigned a,b,c,d,e,f,g,h; };
namespace movie { struct RenderStrategyBink {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual unsigned vfunc_4(Output_334130*); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
char pad[0x28]; unsigned count; unsigned index; Entry_334130 entries[1]; unsigned char active;
};
unsigned RenderStrategyBink::vfunc_4(Output_334130* out) {
if(index >= count) return 0;
// The active flag shares storage with the first entry's trailing word.
((unsigned char*)&entries[0].d)[4] = 1;
Surface_334130* s = entries[index].resource->provider->slot13(0,0);
out->a = s->value50; out->b = s->value48; out->c=0; out->d=0;
out->e=entries[index].a; out->f=entries[index].b; out->g=entries[index].c; out->h=entries[index].d;
return count-index;
}
}
} // namespace fn_00334130

namespace fn_f9e99c55 {

// 0x003341c0 movie::RenderStrategyBink::vfunc_5 (32 B): matches/0x003341c0.cpp
// sym: ?v5@RenderStrategyBink_3341c0@fn_f9e99c55@@UAEXXZ
void RenderStrategyBink_3341c0::v5() {
    Mid_3341c0* m = entries[index].p;
    m->q->o(0);
    ++index;
    flag = 0;
}

} // namespace fn_f9e99c55

// 0x003341e0 movie::RenderStrategyBink::vfunc_7 (836 B): equivalent/0x003341e0.cpp [wrapped: conflict: movie::RenderStrategyBink]
// sym: ?vfunc_7@RenderStrategyBink@movie@fn_003341e0@@UAE_NXZ @76cd4d3a750e @w48680338f378
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_003341e0 {
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 14/14)
// movie::RenderStrategyBink::vfunc_7 @ 0x003341e0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Stream { char pad[8]; float* position; unsigned unused; unsigned* color; float* uv; void FUN_0008ef00(); };
struct Material_3341e0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void texture(unsigned,void*); virtual void option(unsigned,int); };
struct Holder_3341e0 { char pad[16]; Material_3341e0* material; };
struct Texture { char pad[16]; void* handle; };
struct Tile_3341e0 { Texture* texture; int x,y; unsigned width,height; };
struct Gfx {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void finish(int);
virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void state21(int); virtual void s22(); virtual void s23(); virtual void state24(int); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void viewport(float*,float*,float*,float*); virtual Stream* begin(Material_3341e0*,int,unsigned,int,int); virtual void end(Stream*);
virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void state54(int);
virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void start(int); virtual void stop(int);
};
namespace movie { struct RenderStrategyBink { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(); char pad[12]; Holder_3341e0* holder; int x,y; char pad2[8]; union { float sx; unsigned sxBits; }; union { float sy; unsigned syBits; }; unsigned count; char pad3[4]; Tile_3341e0 tiles[1]; }; }
bool movie::RenderStrategyBink::vfunc_7() {
 DAT_0052c2a8->start(-1); DAT_0052c2a8->state21(0); DAT_0052c2a8->state24(2); DAT_0052c2a8->state54(0);
 float depth,b,c,d; DAT_0052c2a8->viewport(&depth,&d,&c,&b);
 holder->material->option(0x444d4c42,0); holder->material->option(0x444d5655,1); holder->material->option(0x444d4946,(sxBits==0x3f800000 && syBits==0x3f800000)?0:1);
 for(unsigned i=0;i<count;++i) {
 Tile_3341e0& t=tiles[i];
 float u=(float)((double)t.width+0.5f); float v=(float)((double)t.height+0.5f);
 float left=(float)((double)t.x*sx+x); float top=(float)((double)t.y*sy+y); float z=depth+0.01f;
 float right=(float)((double)t.width*sx+left); float bottom=(float)((double)t.height*sy+top);
 holder->material->texture(0x584554,t.texture?t.texture->handle:0);
 Stream* s=DAT_0052c2a8->begin(holder->material,0,0x2021,6,0);
 for(int j=0;j<6;++j) {
 *s->color=0xffffffff;
 s->uv[0]=(j==1||j==2||j==4)?u:0.5f;
 s->uv[1]=(j==2||j==4||j==5)?v:0.5f;
 s->position[0]=(j==1||j==2||j==4)?right:left;
 s->position[1]=(j==0||j==1||j==3)?bottom:top;
 s->position[2]=z;
 s->FUN_0008ef00();
 }
 DAT_0052c2a8->end(s);
 }
 DAT_0052c2a8->finish(0); DAT_0052c2a8->stop(-1); return true;
}
} // namespace fn_003341e0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00334530 movie::RenderStrategyBink::vfunc_0_adj4 (8 B): matches/0x00334530.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ?vfunc_2@RenderStrategyBink@movie@fn_00334530@@W3AEXH@Z
namespace fn_00334530 {
namespace movie {
class RenderStrategy {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
class Secondary {
  public:
    virtual void vfunc_2(int);
};
class RenderStrategyBink : public RenderStrategy, public Secondary {
  public:
    virtual void vfunc_2(int);
};
RenderStrategyBink instance;
} // namespace movie
} // namespace fn_00334530


// 0x00334540 FUN_00334540 (165 B): equivalent/0x00334540.cpp [wrapped: conflict: core::Object; core::RefCount; movie::RenderStrategy; movie::RenderStrategyBink]
// sym: ?FUN_00334540@RenderStrategyBink@movie@fn_00334540@@QAEPAU123@XZ @be5238ca7af9 @wbbab037d2539
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_00334540 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00334540 @ 0x00334540

/* size_t: tree_prelude.h */

void __cdecl FUN_002705f0();
void* __cdecl FUN_00263ea0(unsigned int);
struct Shader_334540 { virtual void slot0(); Shader_334540* FUN_0028edb0(); };
namespace core {
struct Object { virtual void slot0(); int id; };
struct RefCount : Object { int count; };
}
namespace movie {
struct RenderStrategy { virtual void slot0(); };
struct RenderStrategyBink : RenderStrategy, core::Object {
 int count; Shader_334540* resource; int f14,f18,f1c,f20; float f24,f28; int f2c,f30; int f34,f38,f3c,f40,f44; unsigned char f48;
 RenderStrategyBink* FUN_00334540();
};
}
movie::RenderStrategyBink* movie::RenderStrategyBink::FUN_00334540() {
 new(static_cast<RenderStrategy*>(this)) RenderStrategy;
 new(static_cast<core::Object*>(this)) core::Object;
 id=DAT_004cdbb0;
 FUN_002705f0();
 new(static_cast<core::Object*>(this)) core::RefCount;
 count=0;
 FUN_002705f0();
 new(this) RenderStrategyBink;
 resource=0; f14=0; f18=0; f1c=0; f20=0; f2c=0; f30=0; f48=0;
 f24=1.0f; f28=1.0f;
 f34=0; f38=0; f3c=0; f40=0; f44=0;
 Shader_334540* p=(Shader_334540*)FUN_00263ea0(32);
 if(p) p=p->FUN_0028edb0();
 resource=p;
 p->slot0();
 return this;
}
} // namespace fn_00334540

namespace fn_f9e99c55 {

// 0x003345f0 movie::RenderStrategyBink::vfunc_2 (36 B): matches/0x003345f0.cpp
// sym: ?f2@RenderStrategyBink_3345f0@fn_f9e99c55@@UAEPAV12@E@Z
// Same code shape as 0x00269560 (propagated; names are from that function)
// data: globalValue = DAT_004cdbb0
RenderStrategyBink_3345f0* RenderStrategyBink_3345f0::f2(u8_3345f0 flag) {
    cleanup();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}

} // namespace fn_f9e99c55

// 0x00334620 movie::RenderStrategyBink::vfunc_6 (743 B): equivalent/0x00334620.cpp [wrapped: conflict: movie::RenderStrategyBink]
// sym: ?vfunc_6@RenderStrategyBink@movie@fn_00334620@@UAEXIIHM@Z @01aad3b5e30f @wf51e31e37c64
namespace fn_00334620 {
// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 43/44, incomplete)
// movie::RenderStrategyBink::vfunc_6 @ 0x00334620

struct Display_334620 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual unsigned height(); virtual unsigned width(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float aspect(); }; 
struct Texture { virtual void acquire(); virtual void release(); Texture* FUN_002c1c30(); void FUN_002c1c70(unsigned,unsigned,int,int,int,int,int); };
extern void* __cdecl FUN_00263ea0(unsigned);
struct Tile_334620 { Texture* texture; unsigned x,y,width,height; };
namespace movie { struct RenderStrategyBink { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned,unsigned,int,float); virtual void vfunc_7(); char pad[16]; int left,top; unsigned width,height; float sx,sy; unsigned count; unsigned extra; Tile_334620 tiles[1]; }; }
void movie::RenderStrategyBink::vfunc_6(unsigned w,unsigned h,int mode,float ratio) {
 unsigned screenW=(*(Display_334620**)&DAT_0052c2a4)->width(); unsigned screenH=(*(Display_334620**)&DAT_0052c2a4)->height(); float aspect=(*(Display_334620**)&DAT_0052c2a4)->aspect();
 if(w==width && h==height) return;
 width=w; height=h;
 float fw=(float)w;
 volatile float fh=(float)h;   // the original rounds h and r to float in memory
 volatile float r=fw/fh*ratio;
 double factor=1.0f;
 if(mode==2) factor=(double)r/aspect;
 else if(mode==0) { factor=(double)r/aspect; if(factor>1.0f) factor=1.0f; }
 double x=(double)screenW/fw*factor;
 sx=(float)x;
 float y=(float)((double)screenH*aspect/((double)fh*r)*factor);
 sy=y;
 union {float f; unsigned u;} ax,ay; ax.f=(float)(x-1.0f); ax.u &=0x7fffffff; ay.f=(float)((double)y-1.0f); ay.u &=0x7fffffff;
 if(ax.f<=0.001f && ay.f<=0.001f) { sx=1.0f; sy=1.0f; }
 int sw=(int)(__int64)(*(Display_334620**)&DAT_0052c2a4)->width(); left=(int)(__int64)(((double)sw-(double)width*sx)*0.5f);
 int sh=(int)(__int64)(*(Display_334620**)&DAT_0052c2a4)->height(); top=(int)(__int64)(((double)sh-(double)height*sy)*0.5f);
 unsigned rows=(h+1023)>>10, cols=(w+1023)>>10; count=rows*cols;
 Tile_334620* t=tiles; unsigned yy=0;
 for(unsigned row=0;row<rows;++row,yy+=1024) { unsigned xx=0; for(unsigned col=0;col<cols;++col,++t) {
 if(t->texture) { t->texture->release(); t->texture=0; }
 Texture* p=(Texture*)FUN_00263ea0(24); if(p) p=p->FUN_002c1c30(); t->texture=p; p->acquire();
 t->texture->FUN_002c1c70(width,height,32,0,0,11,0);
 t->x=xx; t->y=yy; xx+=1024;
 t->width=xx>width ? width&1023 :1024;
 t->height=yy+1024>height ? height&1023 :1024;
 } }
}
} // namespace fn_00334620

namespace fn_f9e99c55 {

// 0x00334910 FUN_00334910 (34 B): matches/0x00334910.cpp
// sym: _FUN_00334910
// data: g_value_334910 = DAT_004cdbb0
extern "C" int __cdecl FUN_00334910(void* p) {
    DAT_004cdbb0 = (hulk_intptr)p;
    movie::RenderStrategyBink* x = (movie::RenderStrategyBink*)allocate(p, 0x4c);
    if (x)
        return ((RenderStrategyBink_nv_334910*)(((movie::RenderStrategyBink*)(x))))->finish();
    return 0;
}

} // namespace fn_f9e99c55
