#include "gen/hulkfight.h"

struct Script_1a16b0 {
    char pad[0x14];
    int arg;
    int result;
};
struct Provider_1a16b0 {
    int Make(int, int, int);
};
int GetThing();

bool hulkfight::scenario::LuaAction::vfunc_3(int a, int b) {
    int x = GetThing();
    if (!x)
        return false;
    Script_1a16b0* s = (*(Script_1a16b0 * *)&this->f_1c);
    int edi = s->result;
    if (edi) {
        int edx = s->arg;
        if (edx && !this->f_24) {
            this->f_24 = ((Provider_1a16b0*)x)->Make(edx, edi, 0);
            return true;
        }
    }
    return false;
}
