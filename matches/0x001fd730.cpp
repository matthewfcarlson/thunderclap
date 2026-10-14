class Item_1fd730 {
  public:
    virtual void A();
    virtual void Release();
};
class Part_1fd730 {
  public:
    void Run();
};
class Obj_1fd730 {
  public:
    char p0[8];
    int f8;
    Item_1fd730* items[128];
    int f20c;
    char p210[0x24];
    Part_1fd730* parts;
    void Clear();
};
void Obj_1fd730::Clear() {
    int i;
    for (i = 0; i < 128; i++) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    f8 = 0;
    f20c = 0;
    for (i = 0; i < 0x6380; i += 0xc70)
        ((Part_1fd730*)((char*)parts + i))->Run();
}
