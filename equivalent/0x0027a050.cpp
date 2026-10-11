// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 15/16, incomplete)
// FUN_0027a050 @ 0x0027a050
// equiv-conv: FUN_0027a050 ecx stack stack stack stack
unsigned int* __cdecl FUN_0027a050(unsigned int distance, const unsigned char* data, unsigned int size, unsigned int* position, unsigned int* length)
{
    *position = 0;
    *length = 0;
    for (unsigned int offset = 0; offset < distance; ++offset) {
        if (((offset - distance) & 15) == 0) continue;
        unsigned int limit = size - offset;
        if (limit == 0) continue;
        unsigned int i = 0;
        do {
            unsigned int next = i + 1;
            if (distance + next - 1 >= size) break;
            if (data[offset + i] != data[distance + i]) break;
            if (next > *length) {
                *length = next;
                *position = offset;
            }
            i = next;
        } while (i < limit);
    }
    *position = distance - *position;
    return position;
}
