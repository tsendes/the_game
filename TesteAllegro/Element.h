#pragma once

template <class T2>
class Element
{
private:
	Element<T2>* pNext;
	Element<T2>* pFirst;
	T2* pInfo;

public:
	void setpNext(Element<T2>* p)
	{
		pNext = p;
	}
	Element <T2>* getpNext()
	{
		return pNext;
	}
	void setpFirst(Element<T2> p)
	{
		pFirst = p;
	}
	Element<T2>* getpFirst()
	{
		return pFirst;
	}
	Element<T2>* setpFirst()
	{
		return pFirst;
	}
	void setpInfo(T2* p)
	{
		pInfo = p;
	}
	T2* getpInfo()
	{
		return pInfo;
	}
	Element()
	{
		pFirst = NULL;
		pNext = NULL;
	}
	~Element()
	{

	}
	void addToList(T2* info)
	{
		if (pFirst == NULL)
		{
			pFirst = new Element<T2>;
			pNext = NULL;
			pFirst->setpInfo(new T2);
		}
		else
		{
			Element<T2>* pAux = pFirst;
			while (pAux->pNext != NULL)
				pAux = pNext;
			pAux->pNext = new Element<T2>;
			pAux = pAux->pNext;
			pAux->setpInfo(info);

		}

	}
	Element<T2>* removeFromList(Element<T2>* pFirst)
	{
		Element<T2>* pAux = pFirst;
		Element<T2>* pPrevious;
		while (pAux->pNext != NULL)
		{
			pPrevious = pAux;
			pAux = pNext;
		}
		delete pAux;
		pPrevious->pNext = NULL;
	}
};
