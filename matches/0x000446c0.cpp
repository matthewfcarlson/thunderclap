class Obj {
  public:
    int Get(int index);
};
int Obj::Get(int index) {
    if (index >= 0 && index < 8)
        return *(int*)((char*)this + (index * 5 + 0x37) * 8);
    return 0;
}