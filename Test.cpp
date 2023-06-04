#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include <sys/time.h>
#include "sources/MagicalContainer.hpp" //no need for other includes

using namespace ariel;


TEST_CASE("order") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(5);
    container.addElement(3);
    container.addElement(1);

    CHECK(container.size()==5);

    MagicalContainer::AscendingIterator ascIter(container);
    int i=1;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';
        CHECK(i==*it);
        i=+2;
    }


    int arr[5]={1,9,3,7,5};
    MagicalContainer::SideCrossIterator crossIter(container);
    int j=0;
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';
        CHECK(arr[j]==*it);
        j++;
    }



    int arr2[3]={3,5,7};
    j=0;
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17
        CHECK(arr2[j]==*it);
        j++;
    }


    container.removeElement(9);
    CHECK_NE(container.size(),5);
    CHECK_EQ(container.size(),4);
    container.removeElement(7);
    CHECK_EQ(container.size(),3);
}


TEST_CASE(""){
    MagicalContainer container;
    //empty
    CHECK_THROWS(container.removeElement(9));
    CHECK_THROWS(container.removeElement(7));
    container.addElement(7);
    container.removeElement(7);
    CHECK_THROWS(container.removeElement(7));
    CHECK_THROWS(container.removeElement(9));

    container.addElement(7);
    CHECK_EQ(container.size(),1);
    container.addElement(7);
    container.addElement(7);
    container.addElement(7);
    container.addElement(7);
    CHECK_EQ(container.size(),1);
    container.removeElement(7);
    CHECK_EQ(container.size(),0);


    container.removeElement(9);
    CHECK_EQ(container.size(),4);
    container.removeElement(10);
    CHECK_EQ(container.size(),4);
    container.removeElement(3);
    CHECK_EQ(container.size(),4);


    CHECK_NOTHROW(container.addElement(7));
    CHECK_NOTHROW(container.addElement(3));

}

TEST_CASE("throw") {

    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(5);
    container.addElement(3);
    container.addElement(1);


    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer:: PrimeIterator primeIter(container);

    CHECK(primeIter.begin()<primeIter.end());
    CHECK(crossIter.begin()<crossIter.end());
    CHECK(ascIter.begin()<ascIter.end());

    CHECK_FALSE(primeIter.begin()>primeIter.end());
    CHECK_FALSE(crossIter.begin()>crossIter.end());
    CHECK_FALSE(ascIter.begin()>ascIter.end());

    CHECK_FALSE(primeIter.begin()!=primeIter.begin());
    CHECK_FALSE(crossIter.end()!=crossIter.end());
    CHECK_FALSE(ascIter.end()!=ascIter.end());

    CHECK(primeIter.begin()==primeIter.begin());
    CHECK(crossIter.end()==crossIter.end());
    CHECK(ascIter.end()==ascIter.end());

}

TEST_CASE(""){

    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(5);
    container.addElement(3);
    container.addElement(1);
    SUBCASE(""){
        MagicalContainer::AscendingIterator Iter1(container);
        MagicalContainer::AscendingIterator Iter2(container);
        CHECK(Iter1.begin()<Iter2.end());
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1==Iter2);
    }
    SUBCASE(""){
        MagicalContainer::SideCrossIterator Iter1(container);
        MagicalContainer::SideCrossIterator Iter2(container);
        CHECK(Iter1.begin()<Iter2.end());
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1==Iter2);}
    SUBCASE(""){
        MagicalContainer::PrimeIterator Iter1(container);
        MagicalContainer::PrimeIterator Iter2(container);
        CHECK(Iter1.begin()<Iter2.end());
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1<Iter2);
        ++Iter1;
        CHECK(Iter1==Iter2);}
}


;