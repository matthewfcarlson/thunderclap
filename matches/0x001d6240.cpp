// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_1d6240 {
    void Call();
    X_1d6240* Target();
};
X_1d6240* X_1d6240::Target() {
    Call();
    return this;
}