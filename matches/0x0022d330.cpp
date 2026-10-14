struct V3_22d330 {
    float x, y, z;
    unsigned IsSmall();
};
inline float Abs(float v) {
    float t = v;
    *(unsigned*)&t = *(unsigned*)&t & 0x7fffffff;
    return t;
}
unsigned V3_22d330::IsSmall() {
    if (Abs(x) < 1e-05f)
        if (Abs(y) < 1e-05f)
            if (Abs(z) < 1e-05f)
                return 1;
    return 0;
}
