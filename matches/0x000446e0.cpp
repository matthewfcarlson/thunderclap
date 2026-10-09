struct Entry {
    unsigned __int64 value;
    char pad[0x20];
};
class Thing {
  public:
    char pad[0x1c0];
    Entry values[8];
    unsigned __int64 Get(int index);
};
unsigned __int64 Thing::Get(int index) {
    if (index >= 0 && index < 8)
        return values[index].value;
    return 0;
}