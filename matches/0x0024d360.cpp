class EntityLoader {
  public:
    void* vtable;
    int a;
    void* b;
    EntityLoader(void*);
};
EntityLoader::EntityLoader(void* p) {
    a = 0;
    vtable = (void*)0x429394;
    b = p;
}