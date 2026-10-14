typedef unsigned int u32_2706a0;
class ControllerBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(u32_2706a0);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x0c];
    void* buffer;
    u32_2706a0 capacity;
    u32_2706a0 stride;
    u32_2706a0 current;
    u32_2706a0 next;
    void* data2;
    void* allocator;
};
extern void Free(void*, void*);
extern void* Alloc(void*, u32_2706a0);
void ControllerBuffer::f4(u32_2706a0 n) {
    if (capacity == n)
        return;
    if (buffer && data2) {
        Free(allocator, buffer);
        Free(allocator, data2);
    }
    capacity = n;
    buffer = Alloc(allocator, stride * n);
    data2 = Alloc(allocator, capacity * 4);
    for (u32_2706a0 i = 0; i < capacity; ++i)
        ((void**)data2)[i] = (char*)buffer + stride * i;
    current = 0;
    next = 0;
}