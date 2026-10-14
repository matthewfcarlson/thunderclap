extern const float gScale_2ecf20;
extern void* gVtable_2ecf20;
struct SimLength {
    void* vptr;
    float value;
    float raw;
    SimLength(float);
};
SimLength::SimLength(float x) {
    vptr = &gVtable_2ecf20;
    raw = x;
    value = gScale_2ecf20 * x;
}