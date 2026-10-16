// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 40/40)
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/pure3d.h"

extern unsigned int DAT_0039db08, DAT_0039db90, DAT_0039db94, DAT_0039db98;
struct Light { char pad0[4]; float color[4]; char pad1[44]; float direction[4]; char pad2[24]; };
namespace D3D8 { void __stdcall D3DDevice_GetLight(int,Light*); void __fastcall D3DDevice_SetVertexShaderConstant1(int,const float*); void __stdcall D3DDevice_SetRenderState_CullMode(int); void __stdcall D3DDevice_SetRenderState_ZEnable(int); }
namespace pure3d {
struct LightManager_330e60 { void FUN_00321dc0(int*,int); };
struct ShaderContext { char pad[44]; int mode; void FUN_0032a920(int,unsigned int,unsigned int,int,int); void FUN_00329e50(int,int,int,int); void FUN_00329c90(int,int); };
struct d3dToonVertexShader { char pad0[16]; LightManager_330e60* lightManager; ShaderContext* context; char pad18[32]; int fade; char pad3c[20]; unsigned int color; char pad54[41]; unsigned char alternate; char pad7e[22]; unsigned int vertexShader; unsigned int pixelShader; unsigned int backColor; char pad_a0[64]; int toonMode; char pad_e4[4]; unsigned int edgeValue;
 void FUN_00330de0(); void FUN_00333770(int); void FUN_0032a320(int,int); void FUN_0032a2d0(); void FUN_0032a260(); void vfunc_14(int edge);
};
void d3dToonVertexShader::vfunc_14(int edge) {
 if (!vertexShader) FUN_00330de0();
 float scale=(*(float*)&DAT_0040bbec);
 if (edge) {
  float c[4]; c[0]=(float)((backColor>>16)&255)*scale; c[1]=(float)((backColor>>8)&255)*scale; c[2]=(float)(backColor&255)*scale; c[3]=1.0f;
  if(fade) c[3]=(float)(unsigned int)(255-fade)*scale;
  union { unsigned int bits; float value; } edgeBits; edgeBits.bits=edgeValue;
  float settings[4]={64.0f,0.0f,0.0f,0.0f}; settings[2]=edgeBits.value;
  if(alternate){D3D8::D3DDevice_SetVertexShaderConstant1(0xbc,c);D3D8::D3DDevice_SetVertexShaderConstant1(0xbd,settings);}
  else {D3D8::D3DDevice_SetVertexShaderConstant1(0x6a,c);D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,settings);}
  FUN_00333770(fade!=0);
  D3D8::D3DDevice_SetRenderState_CullMode(0x900);
  return;
 }
 float colorConstant[4];
 colorConstant[0]=(float)((color>>16)&255)*scale;
 colorConstant[1]=(float)((color>>8)&255)*scale;
 colorConstant[2]=(float)(color&255)*scale;
 colorConstant[3]=(float)((color>>24)&255)*scale;
 if(fade) colorConstant[3]=(float)(unsigned int)(255-fade)*colorConstant[3]*scale;
 float options[4]={0.0f,64.0f,0.0f,0.0f};
 if(toonMode==2){FUN_00333770(1);colorConstant[3]=0.0f;}
 int indices[4]; float zeroDir[4]={0,0,0,0}; float zeroColor[4]={0,0,0,0};
 Light lights[3];
 lightManager->FUN_00321dc0(indices,0);
 D3D8::D3DDevice_GetLight(indices[0]==-1?0:indices[0],&lights[0]);
 D3D8::D3DDevice_GetLight(indices[1]==-1?0:indices[1],&lights[1]);
 D3D8::D3DDevice_GetLight(indices[2]==-1?0:indices[2],&lights[2]);
 const float *a=indices[0]==-1?zeroColor:lights[0].color;
 const float *b=indices[2]==-1?zeroColor:lights[1].color;
 const float *c=indices[2]==-1?zeroColor:lights[2].color;
 float luminance[4];
 luminance[0]=a[2]*(*(float*)&DAT_00433e3c)+a[1]*(*(float*)&DAT_00433e38)+a[0]*(*(float*)&DAT_00433e34);
 luminance[1]=b[2]*(*(float*)&DAT_00433e3c)+b[1]*(*(float*)&DAT_00433e38)+b[0]*(*(float*)&DAT_00433e34);
 luminance[2]=c[2]*(*(float*)&DAT_00433e3c)+c[1]*(*(float*)&DAT_00433e38)+c[0]*(*(float*)&DAT_00433e34);
 luminance[3]=0;
 if(alternate) {
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbc,colorConstant);
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbd,options);
  D3D8::D3DDevice_SetVertexShaderConstant1(0xbe,luminance);
 } else {
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6c,indices[0]==-1?zeroDir:lights[0].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6d,indices[1]==-1?zeroDir:lights[1].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6e,indices[2]==-1?zeroDir:lights[2].direction);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6f,luminance);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6a,colorConstant);
  D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,options);
 }
 context->FUN_0032a920(2,pixelShader,vertexShader,0,0);
 context->FUN_00329e50(0,4,1,2);
 context->FUN_00329e50(1,4,1,2);
 FUN_0032a320(0,0);
 if(context->mode!=1){context->mode=1;DAT_0039db90=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db94=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db08|=2;DAT_0039db98=(*(unsigned int*)((char*)&DAT_004d4efc + 4));}
 context->FUN_00329c90(1,2);
 D3D8::D3DDevice_SetRenderState_CullMode(0x901);
 D3D8::D3DDevice_SetRenderState_ZEnable(1);
 FUN_0032a2d0();FUN_0032a260();
}
}
