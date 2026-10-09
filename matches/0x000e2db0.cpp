class HSlider {
    char pad0[0x150];
    int field150;
    char pad154[0x2c];
    int field180;

  public:
    void vfunc_1(int);
};
void HSlider::vfunc_1(int x) {
    if (x == field180)
        field150 = *(int*)(field180 + 0x40);
}