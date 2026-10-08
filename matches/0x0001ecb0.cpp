extern char vftableD[];
extern char vftableA[];

class RefObj {
public:
  virtual void v0();
  virtual void Release();
};

struct Tidier {
  void Tidy();
};

class CSmartPropUpdateAttachmentAction {
public:
  char pad[0x1c];
  RefObj* volatile mA;   // 0x1c
  char pad2[4];          // 0x20
  RefObj* volatile mB;   // 0x24
  void Shutdown();
};

void CSmartPropUpdateAttachmentAction::Shutdown() {
  *(void* volatile*)this = (void*)vftableD;
  RefObj* b = mB;
  if (b) { b->Release(); mB = 0; }
  *(void* volatile*)this = (void*)vftableA;
  RefObj* a = mA;
  if (a) { a->Release(); mA = 0; }
  ((Tidier*)this)->Tidy();
}
