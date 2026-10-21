// STATUS: equivalent (tools/equiv.py level 3: 19806 inputs, branch coverage 2/2)
// FUN_000872a0 @ 0x000872a0
#include "decls/address.h"
struct Vec3_872a0 {
    float x, y, z;
};

struct Pos_872a0 {
    void FUN_00059a50(Vec3_872a0 *out);
};

struct Body_872a0 {
    char pad0[0x10];
    Pos_872a0 *pos;
    void FUN_000ae990();
    void FUN_000afe80();
    float FUN_000354c0();
};

struct Link_872a0 {
    char pad0[8];
    char flag;
};


struct Entity {
    char pad0[0x124];
    Body_872a0 *body;
};

struct Holder_872a0 {
    char pad0[4];
    Link_872a0 *link;
    char pad1[0x20 - 8];
    Entity *entity;
};

struct Display_872a0 {
    char pad0[0x10];
    Body_872a0 *a;
    char pad1[4];
    Body_872a0 *b;
};

struct World {
    char pad1[0x54];
    Display_872a0 *display;
};

struct Camera {
    void FUN_00089900(float angle);
    void FUN_000898a0(Vec3_872a0 v);
    char FUN_00089a40();
};

struct Sub0_872a0 {
    void FUN_001b7590();
};

struct Sub1_872a0 {
    void FUN_000bd1b0(int arg);
};

struct Status_872a0 {
    int state;
};

class Tracker_872a0 {
public:
    void FUN_000872a0();
    void FUN_00086980(int flag);

    char pad0[4];
    Status_872a0 *status;
    char pad1[4];
    Holder_872a0 *holder;
    char pad2[0x20 - 0x10];
    Sub1_872a0 *sub1;
    char pad3[0x34 - 0x24];
    Sub0_872a0 *sub0;
    Camera *camera;
};


void Tracker_872a0::FUN_000872a0()
{
    sub0->FUN_001b7590();
    holder->link->flag = 1;
    Vec3_872a0 pos;
    holder->entity->body->pos->FUN_00059a50(&pos);
    camera->FUN_000898a0(pos);
    float angle = holder->entity->body->FUN_000354c0() * 57.295776f;
    camera->FUN_00089900(angle);
    sub1->FUN_000bd1b0(0);
    FUN_00086980(camera->FUN_00089a40());
    if (camera->FUN_00089a40()) {
        status->state = 1;
        DAT_004dd700->display->a->FUN_000ae990();
        DAT_004dd700->display->b->FUN_000afe80();
    } else {
        status->state = 2;
        DAT_004dd700->display->b->FUN_000afe80();
    }
}
