//
// Created by Anna on 27.12.2020.
//

#include "Trit.h"

TernaryLogic::Trit operator~(TernaryLogic::Trit tritA) {
    switch (tritA) {
        case TernaryLogic::True:
            return TernaryLogic::False;
        case TernaryLogic::False:
            return TernaryLogic::True;
        default:
            return TernaryLogic::Unknown;
    }
}

TernaryLogic::Trit operator|(TernaryLogic::Trit tritA, TernaryLogic::Trit tritB) {
    if (tritA == TernaryLogic::True || tritB == TernaryLogic::True) {
        return TernaryLogic::True;
    } else if (tritA == TernaryLogic::Unknown || tritB == TernaryLogic::Unknown) {
        return TernaryLogic::Unknown;
    } else {
        return TernaryLogic::False;
    }
}

TernaryLogic::Trit operator&(TernaryLogic::Trit tritA, TernaryLogic::Trit tritB) {
    if (tritA == TernaryLogic::False || tritB == TernaryLogic::False) {
        return TernaryLogic::False;
    } else if (tritA == TernaryLogic::Unknown || tritB == TernaryLogic::Unknown) {
        return TernaryLogic::Unknown;
    } else {
        return TernaryLogic::True;
    }
}

