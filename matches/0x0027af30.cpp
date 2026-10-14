struct Pair_27af30 {
    unsigned a;
    unsigned b;
    Pair_27af30& Assign(const Pair_27af30* src);
};
Pair_27af30& Pair_27af30::Assign(const Pair_27af30* src) {
    a = src->a;
    b = src->b;
    return *this;
}
