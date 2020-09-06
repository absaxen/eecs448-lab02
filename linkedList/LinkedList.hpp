/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	
	/** TODO 
		Fix this method
	*/
	int count = 0; // Initialize count  
	Node<T>* temp = m_front; // Initialize current  
	while (temp != NULL)
	{
		count++;
		temp = temp->getNext();
	}
	return count;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO 
		Fix this method
	*/
	while ((!isFound) && (m_front != NULL)) //runs through list until data is found within a node or end of list is reached
	{
		if (temp->getValue() == value) //if the node's data equals the key then the node has been found
			isFound = true;
		else
			temp = temp->getNext(); //moves to next node in list
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* secondintoLast = nullptr;
	Node<T>* temp = m_front;
	bool isRemoved = false;

	/** TODO 
		Fix this method
	*/
	if (temp == nullptr)
	{
		std::cout << "List is empty!";
	}
	if (temp->getNext() == nullptr)
	{
		delete temp;
		isRemoved = true;
	}
	secondintoLast = m_front;
	while (secondintoLast->getNext()->getNext() != nullptr)
	{
		secondintoLast = secondintoLast->getNext();
	}

	delete (secondintoLast->getNext());
	secondintoLast->setNext(nullptr);
	isRemoved = true;
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
