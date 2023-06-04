#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#ifndef MAGICAL
#define MAGICAL
#include <string>

namespace ariel {}

    class MagicalContainer {
    private:
    std::vector<int> items;
    public:
        void  addElement(int num){}
        int size(){return 0;}
        void removeElement(int num){}

    class iterator{
int kind;
    public:
        iterator(const MagicalContainer container){}
        iterator(const iterator* iter){}

        bool operator!=(const iterator other) const{return false;}
        bool operator>(const iterator other) const{return true;}
        bool operator<(const iterator other) const{return true;}

        void operator=(const iterator other) const{}

        bool operator==(const iterator other) const{return true;}

//        int operator*() const{return 0;}
//
//        iterator operator++(){}
//
//        iterator begin() const{}
//
//        iterator end() const{}

        ~iterator(){}

        };





        class AscendingIterator: public iterator{
        private:
            std::vector<int> M_container;
            size_t currentIndex;
        public:
            AscendingIterator(MagicalContainer container_): iterator(container_){}
            AscendingIterator( AscendingIterator* iter): iterator(iter){}
            AscendingIterator( ): iterator(nullptr){}

//            bool operator!=(const AscendingIterator other) const{return false;}
//            bool operator>(const AscendingIterator&  other) const{return true;}
//            bool operator<(const AscendingIterator& other) const{return true;}
//
//            void operator=(const AscendingIterator& other) const{}
//
//            bool operator==(const AscendingIterator& other) const{return true;}

            int operator*() const{return 0;}

            AscendingIterator operator++(){return AscendingIterator();}

            AscendingIterator begin() const{return AscendingIterator();}

            AscendingIterator end() {return AscendingIterator();}
            ~AscendingIterator(){}
        };

        class SideCrossIterator: public iterator{
        private:
            std::vector<int> M_container;
            size_t currentIndex;
        public:
            SideCrossIterator(MagicalContainer container_): iterator(container_){}
            SideCrossIterator( SideCrossIterator* iter): iterator(iter){}
            SideCrossIterator( ): iterator(nullptr){}

//            bool operator!=(const SideCrossIterator& other) const{return false;}
//            bool operator>(const  SideCrossIterator&  other) const{return true;}
//            bool operator<(const  SideCrossIterator& other) const{return true;}
//
//            void operator=(const  SideCrossIterator& other) const{}
//
//            bool operator==(const SideCrossIterator&  other) const{return true;}

            int operator*() const{return 0;}

            SideCrossIterator operator++(){return SideCrossIterator();}

            SideCrossIterator begin() const{return SideCrossIterator();}

            SideCrossIterator end() {return SideCrossIterator();}
            ~SideCrossIterator(){}
        };


        class PrimeIterator: public iterator{
        private:
            std::vector<int> M_container;
            size_t currentIndex;
        public:
            PrimeIterator(MagicalContainer container_): iterator(container_){}
            PrimeIterator( PrimeIterator* iter): iterator(iter){}
            PrimeIterator( ): iterator(nullptr){}

//            bool operator!=(const PrimeIterator& other) const{return false;}
//            bool operator>(const  PrimeIterator&  other) const{return true;}
//            bool operator<(const  PrimeIterator& other) const{return true;}
//
//            void operator=(const  PrimeIterator& other) const{}
//
//            bool operator==(const PrimeIterator&  other) const{return true;}

            int operator*() const{return 0;}

            PrimeIterator operator++(){return PrimeIterator();}

            PrimeIterator begin() const{return PrimeIterator();}

            PrimeIterator end() {return PrimeIterator();}
            ~PrimeIterator(){}
        };
};

#endif
