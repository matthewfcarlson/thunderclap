extern "C" char DAT_00429394[];
class EntityLoader {
  public:
    void* vtable;
    int a;
    void* b;
    EntityLoader(void*);
};
EntityLoader::EntityLoader(void* p) {
    a = 0;
    vtable = (void*)((int)DAT_00429394);
    b = p;
}