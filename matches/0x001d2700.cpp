void ReleaseThing(void*);
class Obj_1d2700 {
    char pad[8];
    void* mPtr;

  public:
    void Clear();
};
void Obj_1d2700::Clear() {
    if (mPtr) {
        ReleaseThing(mPtr);
        mPtr = 0;
    }
}