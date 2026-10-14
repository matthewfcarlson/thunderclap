// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_35000 {
    void Call();
    X_35000* Target();
};
X_35000* X_35000::Target() {
    Call();
    return this;
}