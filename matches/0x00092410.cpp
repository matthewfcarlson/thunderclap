class Obj { public: void Setup(const char*, int, int); void Finish(int); };
class Host { public: Obj* GetObject(); void AddThing(Obj*, const char*, int); void Target(); };
extern const char* gItems[];
void Host::Target() {
    Obj* obj = GetObject();
    if (obj) {
        obj->Setup("constants", 1, 1);
        obj->Setup("unlockables", 0, 1);
        int i = 0;
        do { AddThing(obj, gItems[i], i); ++i; } while (i < 0x2fe);
        obj->Finish(2);
    }
}