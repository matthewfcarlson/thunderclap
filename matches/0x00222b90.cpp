struct Item_222b90 {
    void* pad;
    float val;
    char flag;
    char rest[31];
};
class Obj_222b90 {
    char pad[0x68];
    int count;
    Item_222b90 items[1];

  public:
    void Clear(char b);
};
class Ref_222b90 {
  public:
    virtual void a();
    virtual void release();
};
void Obj_222b90::Clear(char b) {
    if (b) {
        for (int i = count - 1; i >= 0; --i)
            ((Ref_222b90*)items[i].pad)->release();
        count = 0;
    } else {
        for (int i = count - 1; i >= 0; --i) {
            items[i].val = -1.0f;
            items[i].flag = 0;
        }
    }
}