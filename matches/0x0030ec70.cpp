extern "C" void* __cdecl Allocate(unsigned int);
class Buffer {
  public:
    char pad[12];
    int count;
    unsigned int* data;
    bool Add(unsigned int);
};
bool Buffer::Add(unsigned int value) {
    if (data == 0) {
        data = (unsigned int*)Allocate(count << 2);
        count = 0;
    }
    data[count] = value;
    ++count;
    return true;
}