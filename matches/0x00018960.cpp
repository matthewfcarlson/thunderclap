int FUN_00018960(float a, float b, float c) {
    union U {
        float f;
        unsigned int u;
    } x;
    x.f = a - b;
    x.u &= 0x7fffffff;
    return x.f <= c;
}