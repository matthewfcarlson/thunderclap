// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00229f40 @ 0x00229f40
struct Item_229f40 { char data[12]; };
struct Partition { Item_229f40* leftEnd; Item_229f40* rightBegin; };
extern void __cdecl FUN_002299c0(Partition*, Item_229f40*, Item_229f40*);
extern void __cdecl FUN_00229dd0(Item_229f40*, Item_229f40*);
extern void __cdecl FUN_002298e0(Item_229f40*, Item_229f40*, int, int);
extern void __cdecl FUN_00229ea0(Item_229f40*, Item_229f40*);
void __cdecl FUN_00229f40(Item_229f40* first, Item_229f40* last, int budget) {
    while (last-first > 32) {
        if (budget <= 0) {
            if (last-first > 1) FUN_002298e0(first,last,0,0);
            FUN_00229ea0(first,last);
            return;
        }
        Partition split;
        FUN_002299c0(&split,first,last);
        budget = budget/2 + (budget/2)/2;
        if (split.leftEnd-first < last-split.rightBegin) {
            FUN_00229f40(first,split.leftEnd,budget);
            first=split.rightBegin;
        } else {
            FUN_00229f40(split.rightBegin,last,budget);
            last=split.leftEnd;
        }
    }
    if (last-first > 1) FUN_00229dd0(first,last);
}
