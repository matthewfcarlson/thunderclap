// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// pure3d::d3dBumpMapVertexShader::vfunc_24 @ 0x00332c60
#include "gen/pure3d.h"

namespace D3D8 { void __stdcall D3DDevice_GetLight(unsigned, void*); void __stdcall D3DDevice_GetTransform(unsigned, void*); void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned, const void*); void __fastcall D3DDevice_SetVertexShaderConstant4(unsigned, const void*); }
struct Matrix_332c60 { float v[16]; void FUN_0022ca90(const Matrix_332c60*,const Matrix_332c60*); void FUN_0022cc10(const Matrix_332c60*,const Matrix_332c60*); void FUN_0022c0b0(); void FUN_0022cdb0(); void FUN_0022c310(const float*, float*); };
struct Light_332c60 { char pad[64]; float direction[3]; char rest[196]; };
struct LightSource_332c60 { void FUN_00321dc0(int*,int); };
namespace pure3d {  }
void pure3d::d3dBumpMapVertexShader::vfunc_24() {
 struct Constants { float zero[4]; float direction[4]; float origin[4]; int index; char padding[12]; float out2[4]; float out1[4]; } constants;
 constants.zero[0]=constants.zero[1]=constants.zero[2]=constants.zero[3]=0;
 (*(LightSource_332c60 * *)&this->f_10)->FUN_00321dc0(&constants.index,0);
 Light_332c60 light;
 D3D8::D3DDevice_GetLight(constants.index == -1 ? 0 : constants.index,&light);
 Matrix_332c60 projection, world, view;
 D3D8::D3DDevice_GetTransform(6,&projection);
 D3D8::D3DDevice_GetTransform(0,&world);
 D3D8::D3DDevice_GetTransform(1,&view);
 Matrix_332c60 combined, result;
 combined.FUN_0022ca90(&projection,&world);
 result.FUN_0022cc10(&combined,&view);
 Matrix_332c60 inverse=result;
 inverse.FUN_0022c0b0();
 Matrix_332c60 proj2=projection;
 proj2.FUN_0022c0b0();
 Matrix_332c60 normal=combined;
 normal.FUN_0022cdb0();
 Matrix_332c60 proj3=projection;
 proj3.FUN_0022cdb0();
 constants.direction[0]=-light.direction[0]; constants.direction[1]=-light.direction[1]; constants.direction[2]=-light.direction[2]; constants.direction[3]=0;
 constants.origin[0]=0; constants.origin[1]=0; constants.origin[2]=0; constants.origin[3]=1;
 normal.FUN_0022c310(constants.origin,constants.out1);
 normal.FUN_0022c310(constants.direction,constants.out2);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x75,constants.index == -1 ? constants.zero : constants.out2);
 D3D8::D3DDevice_SetVertexShaderConstant4(0x62,&inverse);
 D3D8::D3DDevice_SetVertexShaderConstant4(0x6d,&proj2);
 D3D8::D3DDevice_SetVertexShaderConstant1(0x78,constants.out1);
}
