// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00250640 @ 0x00250640
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"

extern "C" int __cdecl FUN_00246f50(char *, const char *, ...);
struct Context { int FUN_00261e60(char **); };
int __cdecl FUN_00250640(char **buffer, int value, Context *context) {
    int result = FUN_00246f50(*buffer, ((char*)&DAT_004298a8), value);
    if ((unsigned char)result != 0) {
        result = context->FUN_00261e60(buffer);
        if ((unsigned char)result != 0)
            return FUN_00246f50(*buffer, ((char*)&DAT_00422518));
    }
    return result & 0xffffff00;
}