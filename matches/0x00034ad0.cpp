struct X_34ad0 {
    void Call();
    X_34ad0* Target();
};
X_34ad0* X_34ad0::Target() {
    Call();
    return this;
}