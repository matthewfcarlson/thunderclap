// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 10/10)
// FUN_002519e0 @ 0x002519e0
struct Stream {
    char pad00[0x24];
    int depth;
};

struct Writer {
    Stream *stream;
};

char __cdecl FUN_00246f50(Stream *s, const char *text);
char __cdecl FUN_0025aaf0(Writer *w, int value);

bool FUN_002519e0(Writer *w, const unsigned char *bytes)
{
    if (!FUN_00246f50(w->stream, "\n[\n"))
        return false;
    w->stream->depth++;
    for (unsigned int i = 0; i < 0x10; i++) {
        if (!FUN_0025aaf0(w, bytes[i]))
            return false;
        if (!FUN_00246f50(w->stream, "\n"))
            return false;
    }
    w->stream->depth--;
    return FUN_00246f50(w->stream, "\n]\n") != 0;
}
