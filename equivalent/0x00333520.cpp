// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00333520 @ 0x00333520
struct Owner_333520 { char pad[0x150]; unsigned value; };
struct FUN_00327e00 { virtual void slot(); char pad[12]; FUN_00327e00(); };
namespace pure3d {
struct d3dShader : ::FUN_00327e00 {
 Owner_333520* owner; unsigned ownerValue;
 unsigned a18,a1c,a20,a24; unsigned char a28; char pad29[3];
 unsigned a2c; float a30,a34; unsigned a38,a3c,a40,a44;
 unsigned char a48; char pad49[3]; unsigned a4c,a50,a54,a58,a5c,a60,a64,a68,a6c,a70,a74; float a78; unsigned char a7c,a7d;
 virtual void slot();
 d3dShader(Owner_333520*);
};
d3dShader::d3dShader(Owner_333520* p) {
 owner=p; ownerValue=p->value;
 a50=a54=a5c=a64=a68=a70=0xff000000;
 a3c=0; a48=0; a60=0; a18=0; a1c=0; a24=0; a28=0; a38=0; a7c=0; a7d=0;
 a40=1; a44=1; a4c=1; a58=0xffffffff; a6c=0xffffffff; a20=1; a2c=5; a30=0.5f; a34=0.5f; a78=127.998046875f;
}
}