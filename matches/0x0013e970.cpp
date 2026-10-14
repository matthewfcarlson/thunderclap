struct R_13e970 {
    char pad[0x34];
    float v;
    bool Fn(float x);
};
bool R_13e970::Fn(float x) {
    v = x * 0.017453292f;
    return 1;
}
