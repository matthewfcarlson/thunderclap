#include "decls/data/game/global.h"
// data: gState_1ebc80 = DAT_004e36d8, sDialogue = DAT_00424220, sObjects = DAT_00424208
#include "gen/owners.h"

class Builder {
  public:
    void Add(const char*);
};
class Runner_1ebc80 {
  public:
    void Run(void*, void*, const char*, float);
};
class State_1ebc80 {
  public:
    Runner_1ebc80* runner;
    char pad[4];
    char enabled;
};
void __stdcall target(void* param1, const char* param2) {
    char local[72];
    if (!param1)
        return;
    if (!param2)
        return;
    if (!*param2)
        return;
    Builder* b = (Builder*)local;
    ((owners::Obj_1ef320 *)b)->FUN_001ef320();
    b->Add(DAT_00424208);
    b->Add(DAT_00424220);
    b->Add(DAT_0042424c);
    State_1ebc80* s = (*(State_1ebc80**)&DAT_004e36d8);
    if (s->enabled)
        s->runner->Run(local, (char*)param1 + 8, param2, 100.0f);
    ((owners::C_1ef350 *)b)->FUN_001ef350();
}