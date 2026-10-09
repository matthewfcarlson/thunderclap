class CController { public: void a(); void b(); void run(); };
void CController::run() {
    *(int*)this = 0x405d38;
    a();
    b();
    *(int*)this = 0x3f6098;
}
