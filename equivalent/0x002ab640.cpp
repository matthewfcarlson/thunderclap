// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002ab640 @ 0x002ab640
struct Block { unsigned int words[16]; };
Block* __cdecl FUN_002ab640(Block* destination, unsigned int count, const Block* source)
{
    if (count == 0) return destination;
    do {
        if (destination != 0) {
            for (int i = 0; i < 16; ++i)
                destination->words[i] = source->words[i];
        }
        ++destination;
    } while (--count != 0);
    return destination;
}