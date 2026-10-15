struct Item {
    char pad[0x1d4c];
    unsigned char flag;
};
class Owner {
  public:
    Item* Lookup(unsigned __int64);
    unsigned char Query(int);
};
unsigned __int64 __cdecl Convert(int, int, int);
unsigned char Owner::Query(int value) {
    unsigned __int64 key = Convert(value, 0, 0);
    Item* item = Lookup(key);
    if (!item)
        return 0;
    return item->flag;
}