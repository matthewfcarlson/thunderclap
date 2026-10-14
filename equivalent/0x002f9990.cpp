// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f9990 @ 0x002f9990
struct Elem { int a, b, c, d; };
void *__cdecl FUN_0008d6d0(unsigned int n);
Elem *__cdecl FUN_002f95f0(Elem *first, int count, Elem *dest);

struct Vec {
    Elem *begin;
    Elem *last;
    Elem *end;
    Vec *FUN_002f9990(Vec *src);
};

Vec *Vec::FUN_002f9990(Vec *src)
{
    int cap = src->end - src->begin;
    if (cap == 0) {
        begin = 0;
    } else {
        unsigned int bytes = cap * 16;
        Elem *p = (Elem *)FUN_0008d6d0(bytes);
        begin = p;
        if (p != 0) {
            last = p;
            end = (Elem *)((char *)p + bytes);
            last = FUN_002f95f0(src->begin, src->last - src->begin, p);
            return this;
        }
    }
    last = 0;
    end = 0;
    return this;
}
