extern "C" char DAT_004317dc[];
struct Part_2fb5d0 {
    void Init();
};
struct CollisionOBB {
    unsigned v;
    char pad[0x38];
    Part_2fb5d0 b;
    char pad2[0x3f];
    Part_2fb5d0 a;
    void Target();
    void Base();
};
void CollisionOBB::Target() {
    v = ((int)DAT_004317dc);
    a.Init();
    b.Init();
    Base();
}
