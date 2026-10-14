struct Target_1922e0 {
    char pad[0x58];
    float value;
    bool Set(float degrees);
};
bool Target_1922e0::Set(float degrees) {
    value = degrees * *(const float*)(0x3f32b8);
    return true;
}
