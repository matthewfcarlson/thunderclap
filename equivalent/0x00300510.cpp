// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00300510 @ 0x00300510
void __cdecl FUN_002ff860(int *items, int start, int count, int value);

void __cdecl FUN_00300510(int *first, int *last)
{
    int count = last - first;
    while (count > 1) {
        int value = first[count - 1];
        first[count - 1] = first[0];
        FUN_002ff860(first, 0, count - 1, value);
        --count;
    }
}