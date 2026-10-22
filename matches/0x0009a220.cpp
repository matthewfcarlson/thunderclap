class Item_9a220 {
  public:
    virtual void A();
    virtual void Release();
};
class CCameraManager_9a220 {
  public:
    char pad[0x80];
    volatile int a, b, c, d;
    volatile float f;
    volatile int g, unused, count;
    Item_9a220* items[1];
    void Clear();
};
void CCameraManager_9a220::Clear() {
    c = 0;
    b = 0;
    a = 0;
    int n = count;
    int i = 0;
    d = 0;
    f = -1.0f;
    g = 0;
    if (n > 0) {
        do {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            ++i;
        } while (i < count);
    }
    count = 0;
}