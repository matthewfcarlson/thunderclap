class Item {
  public:
    virtual void F0();
    virtual void F1();
    virtual void Destroy(int flag);
};

class Holder {
  public:
    char pad[8];
    Item* mItems[100];
    int mCount;
    void Remove(Item* item);
};

void Holder::Remove(Item* item) {
    if (!item)
        return;
    int i;
    for (i = 0; i < mCount; i++) {
        if (mItems[i] == item) {
            Item* p = mItems[i];
            Item** slot = &mItems[i];
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
