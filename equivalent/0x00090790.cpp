// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// FUN_00090790 @ 0x00090790
// FUN_00090790 @ 0x00090790: measures the player's distance or height from a start point and keeps the best value
#include "decls/address.h"
extern "C" double sqrt(double);

struct Vec3_90790 {
    float x, y, z;
};

struct Body_90790 {
    void FUN_00059a50(Vec3_90790 *out);
};
struct Player_90790 {
    char pad00[0x10];
    Body_90790 *body;
};
struct Actor_90790 {
    char pad00[0x124];
    Player_90790 *player;
};
struct World {
    char pad00[0x20];
    Actor_90790 *actor;
};

class Measure {
public:
    char pad00[0x10];
    int kind;
    int mode;
    char active;
    char pad19[3];
    float startX;
    float startY;
    float startZ;
    char pad28[0x38 - 0x28];
    int value;
    int best;
    void FUN_00090790();
};

void Measure::FUN_00090790()
{
    if (!active)
        return;
    int m = mode;
    active = 0;
    if (m == 1) {
        Vec3_90790 p;
        DAT_004dd700->actor->player->body->FUN_00059a50(&p);
        if (kind == 1)
            value = (int)(p.y - startY);
    } else if (m == 2) {
        Vec3_90790 p;
        DAT_004dd700->actor->player->body->FUN_00059a50(&p);
        if (kind == 1)
            value = (int)sqrt((p.x - startX) * (p.x - startX) + (p.z - startZ) * (p.z - startZ));
    }
    if (value > best)
        best = value;
}
