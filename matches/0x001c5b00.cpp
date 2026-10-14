struct Inner_1c5b00 {
    void Helper();
};
struct Outer_1c5b00 {
    char pad[0x128];
    Inner_1c5b00 inner;
    void Target();
};
void Outer_1c5b00::Target() {
    inner.Helper();
}