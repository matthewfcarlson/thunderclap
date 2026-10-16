namespace pure3d {
class BlendFrameController {
  public:
    virtual bool vfunc_22();
    char pad[0x24];
    int mode;
    char pad2[0x18];
    float value;
};
bool BlendFrameController::vfunc_22() {
    if (mode == 1)
        return value <= 0.000001f;
    return false;
}
} // namespace pure3d