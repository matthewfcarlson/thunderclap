// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 4/4)
// FUN_002c0200 @ 0x002c0200
// equiv-conv: FUN_002c0200 eax edx ecx stack stack stack
void FUN_002c0200(const unsigned char *source, unsigned char *destination, int count, unsigned int bytes, int sourceStride, int destinationStride)
{
    for (int row = 0; row < count; ++row) {
        const unsigned int *wordsSource = (const unsigned int *)source;
        unsigned int *wordsDestination = (unsigned int *)destination;
        for (unsigned int i = 0; i < (bytes >> 2); ++i)
            wordsDestination[i] = wordsSource[i];
        for (unsigned int j = bytes & 3, offset = bytes & ~3U; j; --j, ++offset)
            destination[offset] = source[offset];
        source += sourceStride;
        destination += destinationStride;
    }
}
