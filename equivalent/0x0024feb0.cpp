// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0024feb0 @ 0x0024feb0
extern unsigned char DAT_00429b50;
struct Part { void FUN_0023fc40(const void *, int); };
struct FUN_0025fd00 { virtual void dummy(); FUN_0025fd00(); char pad04[4]; };
namespace audio {
struct SeqEventCondition : FUN_0025fd00 {
    int field08;
    int field0c;
    int field10;
    Part part14;
    SeqEventCondition();
    virtual void dummy();
};
}
audio::SeqEventCondition::SeqEventCondition() {
    field08 = 0;
    field0c = 0;
    field10 = 0;
    part14.FUN_0023fc40(&DAT_00429b50, 2);
}