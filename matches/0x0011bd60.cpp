extern "C" const float g_deg2rad = 0.017453292f;
struct Obj_11bd60 {
    char pad[0x18];
    float value;
    bool Set(float v);
};
bool Obj_11bd60::Set(float v) {
    value = v * g_deg2rad;
    return true;
}
