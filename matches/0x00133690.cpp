struct X {
    char pad[12];
    void* m1c;
    bool Set(void* p);
};
bool X::Set(void* p) {
    m1c = p;
    return true;
}
