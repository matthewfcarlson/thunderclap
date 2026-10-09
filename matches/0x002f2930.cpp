struct S {
    char pad[0x14];
    float x;
};
extern const float half;
float f(S* a, S* b) {
    return (a->x + b->x) * half;
}