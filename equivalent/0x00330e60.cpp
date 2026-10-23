// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 40/40)
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
// pure3d::d3dToonVertexShader::vfunc_14 @ 0x00330e60
#include "gen/pure3d.h"

#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/pure3d.h"

extern unsigned int DAT_0039db08, DAT_0039db90, DAT_0039db94, DAT_0039db98;
struct Light_330e60 { char pad0[4]; float color[4]; char pad1[44]; float direction[4]; char pad2[24]; };
namespace D3D8 { void __stdcall D3DDevice_GetLight(int,Light_330e60*); void __fastcall D3DDevice_SetVertexShaderConstant1(int,const float*); void __stdcall D3DDevice_SetRenderState_CullMode(int); void __stdcall D3DDevice_SetRenderState_ZEnable(int); }
namespace pure3d {
struct LightManager_330e60 { void FUN_00321dc0(int*,int); };
struct ShaderContext { char pad[44]; int mode; void FUN_0032a920(int,unsigned int,unsigned int,int,int); void FUN_00329e50(int,int,int,int); void FUN_00329c90(int,int); };
struct d3dToonVertexShader_nv_330e60 {
    void FUN_00330de0();
    void FUN_00333770(int);
    void FUN_0032a320(int,int);
    void FUN_0032a2d0();
    void FUN_0032a260();
};

}
void pure3d::d3dToonVertexShader::vfunc_14(int edge) {
 if (!(*(unsigned int *)&this->f_94)) ((d3dToonVertexShader_nv_330e60*)this)->FUN_00330de0();
 float scale=(*(float*)&DAT_0040bbec);
 if (edge) {
  float c[4]; c[0]=(float)(((*(unsigned int *)&this->f_9c)>>16)&255)*scale; c[1]=(float)(((*(unsigned int *)&this->f_9c)>>8)&255)*scale; c[2]=(float)((*(unsigned int *)&this->f_9c)&255)*scale; c[3]=1.0f;
  if(this->f_38) c[3]=(float)(unsigned int)(255-this->f_38)*scale;
  union { unsigned int bits; float value; } edgeBits; edgeBits.bits=(*(unsigned int *)&this->f_e8);
  float settings[4]={64.0f,0.0f,0.0f,0.0f}; settings[2]=edgeBits.value;
  if((*(unsigned char *)&this->f_7d)){D3D8::D3DDevice_SetVertexShaderConstant1(0xbc,c);D3D8::D3DDevice_SetVertexShaderConstant1(0xbd,settings);}
  else {D3D8::D3DDevice_SetVertexShaderConstant1(0x6a,c);D3D8::D3DDevice_SetVertexShaderConstant1(0x6b,settings);}
  ((d3dToonVertexShader_nv_330e60*)this)->FUN_00333770(this->f_38!=0);
  D3D8::D3DDevice_SetRenderState_CullMode(0x900);
  return;
 }
 float colorConstant[4];
 colorConstant[0]=(float)(((*(unsigned int *)&this->f_50)>>16)&255)*scale;
 colorConstant[1]=(float)(((*(unsigned int *)&this->f_50)>>8)&255)*scale;
 colorConstant[2]=(float)((*(unsigned int *)&this->f_50)&255)*scale;
 colorConstant[3]=(float)(((*(unsigned int *)&this->f_50)>>24)&255)*scale;
 if(this->f_38) colorConstant[3]=(float)(unsigned int)(255-this->f_38)*colorConstant[3]*scale;
 float options[4]={0.0f,64.0f,0.0f,0.0f};
 if(this->f_e0==2){((d3dToonVertexShader_nv_330e60*)this)->FUN_00333770(1);colorConstant[3]=0.0f;}
 int indices[4]; float zeroDir[4]={0,0,0,0}; float zeroColor[4]={0,0,0,0};
 Light_330e60 lights[3];
 (*(LightManager_330e60 * *)&this->f_10)->FUN_00321dc0(indices,0);
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
 if((*(unsigned char *)&this->f_7d)) {
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
 (*(ShaderContext * *)&this->f_14)->FUN_0032a920(2,(*(unsigned int *)&this->f_98),(*(unsigned int *)&this->f_94),0,0);
 (*(ShaderContext * *)&this->f_14)->FUN_00329e50(0,4,1,2);
 (*(ShaderContext * *)&this->f_14)->FUN_00329e50(1,4,1,2);
 ((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a320(0,0);
 if((*(ShaderContext * *)&this->f_14)->mode!=1){(*(ShaderContext * *)&this->f_14)->mode=1;DAT_0039db90=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db94=(*(unsigned int*)((char*)&DAT_004d4efc + 4));DAT_0039db08|=2;DAT_0039db98=(*(unsigned int*)((char*)&DAT_004d4efc + 4));}
 (*(ShaderContext * *)&this->f_14)->FUN_00329c90(1,2);
 D3D8::D3DDevice_SetRenderState_CullMode(0x901);
 D3D8::D3DDevice_SetRenderState_ZEnable(1);
 ((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a2d0();((d3dToonVertexShader_nv_330e60*)this)->FUN_0032a260();
}
