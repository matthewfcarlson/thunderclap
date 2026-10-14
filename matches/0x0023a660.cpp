class Slot_23a660 {
  public:
    void Invoke(void*);
};
class Owner_23a660 {
  public:
    char pad0[0x12c];
    int count;
    int Run(void* arg);
};
int Owner_23a660::Run(void* arg) {
    int i = count;
    int r = -1;
    if (i < 0x200) {
        Slot_23a660* s = (Slot_23a660*)((char*)this + (i * 3) * 8 + 0x130);
        s->Invoke(arg);
        *(int*)((char*)this + (i * 3 + 0x27) * 8) = 0;
        count++;
        r = i;
    }
    return r;
}