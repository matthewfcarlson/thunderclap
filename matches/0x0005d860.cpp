struct Obj {
    void* vptr;
    char pad[12];
    unsigned int m;
    unsigned char Fn(unsigned int x);
};

unsigned char Obj::Fn(unsigned int x) {
    m = x;
    return 1;
}
