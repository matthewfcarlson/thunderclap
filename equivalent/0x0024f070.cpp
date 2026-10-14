// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 10/10)
// FUN_0024f070 @ 0x0024f070
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_24f070 {
    Stream *out;
};

char FUN_00246f50(Stream *s, const char *fmt, ...);
char FUN_0024ebe0(Writer_24f070 *w, float *value);

// Writes a 16-float matrix as "[ v v ... ]" lines to a text stream.
bool FUN_0024f070(Writer_24f070 *w, float *values)
{
    if (!FUN_00246f50(w->out, "\n[\n"))
        return false;
    w->out->indent++;
    for (unsigned int i = 0; i < 16; i++) {
        if (!FUN_0024ebe0(w, &values[i]))
            return false;
        if (!FUN_00246f50(w->out, "\n"))
            return false;
    }
    w->out->indent--;
    return FUN_00246f50(w->out, "\n]\n") != 0;
}
