// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// hulkfight::motion::AccuracyLatencyAction::vfunc_4 @ 0x00194cb0
struct Player_194cb0 {
    char pad0[0x1d54];
    int aimX;               // 0x1d54
    int aimY;               // 0x1d58
    int aimZ;               // 0x1d5c
    int aimW;               // 0x1d60
    int aimV;               // 0x1d64
};
struct PlayerRef_194cb0 {
    Player_194cb0 *FUN_00059a30();
};
struct Owner_194cb0 {
    PlayerRef_194cb0 *FUN_000592a0();
};

extern int DAT_004e15b0;
extern int DAT_004e15b4;
extern int DAT_004e15b8;
extern unsigned int DAT_004e15bc;

class AccuracyLatencyAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad04[0x1c];
    Owner_194cb0 *owner;           // 0x20
};

void AccuracyLatencyAction::vfunc_4()
{
    PlayerRef_194cb0 *ref = owner->FUN_000592a0();
    Player_194cb0 *player = ref->FUN_00059a30();

    // function-local static zero vector
    if (!(DAT_004e15bc & 1)) {
        DAT_004e15bc |= 1;
        DAT_004e15b0 = 0;
        DAT_004e15b4 = 0;
        DAT_004e15b8 = 0;
    }

    if (ref != 0 && player != 0) {
        player->aimX = DAT_004e15b0;
        player->aimY = DAT_004e15b4;
        player->aimZ = DAT_004e15b8;
        player->aimW = 0;
        player->aimV = 0;
    }
}
