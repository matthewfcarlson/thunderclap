extern "C" void* __cdecl memset(void*, int, unsigned int);
struct Record {
    unsigned int size, type, field8, fieldC, value3, value1, value2;
    Record(unsigned int first, unsigned int second, unsigned int third);
};
Record::Record(unsigned int first, unsigned int second, unsigned int third) {
    memset(this, 0, sizeof(*this));
    value1 = first;
    size = 0x1c;
    type = 0xf;
    value2 = second;
    value3 = third;
}