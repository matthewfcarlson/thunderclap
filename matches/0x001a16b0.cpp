#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Script_1a16b0 {
    char pad[0x14];
    int arg;
    int result;
};
struct Provider_1a16b0 {
};
int GetThing();

bool hulkfight::scenario::LuaAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    hulk_intptr x = GetThing();
    if (!x)
        return false;
    Script_1a16b0* s = (*(Script_1a16b0 * *)&this->f_1c);
    int edi = s->result;
    if (edi) {
        int edx = s->arg;
        if (edx && !this->f_24) {
            this->f_24 = ((int)((owners::Object_1d2890 *)(((Provider_1a16b0*)x)))->FUN_001d2890((unsigned int)edx, (unsigned int)edi, 0));
            return true;
        }
    }
    return false;
}
