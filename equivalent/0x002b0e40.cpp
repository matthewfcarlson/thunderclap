// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002b0e40 @ 0x002b0e40
struct Record { unsigned int value[6]; };
Record* __cdecl FUN_002b0e40(Record* destination, int count, const Record* source)
{
    if (count == 0) return destination;
    do {
        if (destination != 0) {
            destination->value[0] = source->value[0];
            destination->value[1] = source->value[1];
            destination->value[2] = source->value[2];
            destination->value[3] = source->value[3];
            destination->value[4] = source->value[4];
            destination->value[5] = source->value[5];
        }
        ++destination;
        --count;
    } while (count != 0);
    return destination;
}