extern "C" void* alloc(unsigned int);
class Buffer {
  public:
    int* begin;
    int* end;
    int* limit;
    bool Init(int n);
};
bool Buffer::Init(int n) {
    if (n != 0) {
        int* p = (int*)alloc(n * 4);
        begin = p;
        if (p != 0) {
            limit = (int*)((char*)p + n * 4);
            end = p;
            return true;
        }
    } else {
        begin = 0;
    }
    end = 0;
    limit = 0;
    return false;
}