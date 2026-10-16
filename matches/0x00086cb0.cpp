#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
struct Reset_86cb0 {
    void FUN_00024800();
};
struct World {
    char pad[0x20];
    Reset_86cb0* reset;
};
struct UI_86cb0 {
    void FUN_0023f720(int*, int);
    bool FUN_0023f760(const char*, int, int);
    void FUN_0023f740();
};
struct Check_86cb0 {
    bool FUN_0008db70();
};
struct Mode_86cb0 {
    int kind;
};
struct Special_86cb0 {
    void FUN_001b7d10(int, int);
};
struct Draw {
    void FUN_001b93a0(Mode_86cb0*, int, int, int, int, int);
};
struct Memory_86cb0 {
    void FUN_0008d0a0();
};
extern Memory_86cb0* __stdcall FUN_0008ceb0(int);
extern void __cdecl FUN_000969c0(int);
extern void __cdecl FUN_00096740();
struct Target_86cb0 {
    int field0;
    Mode_86cb0* mode;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    Check_86cb0* check;
    int field20;
    Draw* draw;
    int field28;
    int field2c;
    int field30;
    Special_86cb0* special;
    int field38;
    void FUN_00086cb0();
};
void Target_86cb0::FUN_00086cb0() {
    if (DAT_004dd700)
        DAT_004dd700->reset->FUN_00024800();
    if (!DAT_0049c0d8)
        return;
    if (!check->FUN_0008db70())
        return;
    if (mode->kind == 4)
        FUN_000969c0(0);
    if (DAT_0049caa0 && mode->kind == 7) {
        special->FUN_001b7d10(field14, field18);
    } else {
        (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f720(&DAT_0049c108, 0);
        if ((*(unsigned char*)&DAT_004dd83e) || (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f760("Display Memory Usage", 0x4d, 0)) {
            FUN_0008ceb0(0)->FUN_0008d0a0();
        }
        (*(UI_86cb0**)&DAT_004dd6e8)->FUN_0023f740();
        draw->FUN_001b93a0(mode, fieldc, field20, field2c, field38, field28);
    }
    if ((*(unsigned char*)&DAT_004dd8e4))
        FUN_00096740();
}
