class Item {
  public:
    float Apply(float*);
};
class Obj {
  public:
    char pad[0x24];
    float val;
    Item* GetItem();
    float Run();
};
float Obj::Run() {
    volatile float f = 10000.0f;
    Item* p = GetItem();
    if (p)
        return p->Apply(&val);
    return f;
}