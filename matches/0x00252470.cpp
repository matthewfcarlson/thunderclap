#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
// data: fmt = DAT_004298a8

extern "C" unsigned char __cdecl FUN_00246f50(const char*, const char*, ...);
extern "C" unsigned char __cdecl FUN_0025abf0(const char**, const char*);
unsigned char __cdecl FUN_00252470(const char** text, const char* value, const char** other) {
    const char* s = *text;
    if (FUN_00246f50(s, DAT_004298a8, value)) {
        if (FUN_0025abf0(text, *other)) {
            value = *text;
            return FUN_00246f50(value, DAT_00422518);
        }
    }
    return 0;
}