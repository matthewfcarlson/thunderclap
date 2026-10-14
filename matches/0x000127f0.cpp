class Obj_127f0 {
  public:
    char pad[0xa0];
    void* Get();
};
void* Obj_127f0::Get() {
    return (void*)((char*)this + 0xa0);
}