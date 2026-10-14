// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b8e80 @ 0x002b8e80
struct Matrix { char data[64]; void FUN_0022b980(); };
struct Base {
 virtual void slot0();
 int reserved04,reserved08,reserved0c;
 int x10,x14,x18,x1c,x20,x24,x28,x2c,x30,x34;
 Base();
};
namespace pure3d {
struct BillboardQuad : Base {
 bool enabled; char pad39[3]; int index;
 Matrix matrix;
 float scaleX,scaleY; int zero88; bool flag; char pad8d[3]; int mode,zero94;
 float a98,a9c,aa0,aa4,aa8,aac,ab0,ab4,ab8,abc;
 int c0,c4;
 virtual void slot0();
 BillboardQuad();
};
BillboardQuad::BillboardQuad() {
 enabled=true; index=-1;
 scaleX=1.0f; scaleY=1.0f; zero88=0; flag=true; mode=1; zero94=0; c0=0; c4=0;
 matrix.FUN_0022b980();
 a98=0.0f; a9c=0.0f; aa0=0.0f; aa4=1.0f; aa8=1.0f; aac=1.0f; ab0=1.0f; ab4=0.0f; ab8=0.0f; abc=0.0f;
 x1c=0; x20=0; x24=0; x10=0; x14=0; x18=0; x28=0; x2c=0; x30=0; x34=0;
}
}