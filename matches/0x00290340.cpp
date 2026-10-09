class Obj { public: char pad[8]; int field; void Init(); void Configure(void*); void Finish(int); Obj* Run(void*); };
Obj* Obj::Run(void* arg) {
    Init();
    field = 0;
    Configure(arg);
    Finish(*(int*)((char*)arg + 8));
    return this;
}