// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::InLoadedRoomCondition::vfunc_6 @ 0x00166d90
struct V3 {
    float x, y, z;
};

struct Handle {
    char FUN_00059a50(V3 *out);
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle *FUN_000592a0();
};

struct Room {
    char FUN_00204350(float x, float y, float z);
};

struct World {
    Room *FUN_000862a0();
};

struct Game {
    char pad00[0x54];
    World *world;           // 0x54
};
extern Game *DAT_004dd700;

namespace hulkfight {
namespace motion {
class InLoadedRoomCondition {
public:
    char pad00[0xc];
    char expected;          // 0xc

    bool vfunc_6(int arg0, fight::Params *params, int arg2);
};

bool InLoadedRoomCondition::vfunc_6(int arg0, fight::Params *params, int arg2)
{
    if (!dynamic_cast<CFightParams *>(params))
        return false;
    Handle *handle = ((CFightParams *)params)->FUN_000592a0();
    V3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    handle->FUN_00059a50(&pos);
    return DAT_004dd700->world->FUN_000862a0()->FUN_00204350(pos.x, pos.y, pos.z) == expected;
}
}
}
