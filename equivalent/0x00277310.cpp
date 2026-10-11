// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 14/14)
// FUN_00277310 @ 0x00277310
// equiv-conv: FUN_00277310 eax edi stack stack
void* __cdecl FUN_00277310(unsigned int upper, unsigned int stride, const void* base, unsigned int key)
{
    if (upper == 0) return 0;
    unsigned int lower = 0;
    do {
        unsigned int middle = (upper >> 1) + (lower >> 1);
        if ((lower & 1) && (upper & 1)) ++middle;
        const char* entry = static_cast<const char*>(base) + middle * stride;
        unsigned int value = *reinterpret_cast<const unsigned int*>(entry);
        if (value == key) return const_cast<char*>(entry);
        if (value < key) lower = middle + 1;
        else {
            if (middle == 0) return 0;
            upper = middle - 1;
        }
    } while (lower <= upper);
    return 0;
}
