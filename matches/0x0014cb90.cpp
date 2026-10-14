struct T_14cb90 {
    char pad[0x24];
    int mVal;
    bool Set(int v);
};

bool T_14cb90::Set(int v) {
    mVal = v;
    return true;
}
