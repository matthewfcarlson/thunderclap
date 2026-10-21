extern const float gZero_354c0;
struct Inner_354c0 {
    char pad[0x10];
    void* Get();
    float Calc();
};
struct Owner_354c0 {
    char pad[0x10];
    Inner_354c0* m;
    float f();
};
float Owner_354c0::f() {
    Inner_354c0* p = m;
    void* q = p->Get();
    if (!q)
        return gZero_354c0;
    return ((Inner_354c0*)((char*)q + 0x20))->Calc();
}