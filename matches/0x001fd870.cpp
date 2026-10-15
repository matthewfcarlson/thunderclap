typedef unsigned __int64 U64;
struct Data {
    int a, b, c;
};
U64 __cdecl Convert(int);
class Item {
  public:
    void Update(Data*);
};
class Owner {
  public:
    Item* Find(U64);
    bool Do(int, Data);
};
bool Owner::Do(int n, Data d) {
    U64 id = Convert(n);
    Item* item = Find(id);
    if (!item)
        return false;
    item->Update(&d);
    return true;
}