typedef unsigned int U32_44ad0;
struct Pair_44ad0 {
    U32_44ad0 lo;
    U32_44ad0 hi;
};
Pair_44ad0 __cdecl Lookup(U32_44ad0);
class RDLHandler_44ad0 {
  public:
    char pad[12];
    int count;
    int* items;
    int Find(U32_44ad0 a, U32_44ad0 b);
};
int RDLHandler_44ad0::Find(U32_44ad0 a, U32_44ad0 b) {
    int i = 0;
    while (i < count) {
        int item = items[i];
        if (item) {
            Pair_44ad0 v = Lookup((U32_44ad0)(item + 0x3b0));
            if (v.lo == a && v.hi == b)
                return items[i];
        }
        ++i;
    }
    return 0;
}