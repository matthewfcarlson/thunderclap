// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f9990 @ 0x002f9990
struct Elem_2f9990 { int a, b, c, d; };
void *__cdecl FUN_0008d6d0(unsigned int n);
Elem_2f9990 *__cdecl FUN_002f95f0(Elem_2f9990 *first, int count, Elem_2f9990 *dest);

struct Vec_2f9990 {
    Elem_2f9990 *begin;
    Elem_2f9990 *last;
    Elem_2f9990 *end;
    Vec_2f9990 *FUN_002f9990(Vec_2f9990 *src);
};

Vec_2f9990 *Vec_2f9990::FUN_002f9990(Vec_2f9990 *src)
{
    int cap = src->end - src->begin;
    if (cap == 0) {
        begin = 0;
    } else {
        unsigned int bytes = cap * 16;
        Elem_2f9990 *p = (Elem_2f9990 *)FUN_0008d6d0(bytes);
        begin = p;
        if (p != 0) {
            last = p;
            end = (Elem_2f9990 *)((char *)p + bytes);
            last = FUN_002f95f0(src->begin, src->last - src->begin, p);
            return this;
        }
    }
    last = 0;
    end = 0;
    return this;
}
