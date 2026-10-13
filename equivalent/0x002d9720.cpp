// STATUS: equivalent (tools/equiv.py level 3: 1854 inputs, branch coverage 24/24)
// FUN_002d9720 @ 0x002d9720
struct ImageSpan {
    unsigned int count;
    unsigned int endOffset;
    unsigned char format;
    unsigned char depth;
};
void __cdecl FUN_002d9720(const ImageSpan* span, unsigned char* buffer)
{
    unsigned int count = span->count;
    unsigned char format = span->format;
    if (format != 6 && format != 4) return;
    unsigned int stride;
    unsigned int alphaBytes;
    if (span->depth == 8) {
        stride = format == 6 ? 4 : 2;
        alphaBytes = 1;
    } else {
        stride = format == 6 ? 8 : 4;
        alphaBytes = 2;
    }
    unsigned char* end = buffer + span->endOffset;
    for (unsigned int i = 0; i < count; ++i) {
        for (unsigned int j = 0; j < alphaBytes; ++j) {
            --end;
            *end = (unsigned char)(255 - *end);
        }
        for (unsigned int j = alphaBytes; j < stride; ++j) {
            --end;
            *end = *end;
        }
    }
}
