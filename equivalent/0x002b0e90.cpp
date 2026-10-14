// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002b0e90 @ 0x002b0e90
void *FUN_0008d6d0(unsigned int size);

struct Elem {
    int a;
    int b;
};
struct Vec {
    Elem *begin;
    Elem *end;
    Vec *FUN_002b0e90(const Vec *src);
};

Vec *Vec::FUN_002b0e90(const Vec *src)
{
    int n = src->end - src->begin;
    if (n != 0) {
        Elem *dst = (Elem *)FUN_0008d6d0(n * sizeof(Elem));
        begin = dst;
        if (dst != 0) {
            end = dst + n;
            const Elem *s = src->begin;
            for (int k = src->end - s; k != 0; k--) {
                if (dst != 0) {
                    dst->a = s->a;
                    dst->b = s->b;
                }
                s++;
                dst++;
            }
            return this;
        }
    }
    begin = 0;
    end = 0;
    return this;
}
