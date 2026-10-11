extern "C" char DAT_003f6098[];
extern "C" char DAT_00405d38[];
class CController {
  public:
    void a();
    void b();
    void run();
};
void CController::run() {
    *(int*)this = ((int)DAT_00405d38);
    a();
    b();
    *(int*)this = ((int)DAT_003f6098);
}
