extern const float rad_13ec30 = 0.017453292f;
struct O_13ec30 {
    virtual void V();
    char pad[0x40];
    float v;
    bool Set(float x);
};
bool O_13ec30::Set(float x) {
    v = x * rad_13ec30;
    return true;
}
