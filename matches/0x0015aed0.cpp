struct C_15aed0 {
    char pad[0x30];
    float m;
    bool Convert(float deg);
};

bool C_15aed0::Convert(float deg) {
    m = deg * 0.0174532925f;
    return true;
}
