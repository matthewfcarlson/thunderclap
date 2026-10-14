struct Obj {
    char pad[0x2c];
    float m;
    char Fn(float f);
};

char Obj::Fn(float f) {
    m = f * (3.14159265358979f / 180.0f);
    return 1;
}
