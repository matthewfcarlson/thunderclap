// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0014e3e0 @ 0x0014e3e0
namespace hulkfight { namespace motion {
struct FUN_00236d40 { virtual void virtualMethod(); FUN_00236d40(); };
struct HitPushbackTrack : FUN_00236d40 {
    virtual void virtualMethod();
    char padding04[8];
    int value0c;
    float value10;
    float value14;
    float value18;
    unsigned char flag1c;
    char padding1d[3];
    int value20;
    int value24;
    int value28;
    int value2c;
    int value30;
    HitPushbackTrack();
};
HitPushbackTrack::HitPushbackTrack() {
    value0c = 0;
    flag1c = 0;
    value20 = 0;
    value24 = 0;
    value2c = 0;
    value30 = 0;
    value10 = -1.0f;
    value14 = 1.0f;
    value18 = -1.0f;
    value28 = -5;
}
} }