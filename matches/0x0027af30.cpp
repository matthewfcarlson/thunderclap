struct Pair {
    unsigned a;
    unsigned b;
    Pair& Assign(const Pair* src);
};
Pair& Pair::Assign(const Pair* src) {
    a = src->a;
    b = src->b;
    return *this;
}
