// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_e36a0 {
    void Call();
    X_e36a0* Target();
};
X_e36a0* X_e36a0::Target() {
    Call();
    return this;
}