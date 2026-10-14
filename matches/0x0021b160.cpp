struct Stream {
    unsigned count;
    unsigned char* pos;
};
struct State {
    unsigned code, a, b;
    char gap[8];
    unsigned mode;
    char gap2[4];
    unsigned zero;
    unsigned first;
    Stream* stream;
    char gap3[4];
    unsigned extra;
};
extern "C" unsigned readSlow(Stream*);
void init(unsigned x, State* s, Stream* p, unsigned y) {
    s->first = x;
    s->stream = p;
    s->a = 1;
    s->b = 1;
    s->mode = 0x11f;
    s->zero = 0;
    s->extra = y;
    unsigned n = p->count;
    p->count = n - 1;
    Stream* q = s->stream;
    if (n > 0) {
        unsigned char* t = q->pos;
        unsigned v = *t++;
        q->pos = t;
        s->code = v;
        return;
    }
    s->code = readSlow(q);
}