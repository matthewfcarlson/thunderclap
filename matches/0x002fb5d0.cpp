extern "C" char DAT_004317dc[];
struct Part {
    void Init();
};
struct CollisionOBB {
    unsigned v;
    char pad[0x38];
    Part b;
    char pad2[0x3f];
    Part a;
    void Target();
    void Base();
};
void CollisionOBB::Target() {
    v = ((int)DAT_004317dc);
    a.Init();
    b.Init();
    Base();
}
