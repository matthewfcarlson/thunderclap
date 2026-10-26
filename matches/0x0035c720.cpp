#include "decls/data/game/global.h"

extern "C" struct Result_35c720 {
    int a;
    int b;
};
extern "C" Result_35c720 __cdecl FUN_0027b020(const char* name);
void FUN_0035c720() {
    Result_35c720 r = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004dc088) = r.a;
    (*(int*)&DAT_004dc08c) = r.b;
}
