struct Callback {
    void invoke(unsigned, unsigned, unsigned, unsigned, unsigned);
};
typedef void (Callback::*Method)(unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0002da20(Callback* object, const unsigned* volatile values, unsigned unused,
                          Method callback) {
    const unsigned* p = values;
    unsigned a = *p++;
    unsigned b = *p++;
    values = (const unsigned*)*p++;
    unsigned e = p[1];
    unsigned d = p[0];
    (object->*callback)(a, b, (unsigned)values, d, e);
}