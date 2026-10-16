#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned int U_3334a0;
struct Context {
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
    virtual void slot54();
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
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual unsigned char query();
    virtual void set(U_3334a0 color, U_3334a0 second, U_3334a0 third);
    virtual void get(U_3334a0* color, U_3334a0* second, U_3334a0* third);
};
namespace pure3d {
struct d3dShader {
    char pad0[16];
    Context* context;
    char pad14[8];
    int mode;
    char pad20[88];
    U_3334a0 color;
    void vfunc_13();
};
void d3dShader::vfunc_13() {
    if (mode == 2 && context->query() == 1) {
        if (!((*(U_3334a0*)&DAT_00555b98) & 1)) {
            (*(U_3334a0*)&DAT_00555b98) |= 1;
            (*(U_3334a0*)&DAT_00555b94) = 0xff000000;
        }
        U_3334a0 oldColor, second, third;
        context->get(&oldColor, &second, &third);
        if (oldColor == (*(U_3334a0*)&DAT_00555b94))
            context->set(color, second, third);
    }
}
} // namespace pure3d
