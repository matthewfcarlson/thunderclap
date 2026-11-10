#include "decls/data/game/global.h"
#include "decls/data/script.h"

// The ScriptHandler singleton (DAT_004e23cc): allocated with ScriptHandler's size (include/decls/data/script.h
// ScriptHandlerView: 0x5494 bytes on 32-bit) and constructed by 0x001d4830.
struct ScriptHandler_1d4c90 {
    ScriptHandler_1d4c90* FUN_001d4830();
};
void* __cdecl FUN_0008d690(unsigned int);
extern "C" ScriptHandler_1d4c90* FUN_001d4c90() {
    if (!(*(ScriptHandler_1d4c90**)&DAT_004e23cc)) {
        HULK_SIZE32(ScriptHandlerView, 0x5494);
        void* memory = FUN_0008d690((int)sizeof(ScriptHandlerView));
        if (memory) {
            (*(ScriptHandler_1d4c90**)&DAT_004e23cc) = ((ScriptHandler_1d4c90*)memory)->FUN_001d4830();
            return (*(ScriptHandler_1d4c90**)&DAT_004e23cc);
        }
        (*(ScriptHandler_1d4c90**)&DAT_004e23cc) = 0;
    }
    return (*(ScriptHandler_1d4c90**)&DAT_004e23cc);
}
