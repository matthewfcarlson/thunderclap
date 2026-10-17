// STATUS: equivalent (tools/equiv.py level 3: 2041 inputs, branch coverage 6/6)
// FUN_00337d60 @ 0x00337d60
struct Allocator { char pad[12]; unsigned int offset; unsigned int FUN_00337d60(unsigned int size, unsigned int alignment); };
unsigned int Allocator::FUN_00337d60(unsigned int size, unsigned int alignment) {
    if (size == 0) return 0;
    while (offset % alignment != 0) ++offset;
    unsigned int result = offset;
    offset = result + size;
    return result;
}