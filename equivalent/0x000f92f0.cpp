// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 2/2)
// FUN_000f92f0 @ 0x000f92f0
struct Record {
    int a;
    int b;
    int index;
    int pad;
};
struct List {
    int count;
    int pad4;
    Record recs[64];
    int FUN_000f9140(int a, int b);
};
struct Owner {
    char pad0[0x458];
    List list;
    int size;
    char flags[1];
    int FUN_000f92f0(int a, int b, char value);
};

int Owner::FUN_000f92f0(int a, int b, char value)
{
    int found = list.FUN_000f9140(a, b);
    if (found != -1) {
        flags[found] = value;
        return found;
    }
    flags[size] = value;
    int index = size;
    int n = list.count;
    list.recs[n].a = a;
    list.recs[n].b = b;
    list.recs[n].index = index;
    list.count++;
    size++;
    return size;
}
