struct DataBlock {
    int m00, m04, m08, m0c, m10, m14, m18, m1c;
    int m20, m24, m28, m2c, m30, m34, m38, m3c;
    int m40, m44, m48, m4c, m50, m54, m58, m5c;

    DataBlock* CopyFrom(const DataBlock* src);
};

DataBlock* DataBlock::CopyFrom(const DataBlock* src) {
    m00 = src->m00;
    m04 = src->m04;
    m08 = src->m08;
    m0c = src->m0c;
    m10 = src->m10;
    m14 = src->m14;
    m18 = src->m18;
    m1c = src->m1c;
    m20 = src->m20;
    m24 = src->m24;
    m28 = src->m28;
    m2c = src->m2c;
    m30 = src->m30;
    m34 = src->m34;
    m38 = src->m38;
    m3c = src->m3c;
    m40 = src->m40;
    m44 = src->m44;
    m48 = src->m48;
    m4c = src->m4c;
    m50 = src->m50;
    m54 = src->m54;
    m58 = src->m58;
    m5c = src->m5c;
    return this;
}