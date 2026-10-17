// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133d70 @ 0x00133d70
namespace hulkfight { namespace motion {
class FUN_00236d40 {
public:
    virtual void dummy();
    char padding[8];
    FUN_00236d40();
};
class FallTrack : public FUN_00236d40 {
public:
    unsigned int value0c;
    float value10;
    unsigned int value14, value18, value1c, value20;
    unsigned char value24;
    char pad25[3];
    unsigned int value28, value2c, value30;
    float value34;
    unsigned int value38;
    unsigned char value3c;
    char pad3d[3];
    int value40;
    unsigned int value44, value48;
    FallTrack();
};
FallTrack::FallTrack() {
    value0c = 0;
    value14 = 0;
    value18 = 0;
    value1c = 0;
    value20 = 0;
    value24 = 0;
    value10 = -1.0f;
    value28 = 0;
    value2c = 0;
    value30 = 0;
    value38 = 0;
    value44 = 0;
    value48 = 0;
    value34 = 9.8f;
    value3c = 1;
    value40 = -5;
}
} }