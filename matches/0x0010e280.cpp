struct Data {
    char pad[0x18];
    int value;
    char pad2[4];
    unsigned char flag;
};
struct Result {
    void send(int*, int, unsigned char);
};
struct Getter {
    Result* get();
};
struct Semaphore {
    Getter* get();
};
namespace hulkfight {
namespace ai {
class SemaphoreWaitAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int, int);
    virtual void v4();
    virtual void v5();
    char pad[0x1c - 4];
    Data* data;
    Semaphore* sem;
    int state;
};
} // namespace ai
} // namespace hulkfight
char hulkfight::ai::SemaphoreWaitAction::vfunc_3(int, int) {
    if (!sem)
        return 0;
    Result* r = sem->get()->get();
    state = 0;
    r->send(&data->value, 1, data->flag);
    return 1;
}