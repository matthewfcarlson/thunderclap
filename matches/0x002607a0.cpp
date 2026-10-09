extern int vft_container;
extern int vft_event;
void Init(void*);
class SeqEvent {
  public:
    int* vptr;
    char pad[8];
    void Initialize();
};
void SeqEvent::Initialize() {
    vptr = &vft_container;
    Init(&pad[8]);
    vptr = &vft_event;
}