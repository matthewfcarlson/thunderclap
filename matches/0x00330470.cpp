class Obj {
  public:
    char pad[0x80];
    void* ptr;
    char gap[0x50];
    int val;
    void Set(int n);
    void Refresh();
};
void Obj::Set(int n) {
    if (n != val) {
        val = n;
        if (n < 4)
            n = 4;
        val = n;
        if (ptr)
            Refresh();
    }
}