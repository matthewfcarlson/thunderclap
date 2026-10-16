// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000447b0 @ 0x000447b0
#include "decls/data/game/global.h"

extern "C" int __cdecl strcmp(const char*, const char*);
class Config_447b0 {
public:
    char pad0[0x1b0];
    int mode;
    void FUN_000447b0(const char* name);
};
void Config_447b0::FUN_000447b0(const char* name) {
    if (!name)
        return;
    for (int i = 0; i < 4; i++) {
        if (strcmp(name, ((const char**)&DAT_0048f6a4)[i]) == 0) {
            mode = i;
            return;
        }
    }
}
