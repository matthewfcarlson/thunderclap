namespace pure3d {
struct Sub {
    float calc(float, float);
    int convert(float);
};
class PoseAnimationController {
  public:
    virtual void vfunc_27();
    char pad[0x28];
    Sub sub;
    char pad2[0xe4];
    float value;
    char pad3[4];
    float other;
    void pre();
    void post(int);
};
void PoseAnimationController::vfunc_27() {
    if (!(value < 1e-5f)) {
        pre();
        post(sub.convert(sub.calc(value, other)));
    }
}
} // namespace pure3d