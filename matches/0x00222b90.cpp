struct Item {
    void* pad;
    float val;
    char flag;
    char rest[31];
};
class Obj {
    char pad[0x68];
    int count;
    Item items[1];

  public:
    void Clear(char b);
};
class Ref {
  public:
    virtual void a();
    virtual void release();
};
void Obj::Clear(char b) {
    if (b) {
        for (int i = count - 1; i >= 0; --i)
            ((Ref*)items[i].pad)->release();
        count = 0;
    } else {
        for (int i = count - 1; i >= 0; --i) {
            items[i].val = -1.0f;
            items[i].flag = 0;
        }
    }
}