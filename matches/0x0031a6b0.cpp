// FUN_0031a6b0 @ 0x0031a6b0
struct Rest_31a6b0 {
    char data[96];
    void FUN_0031a8b0(const Rest_31a6b0 *src);
};

struct Elem_31a6b0 {
    unsigned int first;
    Rest_31a6b0 rest;
};

struct Sub_31a6b0 {
    char data[0x60];
    void FUN_00319c80(const Sub_31a6b0 *src);
};

class Container_31a6b0 {
public:
    Elem_31a6b0 *begin;
    Elem_31a6b0 *end;
    Elem_31a6b0 *cap;
    char pad0c[4];
    Sub_31a6b0 sub;
    unsigned int f70, f74, f78, f7c, f80;
    unsigned char f84;
    char pad85[3];
    unsigned int f88, f8c, f90, f94, f98, f9c;
    int state;

    Container_31a6b0 *FUN_0031a6b0(const Container_31a6b0 *other);
};

Container_31a6b0 *Container_31a6b0::FUN_0031a6b0(const Container_31a6b0 *other)
{
    if (this == other)
        return this;

    end = begin;
    if (state == 1)
        state = 2;
    end = begin;

    for (unsigned int i = 0; i < (unsigned int)(((int)other->end - (int)other->begin) / 100); i++) {
        Elem_31a6b0 tmp;
        const Elem_31a6b0 *s = &other->begin[i];
        tmp.first = s->first;
        tmp.rest.FUN_0031a8b0(&s->rest);
        Elem_31a6b0 *p = end;
        if (p < cap) {
            end = p + 1;
            if (p) {
                p->first = tmp.first;
                p->rest.FUN_0031a8b0(&tmp.rest);
            }
        }
    }

    sub.FUN_00319c80(&other->sub);
    f70 = other->f70;
    f74 = other->f74;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f84 = other->f84;
    f88 = other->f88;
    f8c = other->f8c;
    f90 = other->f90;
    f94 = other->f94;
    f98 = other->f98;
    f9c = other->f9c;
    state = other->state;
    return this;
}
