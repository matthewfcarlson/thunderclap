// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_78b70 {
    void Call();
    X_78b70* Target();
};
X_78b70* X_78b70::Target() {
    Call();
    return this;
}