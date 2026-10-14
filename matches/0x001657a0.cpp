struct A {
    char pad[0x10];
    float f;
    bool Set(float v);
};

bool A::Set(float v) {
    f = v * 0.017453292f;
    return true;
}
