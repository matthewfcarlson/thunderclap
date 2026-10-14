extern const float rad = 0.0174533f;
struct O {
    virtual void V();
    char pad[0x40];
    float v;
    bool Set(float x);
};
bool O::Set(float x) {
    v = x * rad;
    return true;
}
