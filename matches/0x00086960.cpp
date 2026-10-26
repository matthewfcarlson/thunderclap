#include "decls/data/game/global.h"
// data: gFlag_86960 = DAT_004dd6f0

class Other_86960 {
  public:
    void First();
    void Second();
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
    b->Second();
}