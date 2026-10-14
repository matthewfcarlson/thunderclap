class Obj_2ed7a0 {
  public:
    char pad[0x50];
    unsigned char flag;
};
class Container_2ed7a0 {
  public:
    char pad[0x14];
    int* items;
    unsigned int count;
    char pad2[8];
    int* wideItems;
    unsigned int wideCount;
    bool Find(Obj_2ed7a0* obj);
};
bool Container_2ed7a0::Find(Obj_2ed7a0* obj) {
    unsigned int i;
    if (obj->flag) {
        for (i = 0; i < wideCount; ++i) {
            if ((Obj_2ed7a0*)wideItems[i * 5] == obj)
                return true;
        }
    } else {
        for (i = 0; i < count; ++i) {
            if ((Obj_2ed7a0*)items[i] == obj)
                return true;
        }
    }
    return false;
}