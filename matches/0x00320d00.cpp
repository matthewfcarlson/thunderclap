class Holder_320d00 {
    char pad[0x184];

  public:
    bool Find(int value);
};
bool Holder_320d00::Find(int value) {
    int i = 0;
    int* p = (int*)((char*)this + 0x184);
    do {
        int x = *p;
        if (x == -1)
            return false;
        if (x == value)
            return true;
        ++i;
        ++p;
    } while (i < 0x20);
    return false;
}