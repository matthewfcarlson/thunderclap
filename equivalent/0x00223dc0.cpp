// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00223dc0 @ 0x00223dc0
struct Record { char data[40]; };
struct Partition { Record* first; Record* second; };
extern void __cdecl FUN_00223870(Partition*, Record*, Record*);
extern void __cdecl FUN_00223c20(Record*, Record*);
extern void __cdecl FUN_00223760(Record*, Record*, int, int);
extern void __cdecl FUN_00223d20(Record*, Record*);
void __cdecl FUN_00223dc0(Record* first, Record* last, int depth) {
    while (last - first > 32) {
        if (depth <= 0) {
            if (last - first > 1) FUN_00223760(first, last, 0, 0);
            FUN_00223d20(first, last);
            return;
        }
        Partition middle;
        FUN_00223870(&middle, first, last);
        depth = depth / 2;
        depth += depth / 2;
        if (middle.first - first < last - middle.second) {
            FUN_00223dc0(first, middle.first, depth);
            first = middle.second;
        } else {
            FUN_00223dc0(middle.second, last, depth);
            last = middle.first;
        }
    }
    if (last - first > 1) FUN_00223c20(first, last);
}
