// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::motion::CharacterPropStatusCondition::vfunc_6 @ 0x001671d0
// hulkfight::motion::CharacterPropStatusCondition::vfunc_6 @ 0x001671d0: compares a count against a threshold
struct Player_1671d0 {
    int FUN_00066530();
    int FUN_00065f60();
};
Player_1671d0 *__cdecl FUN_000678d0();

struct Slot_1671d0 {
    void *FUN_00059a30();
};
struct Source_1671d0 {
    Slot_1671d0 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
class CharacterPropStatusCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int a, Source_1671d0 *source, int c);
    char pad04[8];
    unsigned int op;
    float threshold;
};
}
}

bool hulkfight::motion::CharacterPropStatusCondition::vfunc_6(int a, Source_1671d0 *source, int c)
{
    source->FUN_000592a0()->FUN_00059a30();
    FUN_000678d0()->FUN_00066530();
    int count = FUN_000678d0()->FUN_00065f60();
    int limit = (int)threshold;
    switch (op) {
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
    default:
        return false;
    }
}
