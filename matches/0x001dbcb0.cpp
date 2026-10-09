struct Element {
    void Init();
};
class CSPManager {
  public:
    void* vftable;
    void Construct();
};
void CSPManager::Construct() {
    char* p;
    int i;
    vftable = (void*)0x4231ac;
    p = (char*)this + 0x1eee0;
    for (i = 0x10; i != 0; --i) {
        p -= 0x18;
        ((Element*)p)->Init();
    }
    p = (char*)this + 0x1ec40;
    for (i = 0x80; i != 0; --i) {
        p -= 8;
        ((Element*)p)->Init();
    }
    p = (char*)this + 0x14608;
    for (i = 0x800; i != 0; --i) {
        p -= 0x28;
        ((Element*)(p + 8))->Init();
        ((Element*)p)->Init();
    }
    vftable = (void*)0x3feefc;
}