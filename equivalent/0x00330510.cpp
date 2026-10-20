// STATUS: equivalent (tools/equiv.py level 3: 19782 inputs, branch coverage 10/10)
// pure3d::d3dToon2VertexShader::vfunc_14 @ 0x00330510
#include "decls/data/platform/xbox/pure3d.h"

struct Context { char pad0[0x2c]; int state2; int state4; char pad1[0x14]; int mode; void FUN_0032a920(int,int,int,int,int); void FUN_00329e50(int,int,int,int); void FUN_00329c90(int,int); void FUN_00329f70(int,int,void*); };
namespace D3D8 { void __fastcall D3DDevice_SetRenderState_Simple(void*,int); }
extern int DAT_0039db08, DAT_0039db90, DAT_0039db94, DAT_0039db98, DAT_0039dc10, DAT_0039dc14, DAT_0039dc18, DAT_0039de18;
namespace pure3d { struct d3dToon2VertexShader { char pad0[0x14]; Context* context; char pad1[0x2c]; int texture; unsigned char flag; char pad2[3]; int mode; char pad3[0x2c]; unsigned char flag2; char pad4[3]; int vertex; int pixel; int extra; void FUN_00330350(); void FUN_003303e0(); void FUN_0032a260(); void vfunc_14(int unused); }; }
void pure3d::d3dToon2VertexShader::vfunc_14(int unused) {
 if (!pixel) FUN_00330350();
 if (!vertex) FUN_003303e0();
 context->FUN_0032a920(3,extra,vertex,pixel,0);
 context->FUN_00329e50(0,4,1,2);
 context->FUN_00329e50(1,4,1,2);
 context->FUN_00329e50(2,4,1,2);
 if (context->state2 != 1) { context->state2=1; DAT_0039db90=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db94=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db08 |= 2; DAT_0039db98=(*(int*)((char*)&DAT_004d4efc + 4)); }
 context->FUN_00329c90(1,2);
 if (context->state4 != 1) { context->state4=1; DAT_0039dc10=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039dc14=(*(int*)((char*)&DAT_004d4efc + 4)); DAT_0039db08 |= 4; DAT_0039dc18=(*(int*)((char*)&DAT_004d4efc + 4)); }
 context->FUN_00329c90(2,texture);
 context->FUN_00329c90(2,2);
 if (context->mode != mode) { context->mode=mode; int value=DAT_004d4f24[mode]; D3D8::D3DDevice_SetRenderState_Simple(((char*)0x0004037c),value); DAT_0039de18=value; }
 context->FUN_00329f70(flag,flag2,&pad3[0]);
 FUN_0032a260();
}