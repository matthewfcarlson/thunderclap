struct Data_602a0 {
    int x;
};
class Obj_602a0 {
  public:
    char pad[0x58];
    Data_602a0* Get();
};
Data_602a0* Obj_602a0::Get() {
    return (Data_602a0*)((char*)this + 0x58);
}