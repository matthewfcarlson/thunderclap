struct A_1657a0 {
    char pad[0x10];
    float f;
    bool Set(float v);
};

bool A_1657a0::Set(float v) {
    f = v * 0.017453292f;
    return true;
}
