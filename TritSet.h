//
// Created by Anna on 28.12.2020.
//

#ifndef LAB_1_TRITSET_H
#define LAB_1_TRITSET_H

#include <iostream>
#include <vector>
#include <map>
#include "Trit.h"

namespace TernaryLogic {

    static const unsigned int TRIT_BIT_SIZE = 2;
    static const unsigned int BITS_IN_ONE_BYTE_NUMBER = 8;

    const std::map<unsigned int, TernaryLogic::Trit> codeTritValueMap{
            {0, Trit::False},
            {1, Trit::True},
            {2, Trit::Unknown}
    };

    class TritSet {
    private:
        std::vector<unsigned int> set_;

        std::size_t initialSize_;
        std::size_t currentSize_;

        std::size_t tritTrueCount_;
        std::size_t tritUnknownCount_;
        std::size_t tritFalseCount_;

        [[nodiscard]] TernaryLogic::Trit getTrit(unsigned int tritPosition) const;

        void setTrit(TernaryLogic::Trit tritValue, unsigned int tritPosition);

    public:

        class Reference {
        private:
            TritSet &setReference_;
            unsigned int index_;
        public:
            friend class TritSet;

            Reference &operator=(TernaryLogic::Trit tritValue);
        };

        TritSet() = default;

        explicit TritSet(size_t N);

        ~TritSet() = default;

        size_t capacity() const; // Возвращает размер дискового пространства, выделенного в данный момент для вектора,
        // выраженный в элементах (тритах).

        size_t getSize() const;


        void shrink();

        Reference operator[](unsigned int tritIndex);

        TritSet operator~(TritSet setA, TritSet setB);

        TritSet operator|(TritSet setA, TritSet setB);

        TritSet operator&(TritSet setA, TritSet setB);

        size_t cardinality(TernaryLogic::Trit value);

        std::unordered_map<TernaryLogic::Trit, int, std::hash<int>> cardinality();

        void trim(size_t lastIndex);

        size_t

        length();
    };

}

#endif //LAB_1_TRITSET_H
