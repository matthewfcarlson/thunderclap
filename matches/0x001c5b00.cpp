struct Inner {
    void Helper();
};
struct Outer {
    char pad[0x128];
    Inner inner;
    void Target();
};
void Outer::Target() {
    inner.Helper();
}