// STATUS: equivalent (tools/equiv.py level 3: 1217 inputs, branch coverage 6/6)
// FUN_0025cf70 @ 0x0025cf70
// FUN_0025cf70 @ 0x0025cf70: fills each plane of a surface region with a constant byte and records the size
extern "C" void *__cdecl memset(void *, int, unsigned int);

struct Surface_25cf70 {
    char pad00[0x10];
    char *base;
    unsigned int flags;
    int state;
};

char __cdecl FUN_0025cf70(Surface_25cf70 *s, unsigned int offset, unsigned int size, unsigned int *outSize)
{
    unsigned char fill = ((s->flags & 0x7c000000) == 0x20000000) ? 0x80 : 0;
    if (s->flags & 0x1f0) {
        unsigned int plane = 0;
        do {
            unsigned int planes = (s->flags >> 4) & 0x1f;
            memset(s->base + offset / planes, fill, size / planes);
            plane++;
        } while (plane < ((s->flags >> 4) & 0x1f));
    }
    *outSize = size;
    s->state = 3;
    return 1;
}
