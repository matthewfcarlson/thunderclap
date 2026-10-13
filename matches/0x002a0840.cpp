struct Obj {
    char pad[0x2c];
    int m2c;
    void Set(int v);
};

void Obj::Set(int v) {
    m2c = v;
}
