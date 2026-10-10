namespace D3D8 {
void __stdcall D3D_GetDeviceCaps(int, int, void*);
}
namespace pure3d {
class pddiObject {
  public:
    pddiObject() throw();
    virtual void p0();
    int field4;
    int field8;
};
struct DisplayMode {
    void FUN_00292330();
    char data[0x34];
};
class d3dDisplay : public pddiObject {
  public:
    d3dDisplay(int arg) throw();
    virtual void v1();
    int field_c;
    int field_10;
    char pad14[0x58 - 0x14];
    char caps[0x434 - 0x58];
    unsigned char b434, b435, b436, b437;
    int field438;
    DisplayMode mode;
    int field470, field474, field478, field47c, field480;
    float scaleX, scaleY, scaleZ;
    char pad490[8];
    int field498;
};
d3dDisplay::d3dDisplay(int arg) throw() {
    mode.FUN_00292330();
    field_c = arg;
    field_10 = 0;
    field438 = 0;
    field470 = 2;
    field474 = 1;
    field478 = 0;
    field47c = 0;
    field480 = 0;
    b434 = 0;
    b435 = 0;
    b436 = 1;
    scaleX = 1.0f;
    scaleY = 1.0f;
    scaleZ = 1.0f;
    D3D8::D3D_GetDeviceCaps(0, 1, caps);
    field498 = 0;
    b437 = 0;
}
} // namespace pure3d
