// STATUS: equivalent (tools/equiv.py level 3: 162 inputs, branch coverage 12/12)
// FUN_00215970 @ 0x00215970
struct Pair { unsigned int a; unsigned int b; };
struct State {
    char pad00[8];
    Pair* limit;      // 0x08
    Pair* cursor;     // 0x0c
    char pad10[4];
    Pair* frames;     // 0x14
    char pad18[0x30 - 0x18];
    unsigned char flags;  // 0x30
};
// equiv-conv: FUN_00215910 eax esi
Pair* FUN_00215910(Pair* src, State* s);

void FUN_00215970(State* s, int count, Pair* src)
{
    if (s->flags & 2)
        src = FUN_00215910(src, s);
    Pair* frame = s->frames - 2;
    Pair* dst = s->cursor - 1;
    s->frames = frame;
    s->cursor = reinterpret_cast<Pair*>(frame->a);
    if (count != 0) {
        do {
            if (src >= s->limit)
                break;
            dst->a = src->a;
            dst->b = src->b;
            src++;
            dst++;
            count--;
        } while (count != 0);
        if (count > 0) {
            do {
                dst->a = 0;
                dst++;
                count--;
            } while (count != 0);
        }
    }
    s->limit = dst;
}
