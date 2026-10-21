// STATUS: equivalent (tools/equiv.py level 3: 574 inputs, branch coverage 4/4)
// FUN_0027dca0 @ 0x0027dca0
#include "decls/data/game/global.h"

struct Id64_27dca0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af50();
    void FUN_0027af70(Id64_27dca0 *src);
    Id64_27dca0 *FUN_0027b0e0(const char *name);
};


class Chain_27dca0;

class Handler_27dca0 {
public:
    virtual void vfunc_0(Id64_27dca0 *id, Chain_27dca0 *chain);
};

class Chain_27dca0 {
public:
    char pad00[0x90];
    int count;                  // 0x90
    Handler_27dca0 *handlers[1];       // 0x94
    void FUN_0027dca0();
};

void Chain_27dca0::FUN_0027dca0()
{
    Id64_27dca0 id;
    Id64_27dca0 empty;

    id.FUN_0027af00();
    empty.FUN_0027b0e0(((char*)&DAT_003f335c));
    id.FUN_0027af70(&empty);
    empty.FUN_0027af50();

    for (int i = 0; i < count; i++)
        handlers[i]->vfunc_0(&id, this);

    id.FUN_0027af50();
}
