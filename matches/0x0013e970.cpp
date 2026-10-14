struct R {
    char pad[0x34];
    float v;
    bool Fn(float x);
};
bool R::Fn(float x) {
    v = x * 0.017453292f;
    return 1;
}
