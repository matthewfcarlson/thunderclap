struct Item {
    char pad[0x54];
    short id;
};
struct List {
    char pad[0x18];
    int Count();
    Item* Get(int);
};
struct Holder {
    char pad[4];
    List* list;
};
class Obj {
  public:
    char pad[0x5a4];
    char flags[256];
    int Find();
};
Holder* __cdecl Fetch();
int Obj::Find() {
    Holder* h = Fetch();
    List* list = h->list;
    int count = ((List*)((char*)list + 0x18))->Count();
    for (int i = 0; i < count; ++i) {
        Item* p = list->Get(i);
        int id = p->id;
        if (flags[id] == 2)
            return id;
    }
    return -1;
}