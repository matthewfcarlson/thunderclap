#include "compat/ptr.h"
extern "C" void* alloc(hulk_uintptr);
class ShadowMeshVertices {
  public:
    virtual ~ShadowMeshVertices();
    int m1;
    int count;
    int count2;
    void* p1;
    void* p2;
    ShadowMeshVertices(int, int);
};
ShadowMeshVertices::ShadowMeshVertices(int a, int b) {
    m1 = 0;
    p1 = 0;
    p2 = 0;
    count = a;
    count2 = b;
    p1 = alloc(a * 12);
    p2 = alloc(count2 * 12);
}