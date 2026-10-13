struct O {
    char pad[0xc];
    int m1c;
    bool Fn(int x);
};

bool O::Fn(int x) {
    m1c = x;
    return true;
}
