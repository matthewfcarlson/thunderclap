// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0021a550 @ 0x0021a550
struct Stream;
typedef unsigned char * (__cdecl *Refill)(int, int, Stream **);
struct Stream {
    unsigned int remaining;
    unsigned char *cursor;
    Refill refill;
    int context;
    int request;
};
int __cdecl FUN_0021a550(Stream *stream)
{
    Stream *available = stream;
    unsigned char *data = stream->refill(stream->request, stream->context, &available);
    if (data && available) {
        stream->cursor = data;
        stream->remaining = (unsigned int)available - 1;
        unsigned int result = *data;
        stream->cursor = data + 1;
        return result;
    }
    return -1;
}