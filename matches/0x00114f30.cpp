struct Obj {
    char pad[0x10];
    void* m;
    bool Set(void* p);
};

bool Obj::Set(void* p) {
    m = p;
    return true;
}