// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d3930 @ 0x002d3930
namespace pure3d {
struct FUN_0027b070 {
    FUN_0027b070();
    virtual void virtual0();
    char padding[0x0c];
};
struct ParticlePlaneGenerator : FUN_0027b070 {
    virtual void virtual0();
    unsigned char enabled;
    char pad11[3];
    int a14, a18, a1c, a20;
    char pad24[4];
    int a28, a2c, a30;
    char pad34[4];
    float a38, a3c;
    int a40, a44, a48;
    float a4c, a50, a54, a58, a5c;
    ParticlePlaneGenerator();
};
ParticlePlaneGenerator::ParticlePlaneGenerator() {
    enabled = 0;
    a14 = a18 = a1c = a20 = a28 = 0;
    a2c = a30 = a40 = a44 = a48 = 0;
    a38 = a3c = a4c = a50 = a54 = a58 = a5c = 1.0f;
}
}
