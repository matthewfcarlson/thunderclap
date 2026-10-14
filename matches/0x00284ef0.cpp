extern const float threshold_284ef0;
class SimpleFrameController {
  public:
    char pad[0x28];
    float value;
    int vfunc_22();
};
int SimpleFrameController::vfunc_22() {
    return value <= threshold_284ef0;
}
