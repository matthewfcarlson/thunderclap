extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
class Buffer {
  public:
    short* start;
    short* current;
    short* end;
    bool Init(unsigned int count);
};
bool Buffer::Init(unsigned int count) {
    if (count) {
        start = (short*)FUN_0008d6d0(count * sizeof(short));
        if (start) {
            end = start + count;
            current = start;
            return true;
        }
    } else {
        start = 0;
    }
    current = 0;
    end = 0;
    return false;
}