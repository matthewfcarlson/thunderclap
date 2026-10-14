// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 16/20, incomplete)
// FUN_002a23d0 @ 0x002a23d0
typedef bool (__cdecl *Less)(int a, int b);

void __cdecl FUN_002a1ac0(int *first, int *middle, int *last, int a, int b);

// Insertion sort of [first, last) of 4-byte elements with a comparison callback.
void FUN_002a23d0(int *first, int *last, Less less)
{
    if (first == last)
        return;
    for (int *cur = first + 1; cur != last; cur++) {
        int *next = cur + 1;
        int *pos;
        if (less(*cur, *first)) {
            pos = first;
        } else {
            pos = cur;
            while (less(*cur, *(pos - 1)))
                pos--;
        }
        if (pos != cur && cur != next)
            FUN_002a1ac0(pos, cur, next, 0, 0);
    }
}
