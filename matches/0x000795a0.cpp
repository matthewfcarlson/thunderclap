extern "C" float DAT_0049b890;
class Item {
  public:
    void Update(float);
};
class Obj {
  public:
    char pad[0x374c];
    Item* items[20];
    int count;
    void Run(float);
};
void Obj::Run(float value) {
    DAT_0049b890 = value;
    for (int i = 0; i < count; ++i)
        items[i]->Update(value);
}