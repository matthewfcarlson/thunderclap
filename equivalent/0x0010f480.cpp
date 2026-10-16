// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 35/38, incomplete)
// hulkfight::ai::AIHistoryNameCondition::vfunc_6 @ 0x0010f480
#include "decls/data/game/hulkfight/ai.h"

extern "C" int atexit(void (*)());

struct Key_10f480 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027af70(Key_10f480 *src);
    void FUN_0027b040(int word);
    char FUN_0027af90(Key_10f480 *other);
};

void FUN_00363ee0();
void FUN_00363ed0();

struct Fighter_10f480 {
    char pad0[0x1b98];
    Key_10f480 history;             // 0x1b98
    int count;               // 0x1ba0
};

struct Holder_10f480 {
    Fighter_10f480 *FUN_00059a30();
};

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    Holder_10f480 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v2();
};

class AIHistoryNameCondition {
  public:
    char pad0[0xc];
    unsigned mode;
    int name;
    float threshold;

    char FUN_0010f480(int a1, fight::Params *params, int a3);
};

char AIHistoryNameCondition::FUN_0010f480(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;

    Fighter_10f480 *fighter = params->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return 0;

    if (((*(unsigned*)&DAT_004e0c10) & 1) == 0) {
        (*(unsigned*)&DAT_004e0c10) |= 1;
        (*(Key_10f480*)&DAT_004e0c08).FUN_0027af00();
        atexit(FUN_00363ee0);
    }
    if (((*(unsigned*)&DAT_004e0c10) & 2) == 0) {
        (*(unsigned*)&DAT_004e0c10) |= 2;
        (*(Key_10f480*)&DAT_004e0c00).FUN_0027af00();
        atexit(FUN_00363ed0);
    }

    (*(Key_10f480*)&DAT_004e0c00).FUN_0027af70(&fighter->history);
    (*(Key_10f480*)&DAT_004e0c08).FUN_0027b040(name);

    int limit = (int)threshold;
    int count = fighter->count;
    Key_10f480 *hist = &fighter->history;

    if (limit < 0) {
        if (mode == 3)
            return !hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
        return hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
    }
    if (limit == 0) {
        if (mode == 3)
            return hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
        return !hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08));
    }
    if (!hist->FUN_0027af90(((Key_10f480*)&DAT_004e0c08)))
        return 0;
    switch (mode) {
    case 0:
        return count < limit;
    case 1:
        return count <= limit;
    case 2:
        return count == limit;
    case 3:
        return count != limit;
    case 4:
        return count >= limit;
    case 5:
        return count > limit;
    }
    return 0;
}
