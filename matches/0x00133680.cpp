struct O_133680 {
    char pad[0x48];
    int m;
    bool Set(int x);
};
bool O_133680::Set(int x) {
    m = x;
    return true;
}
