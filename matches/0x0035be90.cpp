// cl-flags: /Oy-
struct Thing {
    char bytes[0x408];
    Thing();
    ~Thing();
};
extern "C" void work();
void target() {
    Thing t;
    try {
        work();
    } catch (...) {
        throw;
    }
}