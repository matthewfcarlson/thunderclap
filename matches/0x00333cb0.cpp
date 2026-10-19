#include "decls/data/platform/xbox/movie.h"

namespace movie {
struct Renderer_333cb0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void vfunc_6(int, int, int, int);
};
struct PlayerBink {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int, int, int, int);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    char pad04[4];
    int field08;
    char pad0c[8];
    Renderer_333cb0* renderer;
    int state;
    void* bink;
    int field20;
    char field24;
    char pad25[3];
    unsigned int field28;
    char field2c;
    void FUN_00333970();
};
} // namespace movie
struct ThisCall_00333ab0 {
    void FUN_00333ab0(int);
};
void __stdcall FUN_00364dc0(unsigned int, void*);
void __cdecl FUN_00334fa0();
void __stdcall FUN_00364da0(void(__cdecl*)());
void* __stdcall FUN_00364fe0(int, int);
void __stdcall FUN_00366b40(void*, int);
void movie::PlayerBink::vfunc_5(int a, int b, int c, int d) {
    ((ThisCall_00333ab0*)(this))->FUN_00333ab0(b);
    field24 = 0;
    if (field28 > 0)
        FUN_00364dc0(field28, &field2c);
    else
        FUN_00364dc0(0, 0);
    DAT_00555ba0 = field08;
    FUN_00364da0(FUN_00334fa0);
    bink = FUN_00364fe0(a, 0xa004000);
    if (bink) {
        FUN_00366b40(bink, 1);
        FUN_00333970();
        vfunc_10(field20);
        int* values = (int*)bink;
        renderer->vfunc_6(values[0], values[1], c, d);
        state = 3;
    } else
        state = 0;
}
