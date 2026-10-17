// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a0a70 @ 0x002a0a70
namespace pure3d {
struct Light;
struct Base {
    Base(Light* owner);
};
struct Light : Base {
    virtual void virtualFunction();
    void FUN_0027b070();
    char padding[12];
    unsigned char enabled;
    unsigned char visible;
    unsigned char flag2;
    unsigned char flag3;
    unsigned int color;
    unsigned int value18;
    unsigned int value1c;
    float intensity;
    unsigned int invalid24;
    unsigned int unknown28;
    unsigned int values[8];
    float scale;
    unsigned int value50;
    unsigned int invalid54;
    Light();
};
inline Base::Base(Light* owner) { owner->FUN_0027b070(); }
Light::Light() : Base(this) {
    enabled = 0;
    flag2 = 0;
    flag3 = 0;
    visible = 1;
    color = 0xffffffff;
    value18 = 0;
    value1c = 0;
    intensity = 1.0f;
    invalid24 = 0xffffffff;
    for (int i = 0; i < 8; ++i) values[i] = 0;
    scale = 1.0f;
    value50 = 0;
    invalid54 = 0xffffffff;
}
}