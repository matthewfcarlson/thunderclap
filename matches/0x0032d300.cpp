struct X_32d300 {
    char pad[0x9c];
    int mValue;
    void Set(int v);
};
void X_32d300::Set(int v) {
    mValue = v;
}
