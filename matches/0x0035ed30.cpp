#include "decls/data/game/om.h"

extern "C" struct Result_35ed30 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Result_35ed30 Hash(const char*);

void FUN_0035ed30() {
    (*(Result_35ed30*)&DAT_004e2768) = Hash("golfBall_golfBall");
}