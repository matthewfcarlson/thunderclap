// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 43/44, incomplete)
// movie::RenderStrategyBink::vfunc_6 @ 0x00334620
struct Display { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual unsigned height(); virtual unsigned width(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float aspect(); }; extern Display* DAT_0052c2a4;
struct Texture { virtual void acquire(); virtual void release(); Texture* FUN_002c1c30(); void FUN_002c1c70(unsigned,unsigned,int,int,int,int,int); };
extern void* __cdecl FUN_00263ea0(unsigned);
struct Tile { Texture* texture; unsigned x,y,width,height; };
namespace movie { struct RenderStrategyBink { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned,unsigned,int,float); virtual void vfunc_7(); char pad[16]; int left,top; unsigned width,height; float sx,sy; unsigned count; unsigned extra; Tile tiles[1]; }; }
void movie::RenderStrategyBink::vfunc_6(unsigned w,unsigned h,int mode,float ratio) {
 unsigned screenW=DAT_0052c2a4->width(); unsigned screenH=DAT_0052c2a4->height(); float aspect=DAT_0052c2a4->aspect();
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
 int sw=(int)DAT_0052c2a4->width(); left=(int)(((double)sw-(double)width*sx)*0.5f);
 int sh=(int)DAT_0052c2a4->height(); top=(int)(((double)sh-(double)height*sy)*0.5f);
 unsigned rows=(h+1023)>>10, cols=(w+1023)>>10; count=rows*cols;
 Tile* t=tiles; unsigned yy=0;
 for(unsigned row=0;row<rows;++row,yy+=1024) { unsigned xx=0; for(unsigned col=0;col<cols;++col,++t) {
 if(t->texture) { t->texture->release(); t->texture=0; }
 Texture* p=(Texture*)FUN_00263ea0(24); if(p) p=p->FUN_002c1c30(); t->texture=p; p->acquire();
 t->texture->FUN_002c1c70(width,height,32,0,0,11,0);
 t->x=xx; t->y=yy; xx+=1024;
 t->width=xx>width ? width&1023 :1024;
 t->height=yy+1024>height ? height&1023 :1024;
 } }
}