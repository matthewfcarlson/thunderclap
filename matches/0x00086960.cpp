#include "decls/data/game/global.h"
// data: gFlag_86960 = DAT_004dd6f0
#include "gen/owners.h"

class Other_86960 {
  public:
    void First();
};
class Thing_86960 {
  public:
    char pad[0x30];
    Other_86960* a;
    Other_86960* b;
    void Run();
};
void Thing_86960::Run() {
    (*(unsigned char*)&DAT_004dd6f0) = 1;
    a->First();
    ((owners::Object_1b83c0 *)b)->FUN_001b83c0();
}