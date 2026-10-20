struct Callback {
    void invoke(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
void FUN_00090900(Callback* object, const unsigned* arguments, unsigned unused,
                  void (Callback::*callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned)) {
    unsigned a = *arguments++;
    unsigned b = *arguments++;
    unsigned c = *arguments++;
    unsigned d = *arguments++;
    unsigned e = *arguments++;
    unsigned f = *arguments++;
    (object->*callback)(a, b, c, d, e, f);
}