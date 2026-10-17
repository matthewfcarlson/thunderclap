// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00255ff0 @ 0x00255ff0
struct ClipData {
    char pad[8];
    unsigned char flags;
    char gap[3];
    unsigned int value;
    unsigned int next;
    void FUN_00253a90(const char *name);
};
struct FUN_0025fd00 {
    virtual void slot0();
    char pad[4];
    unsigned char enabled;
    char gap[7];
    ClipData data;
    FUN_0025fd00();
};
namespace audio {
struct SeqEventClip : FUN_0025fd00 {
    virtual void slot0();
    SeqEventClip();
};
}
audio::SeqEventClip::SeqEventClip() {
    enabled = 0;
    data.FUN_00253a90("MyRsdFile");
    data.value &= 0x80000000u;
    data.flags &= 0xfe;
    data.next = 0;
}