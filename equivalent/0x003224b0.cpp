// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_003224b0 @ 0x003224b0
namespace pure3d {
struct d3dExtFramebufferEffects {
 virtual void slot0();
 unsigned int owner; // 04
 unsigned int f08, f0c;
 unsigned char f10; char pad11[3];
 float f14;
 unsigned int f18;
 unsigned char f1c; char pad1d[3];
 unsigned int f20;
 unsigned int table[16];
 unsigned int f64;
 float f68, f6c, f70, f74, f78;
 unsigned char f7c, f7d; char pad7e[2];
 float f80, f84, f88;
 unsigned int f8c,f90,f94,f98,f9c,fa0,fa4,fa8,fac,fb0;
 unsigned char fb4; char padb5[3];
 unsigned int fb8;
 float fbc,fc0;
 unsigned int fc4,fc8;
 float fcc,fd0,fd4;
 char padd8[4];
 int fdc;
 float fe0;
 unsigned int fe4;
 float fe8;
 unsigned char fec;
 d3dExtFramebufferEffects(unsigned int value);
};
d3dExtFramebufferEffects::d3dExtFramebufferEffects(unsigned int value) {
 owner=value;
 f08=f0c=0; f10=0; f18=0; f1c=0; f20=0;
 f68=1.0f; f70=1.0f; f6c=0.0f; f78=1.0f;
 f14=0.9f; f74=0.5f;
 f80=f84=f88=1.0f;
 f7c=f7d=0; f64=0;
 for(int i=0;i<16;++i) table[i]=0;
 fdc=-1; fe0=1.0f; fe4=0; fe8=1.0f;
 fc0=fd0=fd4=fbc=1.0f;
 f8c=f90=f94=f98=f9c=fa0=fac=fb0=fa8=0;
 fb4=0; fa4=fc4=fc8=fb8=0;
 fcc=0.5f; fec=1;
}
}
