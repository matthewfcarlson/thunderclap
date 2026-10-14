// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_34fe0 {
    void Call();
    X_34fe0* Target();
};
X_34fe0* X_34fe0::Target() {
    Call();
    return this;
}