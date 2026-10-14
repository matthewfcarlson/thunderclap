// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 8/8)
// FUN_00246e50 @ 0x00246e50
struct Inner;
typedef unsigned char (__cdecl *ProcessFn)(Inner* self, unsigned char* data, int length);
struct Inner {
    int unused;
    ProcessFn process;     // 0x04
};

static void ReverseBytes(unsigned char* first, unsigned char* last)
{
    while (first < last) {
        unsigned char a = *last;
        unsigned char b = *first;
        *first = a;
        first++;
        *last = b;
        last--;
    }
}

struct Wrapper {
    Inner* inner;
    unsigned char Run(unsigned char* data, int length);
};

// Reverses the buffer, lets the inner object process it, then reverses it back.
unsigned char Wrapper::Run(unsigned char* data, int length)
{
    unsigned char* last = data + length - 1;
    ReverseBytes(data, last);
    unsigned char result = inner->process(inner, data, length);
    ReverseBytes(data, last);
    return result;
}
