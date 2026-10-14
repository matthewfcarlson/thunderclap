struct Vec_28a8f0 {
    float x, y, z, w;
    void FUN_0022b610(const Vec_28a8f0* a, const Vec_28a8f0* b);
};
void __cdecl FUN_0022b080(Vec_28a8f0* out, const Vec_28a8f0* a, const Vec_28a8f0* b);
struct Curve_28a8f0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void sample(float t, Vec_28a8f0* out);
    char pad[12];
    int count;
    short* times;
    void target(float a, float b, Vec_28a8f0* out);
};
void Curve_28a8f0::target(float a, float b, Vec_28a8f0* out) {
    Vec_28a8f0 first, second, start, end, tail;
    sample(a, &first);
    sample(b, &second);
    if (a <= b) {
        out->FUN_0022b610(&second, &first);
    } else {
        sample(0.0f, &start);
        sample((float)times[count - 1], &end);
        tail.FUN_0022b610(&second, &start);
        out->FUN_0022b610(&end, &first);
        FUN_0022b080(out, out, &tail);
    }
}