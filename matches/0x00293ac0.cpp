struct Triple_293ac0 {
    int a, b, c;
};
struct Object {
    char pad[0xcc];
    unsigned char flag;
    char pad2[0xe8 - 0xcd];
    int x, y, z;
    void Set(Triple_293ac0* p);
};
void Object::Set(Triple_293ac0* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    flag = 0;
}