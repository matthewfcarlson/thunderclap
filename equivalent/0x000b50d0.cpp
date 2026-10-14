// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000b50d0 @ 0x000b50d0
class FEObject {
public:
    virtual void v0();
};

class TextSelector : public FEObject {
public:
    char pad04[0x154 - 4];
    int selected;             // 0x154
    char pad158[0x1d58 - 0x158];
    void *items;              // 0x1d58
};

struct Marker {
    int FUN_00089960(int id);
    void FUN_000899d0(int v);
    void FUN_00089980();
};

struct Table {
    int FUN_00093260(int idx);
};

struct Message {
    char data[0x20];
    void FUN_001cae40(const char *name);
};

struct Sink {
    void FUN_001cbc20(Message *msg);
};

struct Globals {
    char pad0[0x30];
    Sink *sink;               // 0x30
};
extern Globals *DAT_004dd700;

FEObject *__cdecl FUN_000fc260(const char *name);
void __cdecl FUN_000fc300();

class JumpMarkerHud {
public:
    char pad0[0x34];
    Marker *marker;           // 0x34
    char pad38[0x4c - 0x38];
    Table *table;             // 0x4c
    void FUN_000b50d0();
};

void JumpMarkerHud::FUN_000b50d0()
{
    if (marker == 0 || table == 0)
        return;
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260("jump_marker_selector"));
    if (sel == 0 || sel->items == 0)
        return;
    int id = marker->FUN_00089960(sel->selected);
    if (id == -1)
        return;
    marker->FUN_000899d0(table->FUN_00093260(id));
    marker->FUN_00089980();
    Message msg;
    msg.FUN_001cae40("JumpMarkerSelected");
    DAT_004dd700->sink->FUN_001cbc20(&msg);
    FUN_000fc300();
}
