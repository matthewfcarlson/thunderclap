struct Slot {
    bool on;
    char pad[3];
    unsigned int n;
    char rest[0xbe0];
};
struct Pool {
    int h;
    Slot s[5];
};
struct Owner {
    char pad[0xac8];
    Pool* pool;
    unsigned int Count();
};
unsigned int Owner::Count() {
    unsigned int m = 0;
    Pool* p = pool;
    if (p->s[0].on && p->s[0].n > 0)
        m = p->s[0].n;
    for (int i = 1; i < 4; i++) {
        if (p->s[i].on && p->s[i].n > m)
            m = p->s[i].n;
    }
    if (p->s[4].on && p->s[4].n > m)
        return p->s[4].n + 1;
    return m + 1;
}
