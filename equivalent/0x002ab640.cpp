// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002ab640 @ 0x002ab640
struct Block { unsigned int words[16]; };
extern "C" void * __cdecl FUN_002ab640(void * destination_, unsigned int count, const void * source)
{
    Block * destination = (Block *)destination_;
    if (count == 0) return (Block *)destination;
    do {
        if (destination != 0) {
            for (int i = 0; i < 16; ++i)
                destination->words[i] = ((const Block *)source)->words[i];
        }
        ++destination;
    } while (--count != 0);
    return (Block *)destination;
}