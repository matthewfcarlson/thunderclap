// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002bfcb0 @ 0x002bfcb0
namespace pure3d {
struct FUN_0027b070 {
    virtual void Destroy();
    char pad[12];
    FUN_0027b070();
};
struct Image8 : FUN_0027b070 {
    virtual void Destroy();
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    unsigned int pitch;
    unsigned int format;
    unsigned int flags;
    unsigned char bit28;
    unsigned char bit29;
    char pad2[6];
    unsigned int palette[256];
    unsigned int paletteSize;
    Image8();
};
Image8::Image8() {
    width = 0;
    height = 0;
    depth = 8;
    pitch = 0;
    format = 8;
    flags = 0;
    bit28 = 0;
    bit29 = 0;
    for (int i = 0; i < 256; ++i) palette[i] = 0;
    paletteSize = 256;
}
}