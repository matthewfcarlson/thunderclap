struct X {
    void A();
};
extern X gX;
void Helper() {
    gX.A();
}
