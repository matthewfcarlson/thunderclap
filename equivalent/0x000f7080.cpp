// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// FUN_000f7080 @ 0x000f7080
// Read one line of UTF-16 text (up to and including '\n') from a stream into a buffer of `count` characters.
// Returns the buffer, or null when nothing was read.
class Stream {
public:
    unsigned int FUN_00263fc0();                                    // read position
    unsigned int FUN_00263fb0();                                    // end position
    void FUN_002647e0(void* dst, int a, int b, int c);              // read one element
};

// The incoming buffer-pointer slot doubles as the one-character read buffer.
union BufferSlot {
    unsigned short* buffer;
    unsigned short ch;
};

unsigned short* __stdcall FUN_000f7080(BufferSlot slot, int count, Stream* stream)
{
    unsigned short* buffer = slot.buffer;
    int n = 0;
    if (count > 0) {
        do {
            unsigned int pos = stream->FUN_00263fc0();
            if (pos >= stream->FUN_00263fb0()) {
                break;
            }
            stream->FUN_002647e0(&slot.ch, 1, 2, 1);
            unsigned short c = slot.ch;
            buffer[n++] = c;
            if (c == 0xa) {
                break;
            }
        } while (n < count);
    }
    if (n < count) {
        buffer[n] = 0;
    } else {
        buffer[count - 1] = 0;
    }
    return n > 0 ? buffer : 0;
}
