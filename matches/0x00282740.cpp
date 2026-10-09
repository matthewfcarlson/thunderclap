struct Item { char pad[0x7c]; float value; };
struct Slot { Item *ptr; char pad[12]; };
class Obj { public: char pad48[0x48]; Slot *items; char pad4c[0x5c-0x4c]; unsigned int *keys; void Update(unsigned int key); };
extern const float zero;
void Obj::Update(unsigned int key) {
    unsigned int *p = keys;
    int i = 0;
    while (i < 6) {
        if (*p == key) {
            Item *v = items[key % 6].ptr;
            if (v->value > zero) v->value = 0.0f;
            return;
        }
        ++i;
        p += 2;
    }
}