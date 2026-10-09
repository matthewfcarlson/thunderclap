class C {
  public:
    int Find(int key);
    char pad[0x4fc];
    int data[0x13 + 0x13];
};
int C::Find(int key) {
    int result = 0;
    int* p = (int*)((char*)this + 0x4fc);
    for (int i = 0; i < 0x13; i++, p++)
        if (p[0x13] == key)
            result = p[0];
    return result;
}