extern void* frameVtable;
class Base_284a90 {
  public:
    void Init(void*);
};
class FrameController {
  public:
    char pad[0x10];
    FrameController(void*);
};
FrameController::FrameController(void* p) {
    ((Base_284a90*)this)->Init(p);
    *(void**)this = &frameVtable;
    ((char*)this)[0x10] = ((char*)p)[0x10];
}
