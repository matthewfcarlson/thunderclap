#include "gen/fight.h"

struct ScriptReader_nv_23aee0 {
    int helper1(int, int, int);
    int helper2(int, int);
};

int fight::ScriptReader::vfunc_11(int a, int b, int c) {
    int x = ((ScriptReader_nv_23aee0*)this)->helper1(a, b, 3);
    return ((ScriptReader_nv_23aee0*)this)->helper2(x, c);
}
