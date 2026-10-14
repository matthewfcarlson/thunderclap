typedef unsigned int U32_24cb50;
struct Triple_24cb50 {
    U32_24cb50 a;
    U32_24cb50 b;
    U32_24cb50 c;
};
void copyTriple(Triple_24cb50* dst, const Triple_24cb50* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
