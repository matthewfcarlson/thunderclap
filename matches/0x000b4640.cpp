struct Item_b4640 {
    void Clear();
    char pad[8];
};
struct Thing_b4640 {
    Item_b4640 a;
    Item_b4640 b;
    Item_b4640 c;
    Item_b4640 d;
    Thing_b4640* Run();
};
Thing_b4640* Thing_b4640::Run() {
    a.Clear();
    b.Clear();
    c.Clear();
    d.Clear();
    return this;
}