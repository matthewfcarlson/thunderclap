// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 20/20)
// FUN_000bcf40 @ 0x000bcf40
#include "decls/address.h"
class Input_bcf40 {
  public:
    char FUN_00099740();
    char FUN_00099790();
    char FUN_00099750();
};
class World {
  public:
    char head[8];
    Input_bcf40* input;
};
class Widget_bcf40 {
  public:
    char FUN_001b8b30();
};
struct State_bcf40 {
    int id;
};
extern char DAT_004ddbe1;
char __cdecl FUN_000c5ef0(int who, int a, int b, int c, int d, int e);
char __cdecl FUN_000c5d60(int who, int a);

class Menu_bcf40 {
  public:
    char pad0[0x30];
    State_bcf40* current;
    char pad1[0x54 - 0x34];
    Widget_bcf40* widget;
    void FUN_000b5a80();
    void FUN_000b5ad0();
    void FUN_000b5b50();
    void FUN_000b5b90();
    void FUN_000bcbf0();
    void FUN_000b99b0();
    void FUN_000b7490();
    void FUN_000b7590();
    void FUN_000b7660();
    void FUN_000b8d00();
    void FUN_000b76c0();
    void FUN_000bc1e0(const char* name);
    void FUN_000bcf40(int who);
};

void Menu_bcf40::FUN_000bcf40(int who) {
    if (current->id == 7)
        return;
    Input_bcf40* in = DAT_004dd700->input;
    if (in->FUN_00099740())
        return;
    if (in->FUN_00099790())
        return;
    if (in->FUN_00099750())
        return;
    if (widget != 0 && widget->FUN_001b8b30())
        return;
    if (DAT_004ddbe1) {
        char r = FUN_000c5ef0(who, 2, 7, -1, -1, -1);
        if (r)
            return;
        DAT_004ddbe1 = 0;
        return;
    }
    if (FUN_000c5ef0(who, 2, 5, -1, -1, -1))
        return;
    if (!FUN_000c5d60(who, 4))
        return;
    FUN_000b5a80();
    FUN_000b5ad0();
    FUN_000b5b50();
    FUN_000b5b90();
    FUN_000bcbf0();
    FUN_000b99b0();
    FUN_000b7490();
    FUN_000b7590();
    FUN_000b7660();
    FUN_000b8d00();
    FUN_000b76c0();
    FUN_000bc1e0("pause");
}
