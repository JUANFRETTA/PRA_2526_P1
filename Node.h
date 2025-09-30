#include <ostream>
template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;
		//Constructor
		Node(T d, Node<T>* n=nullptr){
			data = d;
			next = n;
		}

		friend std::ostream& operator<<(std::ostream& out, const Node<T>& node){
			out << node.data;
			return out;
		}
	};
