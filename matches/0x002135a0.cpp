struct Obj {
    char pad[8];
    int offset;
};
typedef unsigned int size_t;
extern "C" size_t strlen(const char*);
extern "C" int __fastcall find(int, Obj*);
extern "C" int make(Obj*, const char*, int);
extern "C" void emit(Obj*, int, int*, int);
void target(Obj* obj, int type, const char* str) {
    int tmp[2];
    int id = find(type, obj);
    tmp[1] = make(obj, str, strlen(str));
    tmp[0] = 4;
    emit(obj, id, tmp, obj->offset);
    obj->offset += 8;
}