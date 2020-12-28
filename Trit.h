//
// Created by Anna on 27.12.2020.
//

#ifndef LAB_1_TRIT_H
#define LAB_1_TRIT_H

namespace TernaryLogic {

    enum Trit {
        False,
        Unknown,
        True
    };

    Trit operator~(Trit tritA);

    Trit operator|(Trit tritA, Trit tritB);

    Trit operator&(Trit tritA, Trit tritB);

}

#endif //LAB_1_TRIT_H
