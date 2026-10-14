struct Item_adbd0 {
    void Run();
};
struct Holder_adbd0 {
    char pad[0x10];
    int count;
    Item_adbd0** items;
    void Run();
};
void Holder_adbd0::Run() {
    for (int i = 0; i < count; ++i)
        items[i]->Run();
}