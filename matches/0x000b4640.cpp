struct Item {
    void Clear();
    char pad[8];
};
struct Thing {
    Item a;
    Item b;
    Item c;
    Item d;
    Thing* Run();
};
Thing* Thing::Run() {
    a.Clear();
    b.Clear();
    c.Clear();
    d.Clear();
    return this;
}