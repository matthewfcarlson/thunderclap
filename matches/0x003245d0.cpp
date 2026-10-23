#include "gen/pure3d.h"

struct Local_3245d0 {
    unsigned a, b, c;
};
struct Skin_3245d0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(unsigned, Local_3245d0*);
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual bool s22();
    virtual void s23();
    virtual void s24();
    char pad[0x79];
    unsigned char active;
    void FUN_00327d00();
    void FUN_00327d20(int);
};
struct Device_3245d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(int, Local_3245d0*);
    void FUN_00324270(Skin_3245d0*);
};
struct Receiver_3245d0 {
    void FUN_003272f0();
};
namespace pure3d {
} // namespace pure3d
void pure3d::d3dExtHardwareSkinning::vfunc_6(int __p0, int __p1) { Skin_3245d0 * skin = (Skin_3245d0 *)__p0; Receiver_3245d0 * receiver = (Receiver_3245d0 *)__p1;

    Local_3245d0 data;
    (*(Device_3245d0 * *)&this->f_04)->FUN_00324270(skin);
    skin->active = 1;
    (*(Device_3245d0 * *)&this->f_04)->v47(0, &data);
    skin->s9(0x5654494c, &data);
    if (skin->s22())
        skin->s24();
    for (int i = 0; i < skin->s11(); ++i) {
        skin->FUN_00327d00();
        skin->FUN_00327d20(i);
        receiver->FUN_003272f0();
    }
    skin->active = 0;
}
