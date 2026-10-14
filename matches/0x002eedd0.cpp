class Inner_2eedd0 {
  public:
    void First();
    void Second(void*, void*, int);
};
class Obj_2eedd0 {
  public:
    char pad[0xb0];
    void Run(void*);
};
void Obj_2eedd0::Run(void* arg) {
    ((Inner_2eedd0*)this)->First();
    ((Inner_2eedd0*)((char*)this + 0xb0))->Second((char*)this + 0x2c, arg, 0);
}