typedef unsigned __int64 U64;
U64 __cdecl Make(unsigned int, int, int);
struct State {
    char pad[0xe8];
    unsigned char flag;
};
class Item {
  public:
    char pad[0x1ca0];
    State* state;
};
class Owner {
  public:
    Item* Lookup(U64);
    unsigned char Check(unsigned int);
};
unsigned char Owner::Check(unsigned int id) {
    Item* item = Lookup(Make(id, 0, 0));
    State* state = item ? item->state : 0;
    if (!state)
        return 0;
    return state->flag;
}