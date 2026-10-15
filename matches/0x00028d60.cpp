typedef unsigned __int64 U64;
U64 __cdecl makeKey(int, int, int);
struct Item {
    char pad[0x1ca0];
    struct Status* status;
};
struct Status {
    char pad[0xe9];
    unsigned char enabled;
};
class Owner {
  public:
    Item* get(U64);
    void act(int);
};
void Owner::act(int n) {
    U64 key = makeKey(n, 0, 0);
    Item* item = get(key);
    if (item && item->status)
        item->status->enabled = 1;
}
