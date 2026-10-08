namespace pure3d {
class BlendFrameController {
public:
    char pad0[0x28];
    unsigned int count;
    char pad2[0x18 - 4];
    float values[1];
    float vfunc_21();
};
extern const float zero;
float BlendFrameController::vfunc_21() {
    if (count > 0) return *(float*)((char*)this + count * 0x2c + 0x18);
    return zero;
}
}
