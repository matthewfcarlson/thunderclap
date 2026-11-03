#include "gen/fight.h"

struct ScriptReader_nv_23afe0 {
    int first(int, int, int);
};

void fight::ScriptReader::vfunc_8(int a, int b, int c, int d) {
    int x = ((ScriptReader_nv_23afe0*)this)->first(a, b, 4);
    ((fight::ScriptReader *)(((ScriptReader_nv_23afe0*)this)))->FUN_0023ad30(x, (char *)(hulk_uintptr)(int)c, d);
}
