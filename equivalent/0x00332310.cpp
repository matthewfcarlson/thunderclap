// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 40/42, incomplete)
// pure3d::d3dBuildingShader::vfunc_14 @ 0x00332310
namespace D3D8 { void __stdcall D3DDevice_SetTexture(unsigned int, void*); void __stdcall D3DDevice_SetPalette(unsigned int, unsigned int); void __stdcall D3DDevice_SetTextureState_TexCoordIndex(unsigned int, unsigned int); void __fastcall D3DDevice_SetRenderState_Simple(unsigned int, unsigned int); }
extern unsigned int DAT_0039db08; extern unsigned int DAT_0039db4c[]; extern unsigned int DAT_0039db64[]; extern unsigned int DAT_0039de18; extern unsigned int DAT_004d4f24[];
struct Texture { void FUN_00326b00(unsigned int); };
struct Context { char pad0[8]; Texture* textures[4]; unsigned int coord[4]; char pad28[0x20]; unsigned int renderMode; char pad4c[0x48]; unsigned int filter[4]; char padA4[0x50]; unsigned int coordMode[4]; void FUN_00329cf0(unsigned int,unsigned int,unsigned int); void FUN_00329da0(unsigned int,unsigned int,unsigned int); void FUN_00329d50(unsigned int,unsigned int,unsigned int,unsigned int); void FUN_00329c40(unsigned int,unsigned int); void FUN_00329c90(unsigned int,unsigned int); void FUN_00329f20(unsigned int); void FUN_00329bb0(unsigned int); void FUN_00329f70(unsigned int,unsigned int,void*); };
namespace pure3d { struct d3dBuildingShader { char pad0[0x14]; Context* context; char pad18[4]; unsigned int effect; char pad20[0x18]; unsigned int intensity; char pad3c[8]; unsigned int texCoord; unsigned char disabled; char pad49[3]; unsigned int renderMode; unsigned int color[11]; unsigned char flag; char pad7d[3]; Texture* base; Texture* detail; Texture* extra; unsigned char skipDetail; void FUN_0032a320(unsigned int,unsigned int); void FUN_0032a260(); void vfunc_14(unsigned int); }; }
void pure3d::d3dBuildingShader::vfunc_14(unsigned int) {
 unsigned int stage=0; const unsigned int two=2;
 if(base) {
  Context* c=context; c->FUN_00329cf0(0,4,0);
  if(c->filter[0]!=two) { c->filter[0]=two; DAT_0039db08|=0x800; DAT_0039db4c[0]=two; }
  context->FUN_00329da0(0,two,two);
  c=context; Texture* t=base;
  if(c->textures[0]!=t) { c->textures[0]=t; if(t) t->FUN_00326b00(0); else { D3D8::D3DDevice_SetTexture(0,0); D3D8::D3DDevice_SetPalette(0,0); } }
  FUN_0032a320(0,0); stage=1;
 }
 if(extra && !skipDetail) {
  context->FUN_00329d50(stage,0x14,1,two);
  context->FUN_00329da0(stage,two,1);
  Context* c=context; Texture* t=extra;
  if(c->textures[stage]!=t) { c->textures[stage]=t; if(t) t->FUN_00326b00(stage); else { D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); } }
  FUN_0032a320(stage,0); ++stage;
 }
 if(detail) {
  Context* c=context; c->FUN_00329cf0(stage,0x14,1);
  if(c->filter[stage]!=two) { c->filter[stage]=two; DAT_0039db08|=0x800; DAT_0039db4c[stage*32]=two; }
  context->FUN_00329da0(stage,two,1);
  c=context; Texture* t=detail;
  if(c->textures[stage]!=t) { c->textures[stage]=t; if(t) t->FUN_00326b00(stage); else { D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); } }
  c=context; if(c->coord[stage]!=0x30000) { c->coord[stage]=0x30000; D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage,0x30000); }
  c=context; if(c->coordMode[stage]!=two) { c->coordMode[stage]=two; DAT_0039db08|=0x400; DAT_0039db64[stage*32]=two; }
  context->FUN_00329c40(stage,1); context->FUN_00329c90(stage,texCoord); ++stage;
 }
 if(!disabled && intensity && effect>=1 && effect<=7 && effect!=6) {
  unsigned int v=intensity;
  if(effect==1) { context->FUN_00329cf0(stage,two,1); context->FUN_00329f20((0u-v)<<24); context->FUN_00329da0(stage,two,3); }
  else { unsigned int x=(effect==2)?(255-v):v; unsigned int rgb=(x<<16)|(x<<8)|x; context->FUN_00329f20(rgb); context->FUN_00329d50(stage,4,1,3); context->FUN_00329da0(stage,two,1); }
  Context* c=context; if(c->textures[stage]) { c->textures[stage]=0; D3D8::D3DDevice_SetTexture(stage,0); D3D8::D3DDevice_SetPalette(stage,0); }
  FUN_0032a320(stage,0); ++stage;
 }
 context->FUN_00329bb0(stage);
 Context* c=context; if(c->renderMode!=renderMode) { c->renderMode=renderMode; unsigned int val=DAT_004d4f24[renderMode]; D3D8::D3DDevice_SetRenderState_Simple(0x4037c,val); DAT_0039de18=val; }
 context->FUN_00329f70(disabled,flag,color); FUN_0032a260();
}