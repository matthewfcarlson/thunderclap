// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::InLoadedRoomCondition::vfunc_6 @ 0x00166d90
struct V3_166d90 {
    float x, y, z;
};

struct Handle_166d90 {
    char FUN_00059a50(V3_166d90 *out);
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_166d90 *FUN_000592a0();
};

struct Room {
    char FUN_00204350(float x, float y, float z);
};

struct World {
    Room *FUN_000862a0();
};

struct Game_166d90 {
    char pad00[0x54];
    World *world;           // 0x54
};
extern Game_166d90 *DAT_004dd700;

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
    Handle_166d90 *handle = ((CFightParams *)params)->FUN_000592a0();
    V3_166d90 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    handle->FUN_00059a50(&pos);
    return DAT_004dd700->world->FUN_000862a0()->FUN_00204350(pos.x, pos.y, pos.z) == expected;
}
}
}
