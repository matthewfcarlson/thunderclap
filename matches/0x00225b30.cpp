struct AnimationDriver_225b30 {
    char pad[0x224];
    unsigned char a;
    unsigned char b;
    float fallback();
    float target();
};
float AnimationDriver_225b30::target() {
    if (a)
        return -1.0f;
    if (b)
        return -1.0f;
    return fallback();
}
