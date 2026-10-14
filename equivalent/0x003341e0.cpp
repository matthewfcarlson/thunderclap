// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 14/14)
// movie::RenderStrategyBink::vfunc_7 @ 0x003341e0
struct Stream { char pad[8]; float* position; unsigned unused; unsigned* color; float* uv; void FUN_0008ef00(); };
struct Material_3341e0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void texture(unsigned,void*); virtual void option(unsigned,int); };
struct Holder_3341e0 { char pad[16]; Material_3341e0* material; };
struct Texture { char pad[16]; void* handle; };
struct Tile_3341e0 { Texture* texture; int x,y; unsigned width,height; };
struct Device_3341e0 {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void finish(int);
virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void state21(int); virtual void s22(); virtual void s23(); virtual void state24(int); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void viewport(float*,float*,float*,float*); virtual Stream* begin(Material_3341e0*,int,unsigned,int,int); virtual void end(Stream*);
virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void state54(int);
virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void start(int); virtual void stop(int);
};
extern Device_3341e0* DAT_0052c2a8;
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