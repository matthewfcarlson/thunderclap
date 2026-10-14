// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 12/14, incomplete)
// FUN_00311c20 @ 0x00311c20
struct Partition { int* first; int* second; };
void __cdecl FUN_003119b0(Partition* result, int* begin, int* end);
void __cdecl FUN_00311b20(int* begin, int* end);
void __cdecl FUN_00311910(int* begin, int* end, int a, int b);
void __cdecl FUN_00311bd0(int* begin, int* end);
void __cdecl FUN_00311c20(int* begin, int* end, int depth) {
    while (end - begin > 32) {
        if (depth <= 0) {
            if (((int)end - (int)begin & ~3) > 4)
                FUN_00311910(begin, end, 0, 0);
            FUN_00311bd0(begin, end);
            return;
        }
        Partition split;
        FUN_003119b0(&split, begin, end);
        depth /= 2;
        depth += depth / 2;
        if ((((int)split.first - (int)begin) & ~3) < (((int)end - (int)split.second) & ~3)) {
            FUN_00311c20(begin, split.first, depth);
            begin = split.second;
        } else {
            FUN_00311c20(split.second, end, depth);
            end = split.first;
        }
    }
    if (end - begin > 1) FUN_00311b20(begin, end);
}
