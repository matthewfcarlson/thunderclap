extern "C" void* __cdecl Alloc(unsigned int);
class Obj_2ef0b0 {
  public:
    void Init();
};
class Obj70_2ef0b0 {
  public:
    void Init();
};
class ObjB0 {
  public:
    void Init();
};
class Obj1B0 {
  public:
    void Init();
};
extern void* gObject_2ef0b0;
void FUN_002ef0b0() {
    if (gObject_2ef0b0 == 0) {
        void* p = Alloc(0x1c4);
        if (p != 0) {
            ((Obj_2ef0b0*)p)->Init();
            ((Obj70_2ef0b0*)((char*)p + 0x70))->Init();
            ((ObjB0*)((char*)p + 0xb0))->Init();
            ((Obj1B0*)((char*)p + 0x1b0))->Init();
            *((char*)p + 0x6c) = 0;
            gObject_2ef0b0 = p;
        } else
            gObject_2ef0b0 = 0;
    }
}