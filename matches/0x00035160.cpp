struct Blk_35160 {
    unsigned int v[16];
};
struct X_35160 {
    void* get();
};
struct Y_35160 {
    char pad[0x10];
    Blk_35160* get();
};
struct Target_35160 {
    char pad[0x10];
    X_35160* x;
    bool f(Blk_35160* out);
};
bool Target_35160::f(Blk_35160* out) {
    void* p = x->get();
    if (p) {
        Blk_35160* src = ((Y_35160*)((char*)p + 0x10))->get();
        *out = *src;
        return true;
    }
    return false;
}
