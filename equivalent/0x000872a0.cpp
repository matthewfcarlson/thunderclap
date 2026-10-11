// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000872a0 @ 0x000872a0
struct Vec3 {
    float x, y, z;
};

struct Pos {
    void FUN_00059a50(Vec3 *out);
};

struct Body {
    char pad0[0x10];
    Pos *pos;
    void FUN_000ae990();
    void FUN_000afe80();
    float FUN_000354c0();
};

struct Link {
    char pad0[8];
    char flag;
};


struct Entity {
    char pad0[0x124];
    Body *body;
};

struct Holder {
    char pad0[4];
    Link *link;
    char pad1[0x20 - 8];
    Entity *entity;
};

struct Display {
    char pad0[0x10];
    Body *a;
    char pad1[4];
    Body *b;
};

struct Globals {
    char pad1[0x54];
    Display *display;
};

struct Camera {
    void FUN_00089900(float angle);
    void FUN_000898a0(Vec3 v);
    char FUN_00089a40();
};

struct Sub0 {
    void FUN_001b7590();
};

struct Sub1 {
    void FUN_000bd1b0(int arg);
};

struct Status {
    int state;
};

class Tracker {
public:
    void FUN_000872a0();
    void FUN_00086980(int flag);

    char pad0[4];
    Status *status;
    char pad1[4];
    Holder *holder;
    char pad2[0x20 - 0x10];
    Sub1 *sub1;
    char pad3[0x34 - 0x24];
    Sub0 *sub0;
    Camera *camera;
};

extern Globals *DAT_004dd700;

void Tracker::FUN_000872a0()
{
    sub0->FUN_001b7590();
    holder->link->flag = 1;
    Vec3 pos;
    holder->entity->body->pos->FUN_00059a50(&pos);
    camera->FUN_000898a0(pos);
    camera->FUN_00089900(holder->entity->body->FUN_000354c0() * 57.295776f);
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
