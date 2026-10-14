// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_78b90 {
    void Call();
    X_78b90* Target();
};
X_78b90* X_78b90::Target() {
    Call();
    return this;
}