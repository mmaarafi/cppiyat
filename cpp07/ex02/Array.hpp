#pragma once

template <typename T> class Array
{
	private:
		T* _elements;
		unsigned int _size;
	public:
		Array(): _elements(NULL), _size(0) {}
		Array(unsigned int n): _elements(new T[n]()), _size(n) {}
		Array(const Array& other) : _elements(NULL), _size(other._size)
		{
			if (_size > 0)
			{
				_elements = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = other._elements[i];
			}
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _elements; 
				_size = other._size;
				if (_size > 0)
				{
					_elements = new T[_size]();
					for (unsigned int i = 0; i < _size; i++)
						_elements[i] = other._elements[i];
				}
				else
					_elements = NULL;
			}
			return *this;
		}
		~Array() { delete[] _elements;}
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: Index is out of bounds!"; }
		};
		T& operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}
		unsigned int size() const
		{
			return _size;
		}
};