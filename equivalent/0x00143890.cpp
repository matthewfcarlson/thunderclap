// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00143890 @ 0x00143890
struct FUN_00236d40 {
    FUN_00236d40();
    virtual void dummy();
    char reserved[4];
    int enabled;
};
struct FUN_0027af00 { FUN_0027af00(); char data[8]; };
namespace hulkfight { namespace motion {
struct WorldDamageTrack : FUN_00236d40 {
    virtual void dummy();
    int zeroC;
    FUN_0027af00 object;
    int zero18, zero1C, zero20, zero24, zero28;
    float negativeOne, one30;
    int zero34;
    float one38, one3C;
    WorldDamageTrack();
};
WorldDamageTrack::WorldDamageTrack() : zeroC(0) {
    zero18=zero1C=zero20=zero24=zero28=0;
    negativeOne=-1.0f;
    one30=1.0f;
    zero34=0;
    one38=one3C=1.0f;
    enabled=1;
}
}}