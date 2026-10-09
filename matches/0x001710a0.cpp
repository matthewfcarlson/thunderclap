struct HelperA { void* run(); };
struct HelperB { void* run(); };
struct HelperC { void run(int); };
class MotionStateAction { char pad[0x1c]; HelperA* mAt1c; HelperB* mAt20; public: bool vfunc_5(int, int); };
bool MotionStateAction::vfunc_5(int param, int unused) {
    if (param == 0) {
        void* x = mAt20->run();
        x = ((HelperB*)x)->run();
        ((HelperC*)x)->run(*(int*)((char*)mAt1c + 0x14));
    }
    return true;
}