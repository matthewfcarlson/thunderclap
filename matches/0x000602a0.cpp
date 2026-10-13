struct Data {
    int x;
};
class Obj {
  public:
    char pad[0x58];
    Data* Get();
};
Data* Obj::Get() {
    return (Data*)((char*)this + 0x58);
}