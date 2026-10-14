class Item_1e8880 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void Destroy(int flag);
};

class Holder_1e8880 {
  public:
    char pad[8];
    Item_1e8880* mItems[100];
    int mCount;
    void Remove(Item_1e8880* item);
};

void Holder_1e8880::Remove(Item_1e8880* item) {
    if (!item)
        return;
    int i;
    for (i = 0; i < mCount; i++) {
        if (mItems[i] == item) {
            Item_1e8880* p = mItems[i];
            Item_1e8880** slot = &mItems[i];
            if (p)
                p->Destroy(1);
            *slot = 0;
            int j = i;
            while (j < mCount - 1) {
                mItems[j] = mItems[j + 1];
                j++;
            }
            mCount--;
            mItems[mCount] = 0;
            return;
        }
    }
}
