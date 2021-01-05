//
// Created by Anna on 28.12.2020.
//

#ifndef LAB_1_TRITSET_H
#define LAB_1_TRITSET_H

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "Trit.h"

namespace TernaryLogic {

    static const unsigned int TRIT_BIT_SIZE = 2;
    static const unsigned int BITS_IN_ONE_BYTE_NUMBER = 8;
    static const unsigned int TRITS_IN_ONE_UINT_NUMBER = 16;

    static const std::map<unsigned int, TernaryLogic::Trit> codeTritValueMap{
            {0, Trit::Unknown},
            {1, Trit::True},
            {2, Trit::False}
    };


    class TritSet {
    private:
        std::vector<unsigned int> set_;

        std::size_t initialSize_;
        std::size_t currentSize_;

        std::unordered_map<TernaryLogic::Trit, size_t, std::hash<int>> tritValuesCountsMap_{
                {Trit::False,   0},
                {Trit::True,    0},
                {Trit::Unknown, 0}
        };

        [[nodiscard]] TernaryLogic::Trit getTrit(unsigned int tritPosition) const;

        void setTrit(TernaryLogic::Trit tritValue, unsigned int tritPosition);

        static std::pair<TritSet, TritSet> createOperands(const TritSet &setA, const TritSet &setB) {
            size_t resultSetSize = setA.getSize() > setB.getSize() ? setA.getSize() : setB.getSize();
            TritSet tempMinSet(resultSetSize);

            if (resultSetSize == setA.getSize()) {
                for (int i = 0; i < setB.getSize(); i++) {
                    tempMinSet[i] = setB.getTrit(i);
                }
                return std::make_pair(setA, tempMinSet);
            } else {
                for (int i = 0; i < setA.getSize(); i++) {
                    tempMinSet[i] = setA.getTrit(i);
                }
                return std::make_pair(setA, tempMinSet);
            }
        }

        void resetTritValuesCountsMapData() {
            tritValuesCountsMap_[True] = 0;
            tritValuesCountsMap_[False] = 0;
            tritValuesCountsMap_[Unknown] = initialSize_;
        }

    public:

        class Reference {
        private:
            TritSet &setReference_;
            unsigned int index_;
        public:
            friend class TritSet;

            Reference(TritSet &setReference, unsigned int index) :
                    setReference_(setReference), index_(index) {};

            Reference &operator=(TernaryLogic::Trit tritValue);

            Reference &operator=(const Reference &reference);

            explicit operator TernaryLogic::Trit() {
                return setReference_.getTrit(index_);
            }
        };

        TritSet();

        explicit TritSet(size_t N);

        ~TritSet() = default;

        size_t capacity() const;

        size_t getSize() const;

        void shrink();

        [[nodiscard]] size_t cardinality(TernaryLogic::Trit tritValue) const;

        [[nodiscard]] std::unordered_map<TernaryLogic::Trit, size_t, std::hash<int>> cardinality() const;

        void trim(size_t lastTritIndex);

        size_t length() const;

        Reference operator[](unsigned int tritIndex);

        friend TritSet operator~(const TritSet &setA) {
            TritSet resultSet(setA.getSize());

            for (int curTritIndex = 0; curTritIndex < resultSet.getSize(); curTritIndex++) {
                resultSet[curTritIndex] = ~setA.getTrit(curTritIndex);
            }

            return resultSet;
        };

        friend TritSet operator|(const TritSet &setA, const TritSet &setB) {
            size_t resultSetSize = setA.getSize() > setB.getSize() ? setA.getSize() : setB.getSize();
            TritSet resultSet(resultSetSize);
            auto operandsPair = createOperands(setA, setB);

            for (int curTritIndex = 0; curTritIndex < resultSet.getSize(); curTritIndex++) {
                resultSet[curTritIndex] =
                        operandsPair.first.getTrit(curTritIndex) | operandsPair.second.getTrit(curTritIndex);
            }

            return resultSet;
        };

        friend TritSet operator&(const TritSet &setA, const TritSet &setB) {
            size_t resultSetSize = setA.getSize() > setB.getSize() ? setA.getSize() : setB.getSize();
            TritSet resultSet(resultSetSize);
            auto operandsPair = createOperands(setA, setB);

            for (int curTritIndex = 0; curTritIndex < resultSet.getSize(); curTritIndex++) {
                resultSet[curTritIndex] =
                        operandsPair.first.getTrit(curTritIndex) & operandsPair.second.getTrit(curTritIndex);
            }

            return resultSet;
        };

        friend std::ostream &operator<<(std::ostream &outputStream, const TritSet &set) {
            outputStream << "Trit_index : Trit_value" << std::endl;
            for (int curTritIndex = 0; curTritIndex < set.getSize(); curTritIndex++) {
                outputStream << "         " << curTritIndex << " : " << set.getTrit(curTritIndex) << std::endl;
            }

            return outputStream;
        };
    };


}

#endif //LAB_1_TRITSET_H
