struct Item { void Do(); };
class X { public: char pad[0x0c]; int count; Item** items; bool Run(); };
bool X::Run() {
    int i;
    for (i = 0; i < count; ++i) {
        Item* p = items[i];
        if (p) p->Do();
    }
    return true;
}