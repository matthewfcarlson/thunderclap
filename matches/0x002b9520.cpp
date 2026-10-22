// FUN_002b9520 @ 0x002b9520
// equiv-map: ??0QuadBase@@QAE@XZ = 0x002b8e80

class BillboardQuad_2b9520 {
public:
    BillboardQuad_2b9520() throw();
    virtual void vfunc_0();
    char pad04[0xc8 - 4];
};

namespace pure3d {
class BillboardCutOffQuad : public BillboardQuad_2b9520 {
public:
    int f_c8, f_cc, f_d0, f_d4, f_d8, f_dc, f_e0, f_e4, f_e8, f_ec, f_f0;
    float f_f4, f_f8, f_fc, f_100;
    int f_104, f_108;
    BillboardCutOffQuad() throw();
    virtual void vfunc_0();
};
}

pure3d::BillboardCutOffQuad::BillboardCutOffQuad() throw()
{
    f_c8 = 0;
    f_cc = 0;
    f_d0 = 0;
    f_d4 = 0;
    f_d8 = 0;
    f_dc = 0;
    f_e0 = 0;
    f_e4 = 0;
    f_e8 = 0;
    f_ec = 0;
    f_f0 = 0;
    f_104 = 0;
    f_108 = 0;
    f_f4 = 1.0f;
    f_f8 = 1.0f;
    f_fc = 1.0f;
    f_100 = 1.0f;
}
