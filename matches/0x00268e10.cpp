extern const float DAT_003f32e0;
extern const float DAT_003f32dc;
namespace core {
struct ControllerInputPointXBox {
    char pad[0x14];
    float value;
    void vfunc_5(float input);
};
void ControllerInputPointXBox::vfunc_5(float input) {
    if (input < DAT_003f32e0)
        value = 0.0f;
    else if (input > DAT_003f32dc)
        value = 1.0f;
    else
        value = input;
}
} // namespace core