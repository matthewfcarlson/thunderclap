struct Item {
    void SetAngle(float);
};
struct Owner {
    Item* Find(int, int);
    bool Set(int key, float angle);
};
struct Pair {
    int a, b;
};
Pair __cdecl Lookup(int);
bool Owner::Set(int key, float angle) {
    Pair p = Lookup(key);
    Item* item = Find(p.a, p.b);
    if (!item)
        return false;
    item->SetAngle(angle * 0.017453292519943295f);
    return true;
}