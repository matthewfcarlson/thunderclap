// Same code shape as 0x002b0fb0 (propagated; names are from that function)
extern void* Alloc(unsigned int);
extern void Init(void*, unsigned int, void*);
class Buffer {
  public:
    int* begin;
    int* end;
    bool Make(unsigned int count, void* arg);
};
bool Buffer::Make(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        begin = (int*)Alloc(count * 8);
        if (begin != 0) {
            end = (int*)((char*)begin + count * 8);
            Init(begin, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}