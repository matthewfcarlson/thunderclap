struct Item {
    char pad[0x1c];
    float value;
    void Set(float);
};
class Obj {
  public:
    char pad[0x374c];
    Item* items[1];
    int Find(__int64);
    void Run(int id, float delta);
};
extern __int64 __cdecl Convert(int);
void Obj::Run(int id, float delta) {
    __int64 x = Convert(id);
    int index = Find(x);
    if (index != -1) {
        Item* p = items[index];
        p->Set(p->value + delta);
    }
}