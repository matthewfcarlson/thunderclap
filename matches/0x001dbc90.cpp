// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X_1dbc90 {
    void Call();
    X_1dbc90* Target();
};
X_1dbc90* X_1dbc90::Target() {
    Call();
    return this;
}