namespace pure3d {
struct Skeleton {
    struct Partition {
        virtual void Destroy();
        char reserved[12];
        int value;
        char tail[4];
    };
};
} // namespace pure3d
struct Handler {
    void FUN_0027bd70(int, pure3d::Skeleton::Partition*);
    void FUN_0027be80(int);
};
void Handler::FUN_0027be80(int arg) {
    pure3d::Skeleton::Partition partition;
    partition.value = 0;
    FUN_0027bd70(arg, &partition);
}