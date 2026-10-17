// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254b10 @ 0x00254b10
struct Value { unsigned int lo, hi; };
extern "C" Value __cdecl FUN_002672f0(const char*, int, int);
struct Descriptor {
    char bytes[20];
    Descriptor* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventLogicRepeatType {
    void* vtable;
    void FUN_002605e0(Descriptor*, Value*, int, int);
    SeqEventLogicRepeatType* FUN_00254b10();
};
}
extern "C" char DAT_0042a3a0[];
audio::SeqEventLogicRepeatType* audio::SeqEventLogicRepeatType::FUN_00254b10() {
    Value value = FUN_002672f0("SeqEventLogicRepeat", 0, 0);
    Descriptor desc;
    FUN_002605e0(desc.FUN_0023fc40("||:", 0), &value, 28, 4);
    desc.FUN_00240060();
    vtable = DAT_0042a3a0;
    return this;
}