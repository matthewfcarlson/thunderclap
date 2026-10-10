// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 10/10)
// pure3d::d3dTexture::vfunc_14 @ 0x00326a10
namespace XGRAPHC {
void __stdcall XGSwizzleRect(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __stdcall XGSwizzleBox(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
}
// equiv-conv: FUN_00325f30 eax
int FUN_00325f30(int format);
void __cdecl FUN_0008d330(unsigned);

namespace pure3d {
class d3dTexture {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void vfunc_14(int unused);
    char pad04[0x0c];
    unsigned f10, f14, f18;
    char pad1c[4];
    unsigned f20;
    char pad24[8];
    unsigned f2c, f30;
    char pad34[0x10];
    unsigned f44, f48, f4c;
    char pad50[0x0c];
    unsigned f5c, f60, f64;
    char pad68[0x84];
    unsigned char fEc, fEd;
    char padEE[6];
    unsigned fF4;
};

void d3dTexture::vfunc_14(int) {
    if (f10 == 0 && !fEc && !fEd) {
        if (f14 != 0) {
            int bytesPerPixel = FUN_00325f30(f30) >> 3;
            XGRAPHC::XGSwizzleRect((fF4 + 0xf) & 0xfffffff0, 0, 0, f20, f44, f48, 0, bytesPerPixel);
        } else if (f18 != 0) {
            int bytesPerPixel = FUN_00325f30(f4c) >> 3;
            XGRAPHC::XGSwizzleBox((fF4 + 0xf) & 0xfffffff0, 0, 0, 0, f2c, f5c, f60, f64, 0, bytesPerPixel);
        }
        FUN_0008d330(fF4);
        fF4 = 0;
    }
}
}
