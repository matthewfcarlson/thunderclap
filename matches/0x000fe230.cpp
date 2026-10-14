class Item_fe230 {
  public:
    virtual void f();
    virtual void Release();
};
class Container_fe230 {
  public:
    char pad[8];
    int count;
    int entries[1];
    int Remove(int key);
};
int Container_fe230::Remove(int key) {
    int i = 0;
    if (count > 0) {
        while (i < count) {
            if (entries[i] == key) {
                Item_fe230* p = (Item_fe230*)entries[i];
                if (p != 0) {
                    p->Release();
                    entries[i] = 0;
                }
                --count;
                break;
            }
            ++i;
        }
    }
    if (i < count) {
        do {
            entries[i] = entries[i + 1];
            ++i;
        } while (i < count);
    }
    return 1;
}