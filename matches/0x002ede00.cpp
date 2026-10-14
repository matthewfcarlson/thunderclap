extern "C" void* Alloc(unsigned int);
struct Buffer_2ede00 {
    void* p;
    void* begin;
    void* end;
    void Init(int n);
};
void Buffer_2ede00::Init(int n) {
    if (n != 0) {
        void* q = Alloc(n * 4);
        p = q;
        if (q != 0) {
            end = (char*)q + n * 4;
            begin = q;
            return;
        }
    } else {
        p = 0;
    }
    begin = 0;
    end = 0;
}