struct Helper_1a31d0 {
    ~Helper_1a31d0() throw(); // FUN_0027af50
    int x;
};

struct Base_1a31d0 {
    virtual ~Base_1a31d0() throw(); // FUN_00236d60
};

namespace hulkfight {
namespace scenario {

struct EffectTrack : Base_1a31d0 {
    virtual ~EffectTrack();
    virtual void f();
    char p4[0x18 - 4];
    Helper_1a31d0 h18;
    char p1c[0x20 - 0x1c];
    Helper_1a31d0 h20;
    char p24[0x30 - 0x24];
    Helper_1a31d0 h30;
    char p34[0x58 - 0x34];
    Helper_1a31d0 h58;
};

EffectTrack::~EffectTrack() {}

} // namespace scenario
} // namespace hulkfight