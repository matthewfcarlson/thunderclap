class Queue_35930 {
  public:
    void Send(void*);
};
struct Global_35930 {
    char pad[0x30];
    Queue_35930* q;
};
extern Global_35930* g_35930;
class Temp_35930 {
  public:
    void Build(int, int, int);
};
class Obj_35930 {
  public:
    char pad[0x10];
    int* ptr;
    char pad2[0x120];
    int value;
    void Set(int x);
};
void Obj_35930::Set(int x) {
    char local[28];
    int old = value;
    if (old != x) {
        Queue_35930* q = g_35930->q;
        if (q) {
            ((Temp_35930*)local)->Build(old, x, *ptr);
            q->Send(local);
        }
        value = x;
    }
}