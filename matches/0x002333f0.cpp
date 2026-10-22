struct Inner_2333f0 {
    int Helper(void*, void*, void*);
};
struct Branch_2333f0 {
    char pad[0x18];
    Inner_2333f0 inner;
    int Target(void*, void*);
};
int Branch_2333f0::Target(void* a, void* b) {
    return inner.Helper(this, a, b);
}