struct Inner_2333f0 {
    void Helper(void*, void*, void*);
};
struct C_2333f0 {
    char pad[0x18];
    Inner_2333f0 inner;
    void Target(void*, void*);
};
void C_2333f0::Target(void* a, void* b) {
    inner.Helper(this, a, b);
}