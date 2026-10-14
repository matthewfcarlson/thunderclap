class Helper_24380 {
  public:
    int Lookup(int);
};
class Obj_24380 {
  public:
    virtual void v0();
    char pad[8];
    int count;
    int items[1];
    void removeAt(int);
    bool find(int);
};
bool Obj_24380::find(int value) {
    int i = 0;
    if (count > 0) {
        do {
            Helper_24380* h = *(Helper_24380**)((char*)*(int**)this + 0x44);
            int result = h->Lookup(items[i]);
            if (result != 0 && result == value) {
                removeAt(i);
                return true;
            }
            ++i;
        } while (i < count);
    }
    return false;
}
