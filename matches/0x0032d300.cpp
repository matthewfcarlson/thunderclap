struct X {
    char pad[0x9c];
    int mValue;
    void Set(int v);
};
void X::Set(int v) {
    mValue = v;
}
