// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001b4cd0 @ 0x001b4cd0
struct Triple { int x, y, z; };
struct Actor {
    void FUN_001b4620(Triple value, int fourth, int fifth, int sixth);
    void FUN_001b4cd0(int x, int y, int z, int fourth);
};
void Actor::FUN_001b4cd0(int x, int y, int z, int fourth) {
    Triple value = { x, y, z };
    FUN_001b4620(value, fourth, 0, 0);
}