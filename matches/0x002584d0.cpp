// om::Type's constructor: the two type keys, an instance's size and alignment (records.h OmType: the class has the
// record's layout on both builds).
#include "decls/data/records.h"
class Type {
  public:
    virtual void f();
    unsigned int reserved04;
    OmTypeBody body;
    Type(const OmKey* baseKey, const OmKey* key, int size, int align);
};
Type::Type(const OmKey* baseKey, const OmKey* key, int size, int align) {
    body.baseKey = *baseKey;
    body.key = *key;
    body.size = size;
    body.align = align;
}
