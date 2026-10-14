// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b3440 @ 0x001b3440
extern float DAT_004e18c0[];
extern float DAT_004e18d0[];
extern float DAT_004e18bc[];

class Timeline_1b3440 {
public:
    char pad0[0xc];
    int track;
    char pad10[8];
    float rate;
    float pos;
    char pad20[4];
    float time;
    int FUN_001b3250(float t);
    bool FUN_001b3440(float dt);
};

bool Timeline_1b3440::FUN_001b3440(float dt)
{
    int t = track;
    if (t < 0)
        return false;
    int seg = FUN_001b3250(pos);
    if (DAT_004e18c0[t * 45 + seg] == 0.0f && DAT_004e18d0[t * 45 + seg] == 0.0f)
        return false;
    time = dt + time;
    pos = time * rate;
    if (pos >= DAT_004e18bc[t * 45])
        return false;
    return true;
}
