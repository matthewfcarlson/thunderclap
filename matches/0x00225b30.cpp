struct C {
    char pad[0x224];
    unsigned char a;
    unsigned char b;
    float fallback();
    float target();
};
float C::target() {
    if (a)
        return -1.0f;
    if (b)
        return -1.0f;
    return fallback();
}
