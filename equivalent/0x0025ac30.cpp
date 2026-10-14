// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 8/10, incomplete)
// FUN_0025ac30 @ 0x0025ac30
struct Stream;

struct Writer {
    Stream *stream;
};

char __cdecl FUN_00246f50(Stream *s, const char *format, ...);

void FUN_0025ac30(Writer *w, unsigned __int64 value)
{
    char out[0x100];
    char digits[0x100];
    int n = 0;
    do {
        digits[n++] = (char)('0' + (int)(value % 10));
        value = value / 10;
    } while (value != 0);
    for (int i = 0; i < n; i++)
        out[i] = digits[n - 1 - i];
    out[n] = 0;
    FUN_00246f50(w->stream, "%s", out);
}
