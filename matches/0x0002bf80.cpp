struct Triple {
    unsigned a, b, c;
};
struct Actor {
    void FUN_0002b970(unsigned, Triple, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    void FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g,
                      unsigned h, unsigned i);
};
void Actor::FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g,
                         unsigned h, unsigned i) {
    FUN_0002b970(a, *(Triple*)&b, e, f, g, h, i, 1);
}