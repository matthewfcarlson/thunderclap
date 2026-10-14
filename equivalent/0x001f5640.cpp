// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f5640 @ 0x001f5640
class Inner {
public:
    char pad0[8];
    int f8;
    void FUN_001f34f0();
    void FUN_001f32b0(int a, int b, int c);
    void FUN_001f3370(int v);
};

class Player {
public:
    char pad0[0xc0];
    Inner *fc0;
    char padc4[0x334 - 0xc4];
    float f334;
    void FUN_001f3950(float v);
    char FUN_001f5640(int obj, int arg);
};

char Player::FUN_001f5640(int obj, int arg)
{
    if (fc0 == 0 || obj == 0)
        return 0;
    if (fc0->f8 != obj) {
        fc0->FUN_001f34f0();
        fc0->FUN_001f32b0(obj, 0, 0);
    }
    FUN_001f3950(100.0f * f334);
    fc0->FUN_001f3370(arg);
    return 1;
}
