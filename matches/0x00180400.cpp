struct X_180400 {
    virtual void V();
    char pad[12];
    int m10;
    bool Fn(int a);
};

bool X_180400::Fn(int a) {
    m10 = a;
    return true;
}
