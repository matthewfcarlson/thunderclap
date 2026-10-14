// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_23a5f0 {
    void Call();
    X_23a5f0* Target();
};
X_23a5f0* X_23a5f0::Target() {
    Call();
    return this;
}