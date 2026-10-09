struct Obj {
    void Get(int d, float* out);
};

float __cdecl FUN_0028b150(Obj* a, Obj* b, float t, int d) {
    float x, y;
    a->Get(d, &x);
    b->Get(d, &y);
    return (y - x) * t + x;
}
