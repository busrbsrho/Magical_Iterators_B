#pragma once

#include <vector>
#include <set>
#include "LIterator.hpp"

using namespace std;

namespace ariel {
    class MagicalContainer{
        private:
      
            set<int> container; // set will help preserving the ascenidg order 
            vector<const int*> AScending_Elements;
            vector<const int*> Prime_Elements;
            vector<const int*> SideCross_Elements;

            bool isPrime(int element);

        public:


            MagicalContainer();
            void addElement(int element);
            void removeElement(int element);
            int size() const {return container.size();}
            
        


        

        class AscendingIterator : public LIterator {

            private:
                MagicalContainer* _container;
                size_t _index;
            public:
                AscendingIterator(): _container(nullptr), _index(0){} //inline implement
                
				AscendingIterator(MagicalContainer& container): AscendingIterator(&container, 0){} //inline implement
                
				AscendingIterator(const AscendingIterator &ascen_iter_other);
                
				AscendingIterator (MagicalContainer *container, size_t index): _container(container), _index(index){}//inline implement
                
				~AscendingIterator() override = default;

                AscendingIterator &operator=(const AscendingIterator &ascen_iter_other);
				
				bool operator==(const AscendingIterator &other) const;
                bool operator==(const LIterator &other) const override;
                
				bool operator!=(const AscendingIterator &other) const;
				bool operator!=(const LIterator &other) const override;
                
				
				bool operator<(const LIterator &other) const override;
				bool operator<(const AscendingIterator &other) const;
                
				
				bool operator>(const LIterator &other) const override;
                bool operator>(const AscendingIterator &other) const;
               
			    int operator*() const;


                AscendingIterator& operator++();

                AscendingIterator begin() {//inline implementation
					return AscendingIterator(_container, 0);
				}
                AscendingIterator end() const { //inline implementation
					return AscendingIterator(_container, _container->AScending_Elements.size());
				}
        };


        class PrimeIterator : public LIterator {
            private:
                MagicalContainer* _container;
                size_t _index;
            public:
                PrimeIterator();

                PrimeIterator(MagicalContainer &container): _container(&container), _index(0) {}

                PrimeIterator(const PrimeIterator& prime_iter);
                
				PrimeIterator(MagicalContainer *container, size_t index): _container(container), _index(index){} //inline implement
                
				~PrimeIterator() override = default;

                PrimeIterator &operator=(const PrimeIterator &prime_iter_other);
                
				bool operator==(const PrimeIterator &other) const;
				bool operator==(const LIterator &other) const override;
                
				bool operator!=(const LIterator &other) const override;
				bool operator!=(const PrimeIterator &other) const;

                bool operator<(const LIterator &other) const override;
                bool operator<(const PrimeIterator &other) const;

				bool operator>(const LIterator &other) const override;
				bool operator>(const PrimeIterator &other) const; 
                
				
                
				
                
				
                
				
                PrimeIterator& operator++();
                int operator*() const;

                PrimeIterator begin(){
                    return PrimeIterator(_container, 0);
                }
                PrimeIterator end() const{
                    return PrimeIterator(_container, _container->Prime_Elements.size());
                }
        };


        class SideCrossIterator : public LIterator {
            private:
                MagicalContainer* _container;
                size_t _index;
            public:
                
				SideCrossIterator(): _container(nullptr), _index(0) {}
                
				SideCrossIterator(MagicalContainer& magical): _container(&magical), _index(0){}
                
				SideCrossIterator(const SideCrossIterator& side_cross_iter);
                
				SideCrossIterator(MagicalContainer *container, size_t index): _container(container), _index(index){} //inline implement
                
				~SideCrossIterator() override = default;

                SideCrossIterator &operator=(const SideCrossIterator &side_cross_iter_other);
                
				bool operator==(const LIterator &other) const override;
				bool operator==(const SideCrossIterator &other) const;
                
				
				bool operator!=(const LIterator &other) const override;
				bool operator!=(const SideCrossIterator &other) const;
                
				bool operator<(const LIterator &other) const override;
				bool operator<(const SideCrossIterator &other) const;
                
				
				bool operator>(const LIterator &other) const override;
				bool operator>(const SideCrossIterator &other) const;
               
                
               
               
                SideCrossIterator& operator++();
                int operator*() const;

                SideCrossIterator begin(){
                    return SideCrossIterator(_container, 0);
                }

                SideCrossIterator end() const{
                    return SideCrossIterator(_container, _container->SideCross_Elements.size());
                }
        };

    };

}
