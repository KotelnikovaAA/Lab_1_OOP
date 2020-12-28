//
// Created by Anna on 28.12.2020.
//

#include "TritSet.h"

TernaryLogic::TritSet::TritSet(std::size_t N) {
    set_.resize(N * 2 / 8 / sizeof(unsigned int), 0);
}

size_t TernaryLogic::TritSet::capacity() {
    return (set_.capacity() * sizeof(unsigned int) * 4);
}

size_t TernaryLogic::TritSet::getSize() const {
    return 0;
}

TernaryLogic::Trit TernaryLogic::TritSet::getTrit(const unsigned int tritPosition) const {
    std::size_t elementIndex = tritPosition * TRIT_BIT_SIZE / (sizeof(unsigned int) * BITS_IN_ONE_BYTE_NUMBER);
    unsigned int detectedElement = set_[elementIndex];

    std::size_t tritElementIndex = tritPosition * TRIT_BIT_SIZE % (sizeof(unsigned int) * BITS_IN_ONE_BYTE_NUMBER);
    unsigned int offset = (15 - tritElementIndex) * 2;

    unsigned int tritValue = (detectedElement >> offset) & (unsigned int)3;

    return codeTritValueMap.at(tritValue);
}
               01
11 10 11 00 10 10 11 01
0  1  2  3  4  5  6  7
11 11 11 11 11 00 11 11 &
11 10 11 00 10 10 11 01
11 10 11 00 10 00 11 01 &
11 11 11 11 11 01 11 11

11 10 11 00 10 01 11 01

void TernaryLogic::TritSet::setTrit(const TernaryLogic::Trit tritValue, const unsigned int tritPosition) {
    std::size_t elementIndex = tritPosition * TRIT_BIT_SIZE / (sizeof(unsigned int) * BITS_IN_ONE_BYTE_NUMBER);
    unsigned int detectedElement = set_[elementIndex];

    std::size_t tritElementIndex = tritPosition * TRIT_BIT_SIZE % (sizeof(unsigned int) * BITS_IN_ONE_BYTE_NUMBER);
    unsigned int offset = (15 - tritElementIndex) * 2;

    unsigned int bitMask = ~((unsigned int) 3 << offset);
    set_[elementIndex] &= bitMask;
    set_[elementIndex] |= ((unsigned int) tritValue << offset);
}
