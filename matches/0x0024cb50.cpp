typedef unsigned int U32;
struct Triple { U32 a; U32 b; U32 c; };
void copyTriple(Triple* dst, const Triple* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
