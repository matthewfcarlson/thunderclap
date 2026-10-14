struct X_133690 {
    char pad[12];
    void* m1c;
    bool Set(void* p);
};
bool X_133690::Set(void* p) {
    m1c = p;
    return true;
}
