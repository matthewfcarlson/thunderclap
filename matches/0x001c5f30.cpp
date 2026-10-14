class Thing_1c5f30 {
  public:
    int pad0;
    unsigned int* data;
    unsigned int count;
    unsigned int capacity;
    void Add(unsigned int value);
};
extern "C" void* Alloc(unsigned int);
extern "C" void Free(void*);
void Thing_1c5f30::Add(unsigned int value) {
    unsigned int* p;
    unsigned int n;
    if (count >= capacity) {
        if (capacity == 0)
            capacity = 0x32;
        capacity = capacity * 2;
        p = (unsigned int*)Alloc(capacity * 4);
        if (data != 0) {
            n = 0;
            while (n < count) {
                p[n] = data[n];
                ++n;
            }
            Free(data);
        }
        data = p;
    }
    data[count] = value;
    ++count;
}