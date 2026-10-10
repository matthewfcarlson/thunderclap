// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 24/24)
// pure3d::d3dSpheremapVertexShader::vfunc_14 @ 0x00331910
typedef unsigned int U;
extern U DAT_0039db08,DAT_0039db10,DAT_0039db14,DAT_0039db18,DAT_0039db60,DAT_0039db90,DAT_0039db94,DAT_0039db98,DAT_0039dbcc,DAT_0039dc4c,DAT_0039dc5c,DAT_0039de18;
extern U DAT_004d4efc[]; extern U DAT_004d4f24[];
namespace D3D8 { void __stdcall D3DDevice_SetTexture(U,U); void __stdcall D3DDevice_SetPalette(U,U); void __fastcall D3DDevice_SetRenderState_Simple(U,U); }
struct Texture { void FUN_00326b00(U); };
struct Device {
 char p0[8]; U tex0,tex1; char p10[0x18]; U mode0,mode1; char p30[0x18]; U renderMode; char p4c[0x4c]; U stage0; U stage1; char pa0[0x2c]; U stage2; char pd0[0x14]; U stateE4; char pe8[0x20]; U factor;
 void FUN_00329e50(U,U,U,U);
 void FUN_00329cf0(U,U,U);
 void FUN_00329c90(U,U);
 void FUN_00329da0(U,U,U);
 void FUN_00329bb0(U);
 void FUN_00329f70(U,U,void*);
 void D3DDevice_SetRenderState_TextureFactor(U);
};
struct pure3d { struct d3dSpheremapVertexShader {
 char pad0[0x14]; Device *device; char pad18[0x20]; U alpha; char pad3c[4]; U mode; U setting; unsigned char flag; char pad49[3]; U renderMode; char pad50[0x2c]; unsigned char flag2; char pad7d[3]; Texture* tex0; Texture* tex1; U color;
 void FUN_0032a320(U,U); void FUN_0032a260(); void vfunc_14(U);
 };};
void pure3d::d3dSpheremapVertexShader::vfunc_14(U unused) {
 U ec=color, a=alpha;
 U factor=(((0xff-a)*(ec >> 8 & 0xffff0000) ^ ec) & 0xffffff) ^ ((0xff-a)*(ec >> 8 & 0xff0000));
 Device *d=device;
 if(d->factor!=factor) {d->factor=factor; d->D3DDevice_SetRenderState_TextureFactor(factor);}
 device->FUN_00329e50(0,4,0,2);
 d=device;
 if(d->mode0!=mode){d->mode0=mode; U v=DAT_004d4efc[mode]; DAT_0039db10=v; DAT_0039db14=v; DAT_0039db08|=1; DAT_0039db18=v;}
 d=device;
 if(d->stateE4!=5){d->stateE4=5; DAT_0039db08|=0x800; DAT_0039db60=5;}
 d=device;
 if(d->tex0!=(U)tex0){Texture* t=tex0; d->tex0=(U)t; if(t) t->FUN_00326b00(0); else {D3D8::D3DDevice_SetTexture(0,0); D3D8::D3DDevice_SetPalette(0,0);}}
 FUN_0032a320(0,0);
 d=device; d->FUN_00329cf0(1,4,3);
 if(d->stage0!=2){d->stage0=2; DAT_0039db08|=0x800; DAT_0039dbcc=2;}
 d=device;
 if(d->mode1!=1){d->mode1=1; U v=DAT_004d4efc[1]; DAT_0039db90=v; DAT_0039db94=v; DAT_0039db08|=2; DAT_0039db98=v;}
 device->FUN_00329c90(1,setting);
 d=device;
 if(d->tex1!=(U)tex1){Texture* t=tex1; d->tex1=(U)t; if(t) t->FUN_00326b00(1); else {D3D8::D3DDevice_SetTexture(1,0); D3D8::D3DDevice_SetPalette(1,0);}}
 d=device; d->FUN_00329cf0(2,0x12,5);
 if(d->stage1!=1){d->stage1=1; DAT_0039db08|=0x800; DAT_0039dc4c=1;}
 d=device; d->FUN_00329da0(2,4,1);
 if(d->stage2!=5){d->stage2=5; DAT_0039db08|=0x800; DAT_0039dc5c=5;}
 device->FUN_00329bb0(3);
 d=device;
 if(d->renderMode!=renderMode){d->renderMode=renderMode; U v=DAT_004d4f24[renderMode]; D3D8::D3DDevice_SetRenderState_Simple(0x4037c,v); DAT_0039de18=v;}
 device->FUN_00329f70(flag,flag2,&pad50);
 FUN_0032a260();
}
