// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 60/62, incomplete)
// FUN_000c3900 @ 0x000c3900
typedef unsigned int U;
struct Obj { virtual void init(); virtual void release(); };
namespace pure3d { class DrawableHierarchy; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
struct Inner { virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void set(U,U); virtual void enable(U,U); };
struct Resource : Obj { char pad[12]; Inner* inner; Resource* FUN_0028edb0(); };
struct Loader : Obj { virtual void a2(); virtual Obj* find(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>*, unsigned __int64); Loader* FUN_00266480(int); };
#define V(n) virtual void v##n();
struct Manager { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) virtual void select(int); };
struct Screen { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) virtual void finish(); };
struct Root { char pad[0xe4]; Screen* screen; };
struct Other { void FUN_000929a0(U,int); };
extern Obj* DAT_004dde34; extern Resource* DAT_004dde30; extern unsigned char DAT_004dde2c; extern U DAT_004dde28,DAT_0049fb2c,DAT_0049fb30,DAT_004d9968; extern Manager* DAT_0052c2a8; extern Root* DAT_0052c2b4;
// equiv-conv: __security_check_cookie ecx
void __cdecl __security_check_cookie(U);
int __cdecl FUN_000964a0(char*,int,const char*,...);
void* __cdecl FUN_00263ea0(int);
unsigned __int64 __cdecl FUN_0027b020(const char*);
U __cdecl FUN_00267f80();
void __cdecl FUN_000b9230(Obj*);
struct Game { char p0[0x4c]; Other* other; char p1[0x187c-0x50]; U id; char p2[0x1a08-0x1880]; U start;
void FUN_000bc3c0(const char*,Loader*,int); void FUN_000bd050(); void FUN_000b9470(int,Resource*); bool FUN_000bdf50(bool,int); void FUN_000c21b0(U);
bool target(const char*,U,U,int,const char*,U,U);
};
bool Game::target(const char* name,U duration,U threshold,int mode,const char* folder,U unused,U fade) {
U cookie=DAT_004d9968; bool result=false;
U elapsed;
if(!start) {
 if(DAT_004dde34){ DAT_004dde34->release(); DAT_004dde34=0; }
 if(DAT_004dde30){ DAT_004dde30->release(); DAT_004dde30=0; }
 struct Frame { content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster; char path[256]; char image[256]; } frame;
 if(mode==0) FUN_000964a0(frame.path,256,"art/%s.p3d",name);
 else if(mode==1) FUN_000964a0(frame.path,256,"%s/%s.p3d",folder,name);
 Loader* l=(Loader*)FUN_00263ea0(20); if(l) l=l->FUN_00266480(1024);
 l->init(); FUN_000bc3c0(frame.path,l,11);
 FUN_000964a0(frame.image,256,"%s.png",name);
 unsigned __int64 key=FUN_0027b020(frame.image);
 DAT_004dde34=l->find(&frame.caster,key); DAT_004dde34->init();
 start=FUN_00267f80();
 Resource* r=(Resource*)FUN_00263ea0(32); if(r) r=r->FUN_0028edb0();
 DAT_004dde30=r; r->init(); DAT_004dde30->inner->enable(0x444d4c42,1);
 l->release(); DAT_004dde2c=0;
}
if(DAT_004dde34) { DAT_0052c2a8->select(7); FUN_000b9230(DAT_004dde34); }
if(mode==1) FUN_000bd050();
elapsed=FUN_00267f80()-start;
if(elapsed<fade) FUN_000b9470((int)(((double)fade-(double)elapsed)/(double)fade*255.0f),DAT_004dde30);
bool fading=false;
if(!DAT_004dde2c) {
 if(mode==0 && elapsed>duration-DAT_0049fb30-100) {
 fading=true;
 FUN_000b9470((int)((1.0f-((double)duration-((double)elapsed+100.0f))/(double)DAT_0049fb30)*255.0f),DAT_004dde30);
 }
} else { FUN_000b9470((int)((1.0f-(double)(DAT_004dde28-elapsed)/(double)DAT_0049fb2c)*255.0f),DAT_004dde30); }
if(elapsed>threshold && !DAT_004dde2c && !fading) {
 if(FUN_000bdf50(mode==1,0)) { DAT_004dde2c=1; DAT_004dde28=DAT_0049fb2c+elapsed; }
}
if((DAT_004dde2c && DAT_004dde28<elapsed) || (mode==0 && elapsed>duration)) {
 DAT_0052c2b4->screen->finish();
 DAT_004dde30->inner->set(0x584554,0);
 if(DAT_004dde30){ DAT_004dde30->release(); DAT_004dde30=0; }
 if(DAT_004dde34){ DAT_004dde34->release(); DAT_004dde34=0; }
 other->FUN_000929a0(id,0); FUN_000c21b0(id); start=0; result=true;
}
__security_check_cookie(cookie); return result;
}
