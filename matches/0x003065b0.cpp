class Child {
  public:
    void Update(int value);
};
class PtrRange {
  public:
    Child** begin;
    Child** end;
};
class Owner {
  public:
    char pad[0x10];
    int value;
    PtrRange* items;
    void Set(int v);
};
void Owner::Set(int v) {
    if (value != v) {
        value = v;
        if (items) {
            for (unsigned int i = 0; i < (unsigned int)(items->end - items->begin); ++i) {
                items->begin[i]->Update(value);
            }
        }
    }
}
