/**
 * @file	list.h
 * @brief	Include file for class "List"
 */

#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned short int USI;

template <class T> 
struct Item
{
	T data;
	Item<T> *next;

	Item() : data(), next(0) {}

	Item(const Item<T> &i) 
	{
		if (this != &i)
		{
			data = i.data;
			next = 0;
		}
	}

	Item(const T &_data) : data(_data), next(0) {}

	~Item()
	{
		next = 0;
	}

	Item<T>& operator=(const Item<T> &i)
	{
		if (this != &i)
		{
			data = i.data;
			next = 0;
		}
		return *this;
	}
};

template <class T> 
class List
{
	Item<T> *begin, *end;
	USI size;
public:
	List() : begin(0), end(0), size(0) {}

	List(const List<T> &l);

	~List();

	List<T>& operator=(const List<T> &l);

	USI Size() const;

	void Print(std::ostream &out) const;

	void PushBack(const T &elem);

	void PopBack();

	void Clear();

	void Compact(size_t sz);
};

template <class T> 
inline List<T>::List(const List<T> &l) : begin(0), end(0), size(0)
{
	if(this != &l && l.Size() && l.begin)
	{
		Item<T> *i = l.begin;
		while (i)
		{
			this->PushBack(i->data);
			i = i->next;
		}
	}
}

template <class T> 
inline List<T>::~List()
{
	if (begin)
	{
		Item<T> *i = begin, *tmp;
		while (i)
		{
			tmp = i;
			i = i->next;
			delete tmp;			
		}
	}
}

template <class T> 
inline List<T>& List<T>::operator=(const List<T> &l)
{
	begin = end = 0;
	size = 0;
	if(this != &l && l.Size() && l.begin)
	{
		Item<T> *i = l.begin;
		while (i)
		{
			this->PushBack(i->data);
			i = i->next;
		}
	}
	return *this;
}

template <class T> 
inline USI List<T>::Size() const
{
	return size;
}

template <class T> 
inline void List<T>::Print(std::ostream &out) const
{
	Item<T> *i = begin;
	while (i)
	{
		out << i->data << ' ' << i<< ' ';
		out << '\n';
		i = i->next;
	}
}

template <class T> 
inline void List<T>::PushBack(const T &elem)
{
	if (begin)
	{
		if (end)
		{
			Item<T> *tmp = new Item<T>(elem);
			if (tmp)
			{
				end->next = tmp;
				end = tmp;
				++size;
			}
			else
			{
				cout << "Memory was not allocated\n";
			}
		}
		else
		{
			cout << "NULL pointer\n";
		}
	}
	else
	{
		Item<T> *tmp = new Item<T>(elem);
		if (tmp)
		{
			begin = end = tmp;
			++size;
		}
		else
		{
			cout << "Memory was not allocated\n";
		}
	}	
}

template <class T> 
inline void List<T>::PopBack()
{
	if (end)
	{
		if (begin == end)
		{
			delete begin;
			begin = end = 0;
		}
		else if (begin)
		{
			Item<T> *i = begin;
			while (i->next != end)
			{
				i = i->next;
			}
			i->next = 0;
			delete end;
			end = i;
		}
		--size;
	}
}

template <class T> 
std::ostream& operator << (std::ostream &out, const List<T> &l)
{
	l.Print(out);
	return out;
}

template <class T> 
void inline List<T>::Clear()
{
	if (begin)
	{
		Item<T> *i = begin, *tmp;
		while (i)
		{
			tmp = i;
			i = i->next;
			delete tmp;			
		}
		begin = end = 0;
		size = 0;
	}
}

template <class T> 
inline void List<T>::Compact(size_t sz)
{
	char *temp = new char[sz * size];
	Item<T> *curr = begin;
	for (USI i = 0; i < size; ++i)
	{
		memcpy(temp + i * sz, curr, sz);
		curr = curr->next;
		//cout<<i<<' ';
	}
	USI szTmp = size;
	//this->Clear();
	begin = (Item<T> *)temp;
	curr = begin;
	for (USI i = 0; i < szTmp; ++i)
	{
		if(i != szTmp - 1)
		{
			curr->next = (Item<T> *)(temp + (i + 1) * sz);
			curr = curr->next;
		}
		else
		{
			//curr->next = 0;
		}
		
	}
}

#endif /* _LIST_H_ */