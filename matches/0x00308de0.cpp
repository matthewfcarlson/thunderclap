// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_308de0 {
    void Call();
    X_308de0* Target();
};
X_308de0* X_308de0::Target() {
    Call();
    return this;
}