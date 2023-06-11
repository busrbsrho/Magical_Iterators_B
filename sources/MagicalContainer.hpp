#pragma once

#include <set>
#include <vector>
#include <stdexcept>
using namespace std;

namespace ariel
{
	class MagicalContainer
	{
		private:
			set<int> _elements; // to keep the element in ascending order
			vector<const int *> _elements_ascending_order;
			vector<const int *> _elements_sidecross_order;
			vector<const int *> _elements_prime_order;

			
	static bool isPrime(int num){
    if (abs(num) <= 1)
    {
		return false;
    }
    
	
	for (int i = 2; i*i < num; ++i)
	{
		if (num % i == 0)
			return false;
	}
	
	return true;
    }

		public:
			
			MagicalContainer()=default; // defult constructor
			
			void addElement(int element);

			void removeElement(int element);

			
			size_t size() const {
				return _elements.size();
			}



		class AscendingIterator
		{
			private:
				MagicalContainer& container;
				size_t index;

				
				AscendingIterator(MagicalContainer &cont, size_t index);

			public:
				
				AscendingIterator(MagicalContainer &cont);

				~AscendingIterator() = default;

				
				AscendingIterator(const AscendingIterator &other);//copy constructor

				
				AscendingIterator(AscendingIterator &&other) noexcept;
				
				
				AscendingIterator &operator=(const AscendingIterator &other) {
					if (this != &other)
					{
						container = other.container;
						index = other.index;
					}
					return *this;
				}

				
				AscendingIterator &operator=(AscendingIterator &&other) noexcept;
			
				
				bool operator==(const AscendingIterator &other) const {
					return index == other.index;
				}

				
				bool operator!=(const AscendingIterator &other) const {
					return index != other.index;
				}

				
				bool operator<(const AscendingIterator &other) const {
					return index < other.index;
				}

				bool operator>(const AscendingIterator &other) const {
					return index > other.index;
				}

		
				int operator*() const {
					if (index > container._elements_ascending_order.size())
					{
						throw out_of_range("Iterator out of range");
					}

					return *(container._elements_ascending_order.at(index));
				}

				
				AscendingIterator &operator++() {
					if (index > container._elements_ascending_order.size())
					{
						throw out_of_range("Iterator out of range");
					}
					
					++index;
					return *this;
				}

				
				AscendingIterator begin() {
					return AscendingIterator(container, 0);
				}

				AscendingIterator end() const {
					return AscendingIterator(container, container._elements_ascending_order.size());
				}
		};

		class PrimeIterator
		{
			private:
				MagicalContainer& container;
				size_t index;

				
				PrimeIterator(MagicalContainer &cont, size_t index);

			public:
				
				PrimeIterator(MagicalContainer &cont);

				
				~PrimeIterator() = default;

				PrimeIterator(const PrimeIterator &other);

				
				PrimeIterator(PrimeIterator &&other) noexcept;
				
				
				PrimeIterator &operator=(const PrimeIterator &other) {
					if (this != &other)
					{
						container = other.container;
						index = other.index;
					}

					return *this;
				}

				
				PrimeIterator &operator=(PrimeIterator &&other) noexcept;
			
				
				bool operator==(const PrimeIterator &other) const {
					return index == other.index;
				}

				bool operator!=(const PrimeIterator &other) const {
					return index != other.index;
				}

				
				bool operator<(const PrimeIterator &other) const {
					return index < other.index;
				}

				
				bool operator>(const PrimeIterator &other) const {
					return index > other.index;
				}

				int operator*() const {
					if (index > container._elements_ascending_order.size())
					{
						throw out_of_range("Iterator out of range");
					}

					return *(container._elements_prime_order.at(index));
				}

				
				PrimeIterator &operator++() {
					if (index > container._elements_prime_order.size())
					{
						throw out_of_range("Iterator out of range");
					}
					
					++index;
					return *this;
				}

				
				PrimeIterator begin() {
					return PrimeIterator(container, 0);
				}

				
				PrimeIterator end() const {
					return PrimeIterator(container, container._elements_prime_order.size());
				}
		};

		class SideCrossIterator
		{
			private:
				MagicalContainer& container;
				size_t index;

				
				SideCrossIterator(MagicalContainer &cont, size_t index);

			public:
				
				SideCrossIterator(MagicalContainer &cont);

				
				~SideCrossIterator() = default;

				
				SideCrossIterator(const SideCrossIterator &other);

				
				SideCrossIterator(SideCrossIterator &&other) noexcept;
				
				
				SideCrossIterator &operator=(const SideCrossIterator &other) {
					if (this != &other)
					{
						container = other.container;
						index = other.index;
					}

					return *this;
				}

				
				SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
			
				
				bool operator==(const SideCrossIterator &other) const {
					return index == other.index;
				}

				
				bool operator!=(const SideCrossIterator &other) const {
					return index != other.index;
				}

				
				bool operator<(const SideCrossIterator &other) const {
					return index < other.index;
				}

				
				bool operator>(const SideCrossIterator &other) const {
					return index > other.index;
				}

				
				int operator*() const {
					if (index > container._elements_ascending_order.size())
					{
						throw out_of_range("Iterator out of range");
					}
					
					return *(container._elements_sidecross_order.at(index));
				}

				
				SideCrossIterator &operator++() {
					if (index > container._elements_sidecross_order.size())
					{
						throw out_of_range("Iterator out of range");
					}
					
					++index;
					return *this;
				}

				
				SideCrossIterator begin() {
					return SideCrossIterator(container, 0);
				}

		
				SideCrossIterator end() const {
					return SideCrossIterator(container, container._elements_sidecross_order.size());
				}
		};
	};
}