class C_269f0 {
  public:
    char pad[0x228];
    char slots[0x100];
    int count;
    int find(int, int);
    bool add(int, int);
};
bool C_269f0::add(int x, int y) {
    int i = count;
    if (i >= 0x20)
        return false;
    if (find(x, y) != -1)
        return false;
    *(int*)(slots + i * 8) = x;
    *(int*)(slots + i * 8 + 4) = y;
    count = count + 1;
    return true;
}