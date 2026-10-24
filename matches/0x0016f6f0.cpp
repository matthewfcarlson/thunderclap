struct Obj_16f6f0 {
    char pad[0x2c];
    float m;
    char Fn(float f);
};

char Obj_16f6f0::Fn(float f) {
    m = f * 0.017453292f;
    return 1;
}
