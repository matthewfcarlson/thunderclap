struct Obj_16f6f0 {
    char pad[0x2c];
    float m;
    char Fn(float f);
};

char Obj_16f6f0::Fn(float f) {
    m = f * (3.14159265358979f / 180.0f);
    return 1;
}
