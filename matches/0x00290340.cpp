class Obj_290340 {
  public:
    char pad[8];
    int field;
    void Init();
    void Configure(void*);
    void Finish(int);
    Obj_290340* Run(void*);
};
Obj_290340* Obj_290340::Run(void* arg) {
    Init();
    field = 0;
    Configure(arg);
    Finish(*(int*)((char*)arg + 8));
    return this;
}