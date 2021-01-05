#include "TritSet.h"
#include "Trit.h"
#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
//    TernaryLogic::TritSet setA(40);
//    TernaryLogic::TritSet setB;
//    TernaryLogic::TritSet setC(3);
//
//    std::cout << setA.getSize() << std::endl;
//    std::cout << setA.length() << std::endl;
//    std::cout << setB.getSize() << std::endl;
//    std::cout << setB.length() << std::endl;
//
//
//
//    std::cout << setC.getSize() << std::endl;
//    std::cout << "initial capacity A: " << setA.capacity() << std::endl;
//    std::cout << "B:" << setB.capacity() << std::endl;
//    setB[3] = TernaryLogic::Trit::True;
//    std::cout << "B:" << setB.capacity() << std::endl;
//    setB[2] = TernaryLogic::Trit::Unknown;
//    std::cout << "B:" << setB.capacity() << std::endl;
//    setB[6] = TernaryLogic::Trit::False;
//    std::cout << "B:" << setB.capacity() << std::endl;
//    setB[7] = TernaryLogic::Trit::Unknown;
//    std::cout << setB.getSize() << std::endl;
//    std::cout << "B:" << setB.capacity() << std::endl;
//
//    setA[45] = TernaryLogic::Trit::True;
//    setA[26] = TernaryLogic::Trit::False;
//    std::cout << "changed size A: " << setA.getSize() << std::endl;
//    std::cout << "changed capacity A: " << setA.capacity() << std::endl;
//
//    TernaryLogic::TritSet setD(30);
//    setB = setD;
//    std::cout << "size B: " << setB.getSize() << std::endl;
//    std::cout << "capacity B: " << setB.capacity() << std::endl;
//    setB.shrink();
//    std::cout << "capacity B after 'shrink()': " << setB.capacity() << std::endl;
//
//    setA = setD;
//    std::cout << "size A: " << setA.getSize() << std::endl;
//    std::cout << "capacity A: " << setA.capacity() << std::endl;
//    setA.shrink();
//    std::cout << "capacity A after 'shrink()': " << setA.capacity() << std::endl;
//    std::cout << '\n';
//
//
//    std::cout << "Trim data: " << std::endl;
//    std::cout << "size A before 'trim()': " << setA.getSize() << std::endl;
//    std::cout << "capacity A before 'trim()': " << setA.capacity() << std::endl;
//    std::cout << '\n';
//    setA[0] = TernaryLogic::Trit::False;
//    setA[1] = TernaryLogic::Trit::False;
//    setA[2] = TernaryLogic::Trit::True;
//    setA[5] = TernaryLogic::Trit::True;
//    setA[7] = TernaryLogic::Trit::True;
//    setA[8] = TernaryLogic::Trit::False;
//    std::cout << setA.cardinality(TernaryLogic::True) << std::endl;
//    std::cout << setA.cardinality(TernaryLogic::False) << std::endl;
//    std::cout << setA.cardinality(TernaryLogic::Unknown) << std::endl;
//    std::cout << '\n';
//    auto tritValuesCountsMap = setA.cardinality();
//    for (auto item : tritValuesCountsMap) {
//        std::cout << item.first << " : " << item.second << " counts" << std::endl;
//    }
//    std::cout << '\n';
//    setA.trim(8);
//    std::cout << "size A after 'trim()': " << setA.getSize() << std::endl;
//    std::cout << "capacity A: " << setA.capacity() << std::endl;
//    setA.shrink();
//    std::cout << "capacity A after 'shrink()': " << setA.capacity() << '\n' <<std::endl;
//
//    setC[5] = TernaryLogic::Trit::True;
//    setC[7] = TernaryLogic::Trit::True;
//    setC[8] = TernaryLogic::Trit::False;
//    std::cout << "setA:\n" << setA << std::endl;
//    std::cout << '\n';
//    std::cout << "setB:\n" << setB << std::endl;
//    std::cout << '\n';
//    std::cout << "Lets look on setC:\n" << setC << std::endl;
//    std::cout << '\n';
//    setA = setA & setC;
//    std::cout << "New setA:\n" << setA << std::endl;
//    std::cout << '\n';
//    setA = ~setA;
//    std::cout << "The most new setA that can be in this world:\n" << setA << std::endl;
//    std::cout << '\n';
//
//
//
//    return 0;
//
//
//
//


    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();



}
