// STATUS: equivalent (tools/equiv.py level 3: 14807 inputs, branch coverage 6/6)
// FUN_002202a0 @ 0x002202a0
// FUN_002202a0 @ 0x002202a0
struct InputBuffer { int remaining; unsigned char *cursor; };
struct Reader { int unused; InputBuffer *buffer; };
extern int __cdecl FUN_0021a550(InputBuffer *buffer);
// equiv-conv: FUN_0021f800 esi stack
extern void __cdecl FUN_0021f800(Reader *reader, const char *format, ...);
// equiv-conv: FUN_002202a0 eax edi stack
extern "C" void __cdecl FUN_002202a0(void *reader, unsigned int expected, const char *name)
{
    InputBuffer *buffer = ((Reader *)reader)->buffer;
    unsigned int count = buffer->remaining;
    buffer->remaining = count - 1;
    int value;
    if (count == 0) {
        value = FUN_0021a550(((Reader *)reader)->buffer);
    } else {
        unsigned char *cursor = ((Reader *)reader)->buffer->cursor;
        value = *cursor;
        ((Reader *)reader)->buffer->cursor = cursor + 1;
    }
    if (value == -1)
        FUN_0021f800(((Reader *)reader), "unexpected end of file");
    unsigned int byteValue = (unsigned char)value;
    if (byteValue != expected)
        FUN_0021f800(((Reader *)reader), "bad size of %s (read %d; expected %d)", name, byteValue, expected);
}
