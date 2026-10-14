// Same code shape as 0x00293ac0 (propagated; names are from that function)
struct Triple_2c3410 {
    int a, b, c;
};
struct Object {
    char pad[0xcc];
    unsigned char flag;
    char pad2[0xe8 - 0xcd];
    int x, y, z;
    void Set(Triple_2c3410* p);
};
void Object::Set(Triple_2c3410* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    flag = 0;
}