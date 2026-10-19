// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 16/16)
// FUN_0021f940 @ 0x0021f940
struct Stream { unsigned int remaining; unsigned char *cursor; };
struct Reader { int unused; Stream *stream; int unused2; int reversed; };
extern int __cdecl FUN_0021a550(Stream *);
extern int __cdecl FUN_0021a610(Stream *, void *, unsigned int);
// equiv-conv: FUN_0021f800 esi stack
extern void __cdecl FUN_0021f800(Reader *, const char *);
// equiv-conv: FUN_0021f940 eax ecx edx stack
void __cdecl FUN_0021f940(unsigned int count, unsigned char *destination, Reader *reader, unsigned int size)
{
    if (!reader->reversed) {
        if (FUN_0021a610(reader->stream, destination, count * size))
            FUN_0021f800(reader, "unexpected end of file");
        return;
    }
    if (!count) return;
    unsigned char *end = destination + size - 1;
    do {
        unsigned char *out = end;
        unsigned int left = size;
        while (left) {
            Stream *stream = reader->stream;
            unsigned int previous = stream->remaining;
            stream->remaining = previous - 1;
            stream = reader->stream;
            int value;
            if (previous) {
                value = *stream->cursor;
                ++stream->cursor;
            } else {
                value = FUN_0021a550(stream);
            }
            if (value == -1) FUN_0021f800(reader, "unexpected end of file");
            *out-- = (unsigned char)value;
            --left;
        }
        end += size;
    } while (--count);
}
