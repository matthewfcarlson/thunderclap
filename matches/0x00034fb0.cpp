// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_34fb0 {
    void Call();
    X_34fb0* Target();
};
X_34fb0* X_34fb0::Target() {
    Call();
    return this;
}