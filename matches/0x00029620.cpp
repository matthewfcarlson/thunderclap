#include "decls/address.h"
typedef __int64 I64;
struct Item {
    char pad[0x68];
    unsigned char a, b;
};
class Obj {
  public:
    Item* Get(I64);
    void Set(const char*, unsigned char);
};
void Obj::Set(const char* name, unsigned char value) {
    I64 id = FUN_002672f0(name, 0, 0);
    Item* item = Get(id);
    if (item) {
        Item* child = *(Item**)((char*)item + 0x1ca0);
        if (child) {
            child->a = value;
            child->b = value;
        }
    }
}
