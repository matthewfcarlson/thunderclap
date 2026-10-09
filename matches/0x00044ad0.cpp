typedef unsigned int U32;
struct Pair {
    U32 lo;
    U32 hi;
};
Pair __cdecl Lookup(U32);
class Container {
  public:
    char pad[12];
    int count;
    int* items;
    int Find(U32 a, U32 b);
};
int Container::Find(U32 a, U32 b) {
    int i = 0;
    while (i < count) {
        int item = items[i];
        if (item) {
            Pair v = Lookup((U32)(item + 0x3b0));
            if (v.lo == a && v.hi == b)
                return items[i];
        }
        ++i;
    }
    return 0;
}