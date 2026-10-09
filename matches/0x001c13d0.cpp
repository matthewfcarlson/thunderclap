// Same code shape as 0x001c1340 (propagated; names are from that function)
struct Child {
    void First(int);
    void Second();
    void Third();
};
struct Thing {
    char pad[0xbc];
    Child* volatile child;
    int value;
    void Run();
};
void Thing::Run() {
    child->First(value);
    child->Second();
    child->Third();
}