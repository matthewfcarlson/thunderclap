// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_002ffe00 @ 0x002ffe00
void __cdecl FUN_002ff860(int* begin, int index, int count, int value);

void __cdecl FUN_002ffe00(int* begin, int* end)
{
    int count = end - begin;
    int half = (count - (count >> 31)) >> 1;
    while (half > 0) {
        int value = begin[half - 1];
        --half;
        FUN_002ff860(begin, half, count, value);
    }
}