struct T {
    char pad[0x24];
    int mVal;
    bool Set(int v);
};

bool T::Set(int v) {
    mVal = v;
    return true;
}
