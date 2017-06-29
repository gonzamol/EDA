
#include "Error.h"

#ifndef SETOFINTS3_H_
#define SETOFINTS3_H_


class SetOfInts3 {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		static const int MAXSIZE = 5;

		int elems[MAXSIZE];
		int size;

		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);

	public:
		SetOfInts3();
		bool isEmpty() const;
		void add(int x) throw (Error);
		bool contains(int x) const;
		void remove(int x);
		void probar();
		friend istream& operator>>(istream& sIn,SetOfInts3& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
		bool operator==(const SetOfInts3& set);
		bool operator<(const SetOfInts3& set);
		bool esSubconjunto(const SetOfInts3& set);
		int getMax();
		void removeMax();
};

#endif /* SETOFINTS3_H_ */
