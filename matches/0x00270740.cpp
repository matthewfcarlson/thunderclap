extern "C" void* memcpy(void*, const void*, unsigned int);

class ControllerBuffer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int vfunc_5(const void* src);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    char pad[0x10];
    unsigned int capacity;
    unsigned int size;
    unsigned int readIndex;
    unsigned int writeIndex;
    unsigned int* buffers;
};

unsigned int ControllerBuffer::vfunc_5(const void* src) {
    memcpy((void*)buffers[writeIndex], src, size);
    unsigned int n = (writeIndex + 1) % capacity;
    unsigned int r = readIndex;
    writeIndex = n;
    if (n == r) {
        r = r + 1;
        readIndex = r % capacity;
        return r / capacity;
    }
    return r;
}
