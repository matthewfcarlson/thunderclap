class Item_36e70 {
  public:
    char pad[0x10];
    char Check(int key);
    void Clear(int x);
};
class Owner_36e70 {
  public:
    char pad[0x2150];
    Item_36e70 items[16];
    int Find(int key);
    char Update(int key, int value);
};
char Owner_36e70::Update(int key, int value) {
    int i;
    if (value == 0) {
        for (i = 0; i < 16; ++i) {
            if (items[i].Check(key)) {
                items[i].Clear(0);
                *(int*)((char*)this + 0x2158 + i * 16) = 0;
                return 1;
            }
        }
        return 1;
    }
    i = Find(key);
    if (i < 0)
        return 0;
    *(int*)((char*)this + 0x2158 + i * 16) = value;
    return 1;
}
