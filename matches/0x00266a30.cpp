#include "gen/owners.h"
typedef unsigned int uint_266a30;
struct Stream {
    uint_266a30 FUN_00263fc0();
};
struct Entry_266a30 {
    uint_266a30 value;
    uint_266a30 second;
    uint_266a30 third;
    uint_266a30 position;
};
struct Object {
    char prefix[0x70];
    Entry_266a30 entries[33];
    uint_266a30 index;
    Stream* stream;
    uint_266a30 FUN_00266a30();
};
uint_266a30 Object::FUN_00266a30() {
    ++index;
    if (index != 0) {
        uint_266a30 end = entries[index].second + entries[index].position;
        if (stream->FUN_00263fc0() < end) {
            uint_266a30 current = stream->FUN_00263fc0();
            ((owners::S_264510 *)stream)->FUN_00264510((unsigned)(end - current));
        }
    }
    uint_266a30 pos = stream->FUN_00263fc0();
    entries[index + 1].position = pos;
    uint_266a30 value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].value = value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].second = value;
    ((owners::X_2647e0 *)stream)->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    entries[index + 1].third = value;
    return entries[index + 1].value;
}