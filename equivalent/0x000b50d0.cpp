// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 10/10)
// FUN_000b50d0 @ 0x000b50d0
#include "decls/address.h"
#include "gen/owners.h"
class FEObject_b50d0 {
public:
    virtual void v0();
};

class TextSelector_b50d0 : public FEObject_b50d0 {
public:
    char pad04[0x154 - 4];
    int selected;             // 0x154
    char pad158[0x1d58 - 0x158];
    void *items;              // 0x1d58
};

struct Marker_b50d0 {
};

struct Table_b50d0 {
    int FUN_00093260(int idx);
};

struct Message_b50d0 {
    char data[0x20];
};

struct Sink_b50d0 {
    void FUN_001cbc20(Message_b50d0 *msg);
};

struct World {
    char pad0[0x30];
    Sink_b50d0 *sink;               // 0x30
};

FEObject_b50d0 *__cdecl FUN_000fc260(const char *name);
extern "C" void __cdecl FUN_000fc300();

class JumpMarkerHud {
public:
    char pad0[0x34];
    Marker_b50d0 *marker;           // 0x34
    char pad38[0x4c - 0x38];
    Table_b50d0 *table;             // 0x4c
    void FUN_000b50d0();
};

void JumpMarkerHud::FUN_000b50d0()
{
    if (marker == 0 || table == 0)
        return;
    TextSelector_b50d0 *sel = dynamic_cast<TextSelector_b50d0 *>(FUN_000fc260("jump_marker_selector"));
    if (sel == 0 || sel->items == 0)
        return;
    int id = ((owners::C_89960 *)marker)->FUN_00089960(sel->selected);
    if (id == -1)
        return;
    int value = table->FUN_00093260(id);
    ((owners::Obj_899d0 *)marker)->FUN_000899d0((const char *)(hulk_uintptr)(int)value);
    ((owners::Obj_89980 *)marker)->FUN_00089980();
    Message_b50d0 msg;
    ((owners::Result_1cae40 *)&msg)->FUN_001cae40((hulk_uintptr)"JumpMarkerSelected");
    DAT_004dd700->sink->FUN_001cbc20(&msg);
    FUN_000fc300();
}
