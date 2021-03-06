//
// Created by Anna on 27.12.2020.
//

#ifndef LAB_1_TRIT_H
#define LAB_1_TRIT_H

namespace TernaryLogic {

    enum Trit {
        Unknown,     // 0 = 00
        True,        // 1 = 01
        False        // 2 = 10
    };

    TernaryLogic::Trit operator~(TernaryLogic::Trit tritA);

    TernaryLogic::Trit operator|(TernaryLogic::Trit tritA, TernaryLogic::Trit tritB);

    TernaryLogic::Trit operator&(TernaryLogic::Trit tritA, TernaryLogic::Trit tritB);

}

#endif //LAB_1_TRIT_H
