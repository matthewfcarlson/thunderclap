extern "C" void freebuf(void*);
extern char* sentinel;
struct Str {
    char* data;
    short type;
    void release();
};
void Str::release() {
    if (type == 2) {
        char* p = data;
        if (*(volatile short*)(p - 4) == 1) {
            if (p != sentinel) {
                freebuf(p - 8);
                return;
            }
        } else {
            --*(short*)(p - 4);
        }
    }
}