struct Thing {
    void Helper(int);
    Thing* Run(int);
};
Thing* Thing::Run(int x) {
    Helper(x);
    return this;
}