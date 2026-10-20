// STATUS: equivalent (tools/equiv.py level 3: 3049 inputs, branch coverage 18/18)
// pure3d::SpriteParticleEmitter::vfunc_18 @ 0x002d4530
class Source_2d4530 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual float Get(int which);
};

namespace pure3d {
class SpriteParticleEmitter {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual float vfunc_18(int which);
    char pad04[0x88 - 0x4 - 0x0];
    Source_2d4530 *source;
    char pad8c[0x158 - 0x8c];
    float f158;
    char pad15c[0x168 - 0x15c];
    float f168;
    char pad16c[0x174 - 0x16c];
    float f174;
    char pad178[0x180 - 0x178];
    float f180;
    char pad184[0x194 - 0x184];
    float f194;
    char pad198[0x1a0 - 0x198];
    float f1a0;
    char pad1a4[0x1a8 - 0x1a4];
    float f1a8;
    char pad1ac[0x1b0 - 0x1ac];
    float f1b0;
};
}

float pure3d::SpriteParticleEmitter::vfunc_18(int which)
{
    switch (which) {
    case 0:
        return f158;
    case 7:
        return f168;
    case 8:
        return f174;
    case 9:
        return f180;
    case 10:
        return f194;
    case 11:
        return f1a0;
    case 12:
        return f1a8;
    case 13:
        return f1b0;
    }
    if (source != 0)
        return source->Get(which);
    return 0.0f;
}
