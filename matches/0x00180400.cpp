struct X {
    virtual void V();
    char pad[12];
    int m10;
    bool Fn(int a);
};

bool X::Fn(int a) {
    m10 = a;
    return true;
}
