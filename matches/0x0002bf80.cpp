struct Triple {
    unsigned a, b, c;
};
struct Actor {
    int FUN_0002b970(unsigned, Triple, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    int FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g,
                      unsigned h, unsigned i);
};
int Actor::FUN_0002bf80(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g,
                         unsigned h, unsigned i) {
    return FUN_0002b970(a, *(Triple*)&b, e, f, g, h, i, 1);
}