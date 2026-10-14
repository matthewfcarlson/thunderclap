struct Child_1c1340 {
    void First(int);
    void Second();
    void Third();
};
struct Thing_1c1340 {
    char pad[0xbc];
    Child_1c1340* volatile child;
    int value;
    void Run();
};
void Thing_1c1340::Run() {
    child->First(value);
    child->Second();
    child->Third();
}