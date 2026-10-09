class Item {
  public:
    char pad[0x10];
    char Check(int key);
    void Clear(int x);
};
class Owner {
  public:
    char pad[0x2150];
    Item items[16];
    int Find(int key);
    char Update(int key, int value);
};
char Owner::Update(int key, int value) {
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
