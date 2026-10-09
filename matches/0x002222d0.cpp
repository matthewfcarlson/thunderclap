class Member { public: virtual void f0(); virtual void f1(); };
class PartitionDriver {
public:
    virtual ~PartitionDriver();
    char pad[12];
    Member* mChild;
    void Finish();
};
PartitionDriver::~PartitionDriver() {
    mChild->f1();
    Finish();
}
