extern "C" __int64 __cdecl makeKey(int, int, int);
struct Item {
    char pad[0x1d78];
    unsigned char flag;
};
class Owner {
  public:
    Item* lookup(__int64 key);
    void set(int key, unsigned char value);
};
void Owner::set(int key, unsigned char value) {
    __int64 k = makeKey(key, 0, 0);
    Item* p = lookup(k);
    if (p)
        p->flag = value;
}
