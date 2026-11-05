// FUN_001ebe10 @ 0x001ebe10
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct StringList_1ebe10 {
    char data[0x48];
    void FUN_001ef370(const char *s);
    void FUN_001ef390(unsigned __int64 id);
};

struct EventSink_1ebe10 {
    void *handler;
    bool FUN_001efe20(StringList_1ebe10 *args, const void *where, int name, float delay);
};

struct EventConfig_1ebe10 {
    EventSink_1ebe10 *sink;
    char pad04[4];
    char enabled;
};

struct Registry_1ebe10 {
};

struct Source_1ebe10 {
    char pad00[0x5c];
    int key;
};

struct Owner_1ebe10 {
    char pad00[0x4c];
    Registry_1ebe10 *registry;
};

class Emitter_1ebe10 {
public:
    Owner_1ebe10 *owner;
    void Emit(Source_1ebe10 *source, const void *where, hulk_intptr name);
};


void Emitter_1ebe10::Emit(Source_1ebe10 *source, const void *where, hulk_intptr name)
{
    if (source == 0)
        return;
    StringList_1ebe10 path;
    ((owners::Obj_1ef320 *)&path)->FUN_001ef320();
    path.FUN_001ef370("Objects");
    path.FUN_001ef370("Props");
    path.FUN_001ef390(((owners::Obj_79530 *)(owner->registry))->FUN_00079530(source->key));
    if ((*(EventConfig_1ebe10**)&DAT_004e36d8)->enabled)
        (*(EventConfig_1ebe10**)&DAT_004e36d8)->sink->FUN_001efe20(&path, where, name, 100.0f);
    ((owners::C_1ef350 *)&path)->FUN_001ef350();
}
