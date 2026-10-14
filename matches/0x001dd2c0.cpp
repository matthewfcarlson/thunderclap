class Node {
  public:
    int a[4];
    int next;
};
class Search_1dd2c0 {
  public:
    Node* First();
};
class Worker_1dd2c0 {
  public:
    void Run(int);
};
class Obj_1dd2c0 {
  public:
    char pad[0x608];
    void Target(Search_1dd2c0*, int);
};
void Obj_1dd2c0::Target(Search_1dd2c0* search, int value) {
    Node* p = search->First();
    while (p) {
        char* rec = (char*)this + (p->a[0] * 0x28) + 0x608;
        short n = *(short*)(rec + 0x22);
        if (*(unsigned char*)((char*)this + (n + 0x104e) * 0x14) & 1) {
            Worker_1dd2c0* w = *(Worker_1dd2c0**)(rec + 0x18);
            w->Run(value);
        }
        p = (Node*)p->next;
    }
}