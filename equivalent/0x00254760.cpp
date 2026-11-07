// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254760 @ 0x00254760
#include "gen/audio.h"
#include "gen/owners.h"
#include "decls/data/records.h"

struct Id64 { unsigned int low, high; };
struct Temp { char data[32];   };
extern "C" Id64 __cdecl FUN_002672f0(const char*, int, int);
inline void* operator new(unsigned int, void* place) { return place; }
struct SeqEventSilenceType_nv_254760 {
    void FUN_002605e0(Temp*, const Id64*, int, int);
};

audio::SeqEventSilenceType* audio::SeqEventSilenceType::FUN_00254760() {
    HULK_SIZE32(AudioSeqEventSilence, 0x10);
    Id64 id = FUN_002672f0("SeqEventSilence", 0, 0);
    Temp temp;
    ((SeqEventSilenceType_nv_254760*)this)->FUN_002605e0(((Temp *)((owners::String_23fc40 *)&temp)->FUN_0023fc40("Silnce", (hulk_intptr)0)), &id, (int)sizeof(AudioSeqEventSilence), (int)__alignof(AudioSeqEventSilence));
    ((owners::Str_240060 *)&temp)->FUN_00240060();
    new (this) audio::SeqEventSilenceType;
    return (audio::SeqEventSilenceType*)(this);
}
