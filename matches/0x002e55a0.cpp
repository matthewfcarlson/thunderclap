struct Entry {
    int* begin;
    int* end;
    int pad;
};
class Obj {
  public:
    char pad[0x14];
    Entry* entries;
    char Check(int, int*);
    int Count(int);
};
int Obj::Count(int index) {
    if (Check(index, &index) == 1) {
        Entry* e = entries + index;
        return (e->end - e->begin);
    }
    return 0;
}
