class Obj {
    char pad[0x14];
    void* value;

  public:
    char Set(void* p);
};
char Obj::Set(void* p) {
    value = p;
    return 1;
}