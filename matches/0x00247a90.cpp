struct Obj {
    int pad[3];
    int f0c;
    int pad2[2];
    int f18;
    int f1c;
    int f20;
    float f24;
    int f28;
};

void FUN_00247a90(int p1, Obj* dst, int* src) {
    dst->f0c = 4;
    if (src != 0) {
        dst->f18 = src[0];
        dst->f1c = src[1];
    } else {
        dst->f18 = 0;
        dst->f1c = 0;
    }
    dst->f28 = 0;
    dst->f20 = 0;
    if (dst->f1c == 0) {
        dst->f24 = 1.0f;
        return;
    }
    dst->f24 = 0.0f;
}
