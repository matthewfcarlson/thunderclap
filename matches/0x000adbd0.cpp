struct Item {
    void Run();
};
struct Holder {
    char pad[0x10];
    int count;
    Item** items;
    void Run();
};
void Holder::Run() {
    for (int i = 0; i < count; ++i)
        items[i]->Run();
}