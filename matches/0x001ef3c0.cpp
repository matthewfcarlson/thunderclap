struct Entry_1ef3c0 {
    char pad[8];
    void Init(void*);
};
struct Helper_1ef3c0 {
    void Finish();
};
class Owner_1ef3c0 {
  public:
    char pad[0x40];
    int count;
    void Run(void*, void*);
};
void Owner_1ef3c0::Run(void* a, void* b) {
    if (count < 8) {
        ((Entry_1ef3c0*)((char*)this + count * 8))->Init(&a);
        ++count;
    }
    ((Helper_1ef3c0*)&a)->Finish();
}