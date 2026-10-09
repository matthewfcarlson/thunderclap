extern const float threshold;
class SimpleFrameController { public: char pad[0x28]; float value; int vfunc_22(); };
int SimpleFrameController::vfunc_22() { return value <= threshold; }
