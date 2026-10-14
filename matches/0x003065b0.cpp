class Child_3065b0 {
  public:
    void Update(int value);
};
class PtrRange_3065b0 {
  public:
    Child_3065b0** begin;
    Child_3065b0** end;
};
class Owner_3065b0 {
  public:
    char pad[0x10];
    int value;
    PtrRange_3065b0* items;
    void Set(int v);
};
void Owner_3065b0::Set(int v) {
    if (value != v) {
        value = v;
        if (items) {
            for (unsigned int i = 0; i < (unsigned int)(items->end - items->begin); ++i) {
                items->begin[i]->Update(value);
            }
        }
    }
}
