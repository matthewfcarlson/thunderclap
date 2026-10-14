class X_11be90 {
    char pad[0x24];

  public:
    char Set(int a);
};
char X_11be90::Set(int a) {
    *(int*)((char*)this + 0x24) = a;
    return 1;
}
