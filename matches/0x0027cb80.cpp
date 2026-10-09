class C {
  public:
    char pad[0x90];
    int count;
    void* items[2];
    bool add(void* p);
};
bool C::add(void* p) {
    if (p && count < 1) {
        items[count] = p;
        ++count;
        return true;
    }
    return false;
}