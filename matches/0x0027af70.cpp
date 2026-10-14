// Same code shape as 0x0027af30 (propagated; names are from that function)
struct Pair_27af70 {
    unsigned a;
    unsigned b;
    Pair_27af70& Assign(const Pair_27af70* src);
};
Pair_27af70& Pair_27af70::Assign(const Pair_27af70* src) {
    a = src->a;
    b = src->b;
    return *this;
}
