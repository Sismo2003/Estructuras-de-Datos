#include <iostream>
#define capacidad 10

using namespace std;


template <typename objeto>
class arreglo_lista
{
	public:
	explicit arreglo_lista (int tam):i{tam},cap{i+capacidad	}
	{
		arr=new objeto[cap];
	}
	arreglo_lista (const arreglo_lista &rhs):i{rhs.i},cap{rhs.cap}, arr{nullptr}
	{
		arr=new objeto[cap];
		for(int k=0;k<i;k++)
		arr[k]=rhs.arr[k];
	}
	arreglo_lista(arreglo_lista &&rhs)
	{
		rhs.i=0;
		rhs.cap=0;
		rhs.arr=nullptr;
	}
	arreglo_lista()
	{
		i=0;
		cap=capacidad;
		arr=new objeto[capacidad];
	}
	~arreglo_lista()
	{
		delete []arr;
	}
	arreglo_lista & operator = (const arreglo_lista &rhs)
	{
		arreglo_lista copia=rhs;
		swap(*this, copia);
		return *this;
	}
	arreglo_lista & operator = (arreglo_lista &&rhs)
	{
		swap(i, rhs.i);
		swap(cap, rhs.i);
		swap(arr, rhs.arr);
		return *this;
	}
	void push_final(const objeto &rhs)
	{
		if(i==cap)
		cap=cap+1;//invocar metodo para aumentar el espacio
		arr[i]=rhs;
		i++;
	}
	void push_final(objeto &&rhs)
	{
		if(i==cap)
		cap=cap+1;//invocar metodo para aumentar el espacio
		arr[i]=move(rhs);
		i++;
	}
	void pop_final ()
	{
		if(!vacia())//metodo
		i--;
	}
	objeto & operator [] (int indice)
	{
		
	} 
	const objeto & operator [](int indice)const
	{
		
	} 
	void nueva_capacidad(int nueva_cap)
	{
		
	}
	void reservar(int nueva_capacidad)
	{
		
	}
	int vacia()
	{
		if(i==0)
		return 1;
		else
		return 0;
	}
	private:
	int i;
	int cap;
	objeto *arr;
};
int main()
{
	arreglo_lista <int> a;    
	arreglo_lista <string> b;
	arreglo_lista <float> c(0);
	int x=1;
	string s="Hola";
	a.push_final(7);
	a.push_final(x);
	b.push_final("Hola");
	c.push_final(4.5);
	a.pop_final();
	b.pop_final();
	c.pop_final();
	return 0;
}
