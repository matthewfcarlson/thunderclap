// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 69/70, incomplete)
// FUN_00323130 @ 0x00323130
namespace D3D8 { struct Texture; struct Surface; struct SurfaceDesc { unsigned int data[16]; }; Surface* __stdcall D3DTexture_GetSurfaceLevel2(Texture*, unsigned int); void __stdcall D3DDevice_SetRenderTarget(Surface*, unsigned int); void __stdcall D3DResource_Release(Surface*); void __stdcall D3DDevice_SetTexture(unsigned int, Texture*); void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int); void __stdcall D3DDevice_SetVertexShader(unsigned int); void __stdcall D3DDevice_SetPixelShader(unsigned int); void __stdcall D3DDevice_SetPixelShaderConstant(unsigned int, const float*, unsigned int); void __stdcall D3DDevice_DrawVerticesUP(unsigned int, unsigned int, const void*, unsigned int); }
void __stdcall FUN_003821c0(D3D8::Texture*, unsigned int, D3D8::SurfaceDesc*);
namespace XGRAPHC { int __stdcall XGIsSwizzledFormat(unsigned int); }
extern unsigned int DAT_0039db08,DAT_0039db1c,DAT_0039db20,DAT_0039db9c,DAT_0039dba0,DAT_0039dc1c,DAT_0039dc20,DAT_0039dc9c,DAT_0039dca0,DAT_0039ddfc,DAT_0039de08,DAT_0039de0c,DAT_0039de38;
struct Effect { char pad0[0x88]; unsigned int shaders[5]; char pad1[0xf0-0x9c]; float offsets[20]; float values[20]; D3D8::Texture* FUN_00323130(D3D8::Texture* source,D3D8::Texture* target); };
D3D8::Texture* Effect::FUN_00323130(D3D8::Texture* source,D3D8::Texture* target) {
 D3D8::Surface* surface=D3D8::D3DTexture_GetSurfaceLevel2(target,0); D3D8::D3DDevice_SetRenderTarget(surface,0); D3D8::D3DResource_Release(surface);
 for(unsigned int i=0;i<4;++i) D3D8::D3DDevice_SetTexture(i,source);
 DAT_0039db1c=DAT_0039db20=DAT_0039db9c=DAT_0039dba0=DAT_0039dc1c=DAT_0039dc20=DAT_0039dc9c=DAT_0039dca0=2; DAT_0039db08|=15;
 D3D8::SurfaceDesc desc; FUN_003821c0(source,0,&desc);
 float w=(float)desc.data[5]-0.5f, h=(float)desc.data[6]-0.5f;
 float tw=XGRAPHC::XGIsSwizzledFormat(desc.data[0])?1.0f:(float)desc.data[5];
 float th=XGRAPHC::XGIsSwizzledFormat(desc.data[0])?1.0f:(float)desc.data[6];
 float original[4][12]={0};
 for(int v=0;v<4;++v) { original[v][0]=(v&1)?w:-0.5f; original[v][1]=(v&2)?h:-0.5f; original[v][2]=1.0f; original[v][3]=1.0f; for(int k=0;k<4;++k) { original[v][4+k*2]=(v&1)?tw:0.0f; original[v][5+k*2]=(v&2)?th:0.0f; } }
 int count=0; for(int j=0;j<20;++j) { if(values[j]==0.0f) break; ++count; }
 D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0;
 D3D8::D3DDevice_SetRenderState_Simple(0x40348,1); DAT_0039de0c=1;
 D3D8::D3DDevice_SetRenderState_Simple(0x40344,1); DAT_0039de08=1;
 D3D8::D3DDevice_SetRenderState_Simple(0x40350,0x8006); DAT_0039de38=0x8006;
 D3D8::D3DDevice_SetVertexShader(0x404);
 struct DrawData { float vertices[4][12]; float constants[4][4]; } draw;
 for(int stage=0;stage<2;++stage) {
  if(stage==1) { surface=D3D8::D3DTexture_GetSurfaceLevel2(source,0); D3D8::D3DDevice_SetRenderTarget(surface,0); D3D8::D3DResource_Release(surface); for(unsigned int s=0;s<4;++s) D3D8::D3DDevice_SetTexture(s,target); D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0; }
  for(int side=0;side<2;++side) {
   float sign=side==0?1.0f:-1.0f;
   for(int a=0;a<4;++a) for(int b=0;b<12;++b) draw.vertices[a][b]=original[a][b];
   int batch=0,draws=0;
   for(int n=0;n<count;++n) {
    if(side==1 && n==0) continue;
    float intensity=values[n]; for(int c=0;c<4;++c) draw.constants[batch][c]=intensity;
    float shift=sign*offsets[n];
    for(int v=0;v<4;++v) draw.vertices[v][4+stage+2*batch]+=shift;
    if(draws==1) { D3D8::D3DDevice_SetRenderState_Simple(0x40304,1); DAT_0039ddfc=1; }
    ++batch;
    if(batch==4 || n==count-1) {
     D3D8::D3DDevice_SetPixelShader(shaders[batch]);
     D3D8::D3DDevice_SetPixelShaderConstant(0,&draw.constants[0][0],batch);
     D3D8::D3DDevice_DrawVerticesUP(6,4,draw.vertices,0x30);
     ++draws; batch=0;
     for(int a=0;a<4;++a) for(int b=0;b<12;++b) draw.vertices[a][b]=original[a][b];
    }
   }
   D3D8::D3DDevice_SetRenderState_Simple(0x40304,1); DAT_0039ddfc=1;
  }
 }
 D3D8::D3DDevice_SetRenderState_Simple(0x40304,0); DAT_0039ddfc=0; return source;
}