class C {
public:
    char pad[0x1f8];
    char *items;
    int count;
    bool Set(int index, unsigned char value);
};
bool C::Set(int index, unsigned char value) {
    bool result = false;
    if (index >= 0 && index < count) {
        items[index * 0x34 + 0x30] = value;
        result = true;
    }
    return result;
}