// FUN_000b8e70 @ 0x000b8e70
#include "gen/owners.h"
class FEObject_b8e70 {
public:
    virtual void v0();
};

class TextSelector_b8e70 : public FEObject_b8e70 {
public:
    char pad4[0x154 - 4];
    int selection;          // 0x154
    char pad158[0x1d58 - 0x158];
    void *items;            // 0x1d58
};

class MapThing_b8e70 : public FEObject_b8e70 {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void SetMarker(int marker);     // slot 11
};

FEObject_b8e70 *__cdecl FUN_000fc260(const char *name);

struct MarkerIndex {
};

struct MarkerTable {
    int FUN_00093260(int index);
};

class JumpMarkers {
public:
    char pad0[0x34];
    MarkerIndex *index;     // 0x34
    char pad38[0x4c - 0x38];
    MarkerTable *table;     // 0x4c

    void FUN_000b8e70(int unused);
};

void JumpMarkers::FUN_000b8e70(int unused)
{
    if (table == 0)
        return;
    TextSelector_b8e70 *selector = dynamic_cast<TextSelector_b8e70 *>(FUN_000fc260("jump_marker_selector"));
    if (selector == 0 || selector->items == 0)
        return;
    int i = ((owners::C_89960 *)index)->FUN_00089960(selector->selection);
    if (i == -1)
        return;
    int marker = table->FUN_00093260(i);
    MapThing_b8e70 *map = dynamic_cast<MapThing_b8e70 *>(FUN_000fc260("jump_marker_map"));
    if (map != 0)
        map->SetMarker(marker);
}
