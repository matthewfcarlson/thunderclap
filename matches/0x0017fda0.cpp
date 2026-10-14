class Obj_17fda0 {
  public:
    char pad[0x48];
    int* m;
    int* Get();
};
int* Obj_17fda0::Get() {
    return (int*)((char*)this + 0x48);
}
