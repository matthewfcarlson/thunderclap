// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_27cc40 {
    void Call();
    X_27cc40* Target();
};
X_27cc40* X_27cc40::Target() {
    Call();
    return this;
}