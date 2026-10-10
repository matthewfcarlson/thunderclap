// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00326b40 @ 0x00326b40
namespace pure3d {
class d3dBase {
  public:
    d3dBase();
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class d3dTexture : public d3dBase {
  public:
    d3dTexture(unsigned int arg);
    unsigned int f04, f08;
    unsigned int f0c, f10, f14, f18;
    char pad1c[0x68 - 0x1c];
    unsigned int f68;
    char pad6c[4];
    unsigned int f70, f74, f78, f7c, f80;
    unsigned char f84;
    char pad85[3];
    unsigned int f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0, fb4, fb8, fbc, fc0;
    unsigned int fc4;
    unsigned int fc8, fcc, fd0, fd4, fd8, fdc, fe0, fe4, fe8;
    unsigned char fec, fed, fee, fef;
    unsigned int ff0, ff4;
};
d3dTexture::d3dTexture(unsigned int arg) : d3dBase() {
    f70 = 0; f74 = 0; f78 = 0; f7c = 0; f80 = 0;
    f84 = 0;
    fb8 = 0; fbc = 0; fc0 = 0;
    f94 = 0; f90 = 0; f8c = 0; f88 = 0;
    fa4 = 0; fa0 = 0; f9c = 0; f98 = 0;
    fb4 = 0; fb0 = 0; fac = 0; fa8 = 0;
    f0c = arg;
    f14 = 0; f18 = 0; f10 = 0;
    f68 = 0;
    ff4 = 0;
    fc8 = 0; fd0 = 0; fd4 = 0; fd8 = 0; fdc = 0; fe0 = 0; fe4 = 0;
    fec = 0; fed = 0; fee = 0;
    fe8 = 0;
    fcc = 1;
    ff0 = 0xf;
    fef = 1;
}
}
