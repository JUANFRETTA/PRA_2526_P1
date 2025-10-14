#include <ostream>
#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux;
			while(first != nullptr){
				aux = first->next;
				delete first;
				first= aux;
			};
		}

		T operator[](int pos) const{
			if(pos <0 || pos >=n){
				throw std::out_of_range("Posicion inválida");
			}
			Node<T>* current = first;
			for(int i = 0; i<pos;i++)
				current = current->next;
			return current->data;
		}

		friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        		Node<T>* current = list.first;
        		out << "[";
       			 while (current != nullptr) {
           		 out << current->data;
           		 if (current->next != nullptr)
               			 out << ", ";
           		current = current->next;
       			 }
       			 out << "]";
        		return out;
   		 }

		void insert(int pos, T e) override{
			if(pos<0 ||pos>n){
				throw std::out_of_range("Posicion invalida");
			}

			if(pos == 0){
				first = new Node<T>(e,first);
			}else{
				Node<T>* prev = first;
				for(int i = 0; i<pos-1;i++)
					prev = prev->next;
				prev->next = new Node<T>(e,prev->next);
			}
			n++;
		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0,e);
		}

		T remove(int pos)override{
			if(pos<0 || pos >=n)
				throw std:: out_of_range("Posicion invalida en remove");
			Node<T>* toDelete;
			T value;

			if(pos == 0){
				toDelete = first;
				first = first->next;
			}else{
				Node<T>* prev = first;
				for(int i = 0; i<pos-1;i++)
					prev = prev->next;

				toDelete = prev->next;
				prev->next = toDelete->next;
			}

			value = toDelete->data;
			delete toDelete;
			n--;
			return value;
		}

		T get(int pos)override{
			if(pos<0 || pos >=n)
				throw std::out_of_range("Posicion invalida en get");
			Node<T>* prev = first;
			for(int i =0; i<pos-1;i++)
				prev = prev->next;

			return prev->data;
		}

		int search(T e)override{
			Node<T>* curr = first;
			int pos = 0;
			while(curr != nullptr){
				if(curr->data == e)
					return pos;
				curr = curr->next;
				pos++;
			};
			return -1;
		}

		bool empty(T e)override{
			return n == 0;
		}

		int size()override{
			return n;
		}


};
