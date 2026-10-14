struct Obj_114f30 {
    char pad[0x10];
    void* m;
    bool Set(void* p);
};

bool Obj_114f30::Set(void* p) {
    m = p;
    return true;
}