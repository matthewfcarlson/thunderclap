// Same code shape as 0x000f27a0 (propagated; names are from that function)
extern void* Alloc(unsigned int);
class Factory {
  public:
    int Create(int, int);
};
class Holder {
  public:
    int field;
    int data;
    int slots[32];
    int Run(int arg);
};
int Holder::Run(int arg) {
    if (data == 0)
        return 0;
    Factory* obj = (Factory*)Alloc(100);
    int result;
    if (obj != 0)
        result = obj->Create(data, arg);
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}
