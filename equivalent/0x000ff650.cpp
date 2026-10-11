// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// CHand2HandAgent::vfunc_12 @ 0x000ff650
struct NameHolder {
    void FUN_0027b040(const char *name);
};

struct Clock {
    float FUN_00078780();
};
Clock *__cdecl FUN_000964d0();

struct Player {
    char pad0[0x1ccc];
    float limit;
    char pad1cd0[0x2098 - 0x1cd0];
    NameHolder evadeName;
    char pad2099[0x20a0 - 0x2099];
    unsigned char evading;
};

class CAgentBase {
public:
    virtual void v0();
    virtual void v1();
};

class CHand2HandAgent : public CAgentBase {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual char vfunc_12(Player *player);
    char pad04[0x84 - 4];
    float timer;
    char pad88[0x94 - 0x88];
    float dirX;
    float dirY;
    float dirZ;
    char pada0[0xbc - 0xa0];
    float velX;
    float velY;
    float velZ;
    float speed;
};

char CHand2HandAgent::vfunc_12(Player *player)
{
    char result = 0;
    if (timer < 1.0f)
        return 0;
    Clock *clock = FUN_000964d0();
    if (speed < 5.5f) {
        float limit = player->limit;
        if (clock->FUN_00078780() < limit) {
            result = 1;
            float dot = velZ * dirZ + velY * dirY + velX * dirX;
            float cross = dirZ * velX - velZ * dirX;
            if (dot > 0.7f) {
                if (clock->FUN_00078780() < 0.33f)
                    player->evadeName.FUN_0027b040("evade_s");
                else if (cross < 0.0f)
                    player->evadeName.FUN_0027b040("evade_e");
                else
                    player->evadeName.FUN_0027b040("evade_w");
                player->evading = result;
            } else if (dot > -0.7f) {
                if (cross < 0.0f)
                    player->evadeName.FUN_0027b040("evade_e");
                else
                    player->evadeName.FUN_0027b040("evade_w");
                player->evading = result;
            }
        }
        timer = 0.0f;
    }
    return result;
}
