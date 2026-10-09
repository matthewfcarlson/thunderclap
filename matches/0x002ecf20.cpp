extern const float gScale;
extern void* gVtable;
struct SimLength {
    void* vptr;
    float value;
    float raw;
    SimLength(float);
};
SimLength::SimLength(float x) {
    vptr = &gVtable;
    raw = x;
    value = gScale * x;
}