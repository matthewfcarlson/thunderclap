extern void* Alloc(unsigned int);
extern void Init(void*, unsigned int, void*);

class Buffer {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};

bool Buffer::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}