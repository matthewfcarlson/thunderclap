struct Triple {
    int x, y, z;
};
struct Actor {
    void FUN_001b4620(Triple value, int fourth, int fifth, int sixth);
    void FUN_001b4cd0(Triple value, int fourth);
};
void Actor::FUN_001b4cd0(Triple value, int fourth) {
    FUN_001b4620(value, fourth, 0, 0);
}