struct Helper {
    ~Helper() throw(); // FUN_0027af50
    int x;
};

struct Base {
    virtual ~Base() throw(); // FUN_00236d60
};

namespace hulkfight {
namespace scenario {

struct EffectTrack : Base {
    virtual ~EffectTrack();
    virtual void f();
    char p4[0x18 - 4];
    Helper h18;
    char p1c[0x20 - 0x1c];
    Helper h20;
    char p24[0x30 - 0x24];
    Helper h30;
    char p34[0x58 - 0x34];
    Helper h58;
};

EffectTrack::~EffectTrack() {}

} // namespace scenario
} // namespace hulkfight