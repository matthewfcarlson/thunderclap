extern int vft_container;
extern int vft_event;
void Init(void*);
class SeqEventContainer_2607a0 {
  public:
    int* vptr;
    char pad[8];
    void Initialize();
};
void SeqEventContainer_2607a0::Initialize() {
    vptr = &vft_container;
    Init(&pad[8]);
    vptr = &vft_event;
}