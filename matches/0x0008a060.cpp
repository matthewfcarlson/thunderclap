extern float gZero_8a060;
class Obj_8a060 {
    char pad[0x160];

  public:
    int Find(int);
    char* Get(int);
};
char* Obj_8a060::Get(int arg) {
    int i = Find(arg);
    if (i == -1)
        return (char*)&gZero_8a060;
    return (char*)this + 0x160 + i * 0x18;
}