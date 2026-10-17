// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254120 @ 0x00254120
namespace audio {
struct FUN_0025fd00 {
    FUN_0025fd00();
    virtual void virtual0();
    char padding[4];
};
struct RsdFile {
    void FUN_00253a90(const char *name);
    char pad[8];
    unsigned char flags;
    char gap[3];
    unsigned int state;
    unsigned int field;
};
struct SeqEventStream : FUN_0025fd00 {
    RsdFile file;
    SeqEventStream();
    virtual void virtual0();
};
SeqEventStream::SeqEventStream() {
    file.FUN_00253a90("MyRsdFile");
    file.state &= 0x80000000u;
    file.flags &= 0xfe;
    file.field = 0;
}
}