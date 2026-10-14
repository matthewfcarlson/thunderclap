struct Obj_5d860 {
    void* vptr;
    char pad[12];
    unsigned int m;
    unsigned char Fn(unsigned int x);
};

unsigned char Obj_5d860::Fn(unsigned int x) {
    m = x;
    return 1;
}
