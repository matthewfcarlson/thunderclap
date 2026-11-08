#include "compat/ptr.h"
#include "decls/data/records.h"

struct Node {
    hulk_uintptr a;
    Node* next;
};
class SubObj_2728e0 {
  public:
    virtual void Fn0();
    virtual void Fn1();
};
// core::Drive (records.h CoreDrive): appends a request to the pending list, under the IMutable lock at +0xc
class Container_2728e0 : public CoreDrive {
  public:
    void Add(Node* p);
};
void Container_2728e0::Add(Node* p) {
    ((SubObj_2728e0*)&vftableMutable)->Fn0();
    if (requests == 0) {
        requests = p;
    } else {
        ((Node*)lastRequest)->next = p;
    }
    p->next = 0;
    lastRequest = p;
    ((SubObj_2728e0*)&vftableMutable)->Fn1();
}
