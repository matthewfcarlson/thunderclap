// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c4020 @ 0x002c4020
namespace pure3d {
class FUN_002a0a70 {
public:
    char data[0x50];
    FUN_002a0a70();
    virtual void method();
};
class SpotLight : public FUN_002a0a70 {
public:
    int type;
    float x, y, z, w;
    float a, b, c;
    float angle, halfAngle, intensity;
    SpotLight();
    virtual void method();
};
SpotLight::SpotLight() {
    x = 0.0f;
    y = 0.0f;
    z = 1.0f;
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    w = 1.0f;
    angle = 1.57079637f;
    halfAngle = 0.785398185f;
    intensity = 1.0f;
    type = 3;
}
}