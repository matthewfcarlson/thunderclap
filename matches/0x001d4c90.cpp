#include "decls/data/game/global.h"
#include "decls/data/script.h"

// The ScriptHandler singleton (DAT_004e23cc): allocated with ScriptHandler's size (include/decls/data/script.h
// ScriptHandlerView: 0x5494 bytes on 32-bit) and constructed by 0x001d4830.
struct Object {
    Object* FUN_001d4830();
};
void* __cdecl FUN_0008d690(unsigned int);
extern "C" Object* FUN_001d4c90() {
    if (!(*(Object**)&DAT_004e23cc)) {
        HULK_SIZE32(ScriptHandlerView, 0x5494);
        void* memory = FUN_0008d690((int)sizeof(ScriptHandlerView));
        if (memory) {
            (*(Object**)&DAT_004e23cc) = ((Object*)memory)->FUN_001d4830();
            return (*(Object**)&DAT_004e23cc);
        }
        (*(Object**)&DAT_004e23cc) = 0;
    }
    return (*(Object**)&DAT_004e23cc);
}
