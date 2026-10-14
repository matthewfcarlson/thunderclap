class Obj_92410 {
  public:
    void Setup(const char*, int, int);
    void Finish(int);
};
class Host_92410 {
  public:
    Obj_92410* GetObject();
    void AddThing(Obj_92410*, const char*, int);
    void Target();
};
extern const char* gItems_92410[];
void Host_92410::Target() {
    Obj_92410* obj = GetObject();
    if (obj) {
        obj->Setup("constants", 1, 1);
        obj->Setup("unlockables", 0, 1);
        int i = 0;
        do {
            AddThing(obj, gItems_92410[i], i);
            ++i;
        } while (i < 0x2fe);
        obj->Finish(2);
    }
}