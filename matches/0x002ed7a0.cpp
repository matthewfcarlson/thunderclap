class Obj { public: char pad[0x50]; unsigned char flag; };
class Container { public: char pad[0x14]; int *items; unsigned int count; char pad2[8]; int *wideItems; unsigned int wideCount; bool Find(Obj *obj); };
bool Container::Find(Obj *obj) {
    unsigned int i;
    if (obj->flag) {
        for (i = 0; i < wideCount; ++i) {
            if ((Obj*)wideItems[i * 5] == obj) return true;
        }
    } else {
        for (i = 0; i < count; ++i) {
            if ((Obj*)items[i] == obj) return true;
        }
    }
    return false;
}