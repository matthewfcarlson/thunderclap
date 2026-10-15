class Item {
  public:
    void Set(float);
};
class Obj {
    char pad[0x374c];
    Item* items[20];
    int count;

  public:
    void Run(float x);
};
extern float g;
void Obj::Run(float x) {
    g = x;
    for (int i = 0; i < count; i++)
        items[i]->Set(x);
}