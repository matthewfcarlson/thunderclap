#include "decls/address.h"
#include "decls/data/game/global.h"
struct Vector {
    float x, y, z;
};
struct Matrix {
    float elements[16];
    void FUN_0022cdb0();
    void FUN_0022c2b0(Vector*, Vector*);
    void FUN_0022c3b0(Vector*, Vector*);
};
struct MatrixSource_2b5410 {
    Matrix* FUN_0028faa0();
};
struct Gfx {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54(int);
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74(int, int, int);
};
namespace pure3d {
struct ShadowMeshImpl {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    char padding[0x48];
    unsigned int state;
    char padding50[4];
    unsigned char mode;
    char padding55[3];
    Vector first;
    Vector second;
    void FUN_002b4990();
    void FUN_002b3820();
    void FUN_002b4210();
    void FUN_002b3c70();
};
void ShadowMeshImpl::vfunc_6() {
    Matrix matrix = *(*(MatrixSource_2b5410**)&DAT_0052c2b4)->FUN_0028faa0();
    matrix.FUN_0022cdb0();
    if (mode)
        matrix.FUN_0022c2b0(&second, &first);
    else
        matrix.FUN_0022c3b0(&second, &first);
    FUN_002b4990();
    FUN_002b3820();
    DAT_0052c2a8->slot54(2);
    DAT_0052c2a8->slot74(0, 0, 3);
    FUN_002b4210();
    FUN_002b3c70();
    DAT_0052c2a8->slot54(1);
    DAT_0052c2a8->slot74(0, 0, 4);
    FUN_002b4210();
    FUN_002b3c70();
    state = 0;
}
} // namespace pure3d
