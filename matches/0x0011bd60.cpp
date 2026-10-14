extern "C" const float g_deg2rad = 0.0174533f;
struct Obj {
    char pad[0x18];
    float value;
    bool Set(float v);
};
bool Obj::Set(float v) {
    value = v * g_deg2rad;
    return true;
}
