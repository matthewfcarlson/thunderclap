// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_00300bc0 @ 0x00300bc0
struct Partition { int* first; int* second; };
void __cdecl FUN_00300100(Partition*, int*, int*);
void __cdecl FUN_00300270(int*, int*);
void __cdecl FUN_002ffe00(int*, int*, int, int);
void __cdecl FUN_00300510(int*, int*);
void __cdecl FUN_00300bc0(int* first, int* last, int budget) {
    while (last - first > 32) {
        if (budget <= 0) {
            if (last - first > 1) FUN_002ffe00(first, last, 0, 0);
            FUN_00300510(first, last);
            return;
        }
        Partition split;
        FUN_00300100(&split, first, last);
        budget = budget / 2;
        budget += budget / 2;
        if (split.first - first < last - split.second) {
            FUN_00300bc0(first, split.first, budget);
            first = split.second;
        } else {
            FUN_00300bc0(split.second, last, budget);
            last = split.first;
        }
    }
    if (last - first > 1) FUN_00300270(first, last);
}
