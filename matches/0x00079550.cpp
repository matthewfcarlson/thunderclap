extern float gValue;
class Item {
  public:
    void Set(float);
};
class Thing {
  public:
    char pad[0x374c];
    Item* items[20];
    int count;
    void Run(float value);
};
void Thing::Run(float value) {
    gValue = value;
    for (int i = 0; i < count; ++i)
        items[i]->Set(value);
}