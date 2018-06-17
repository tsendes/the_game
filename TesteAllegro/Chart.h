#pragma once
#include <stdlib.h>
#include "Element.h"

template<class T>
class Chart
{
public:
	Chart()
	{
		pFirst = NULL;
		pNext = NULL;
	}
	~Chart()
	{
		delete (pNext);
		delete (pFirst);
	}
	void addToList(T* info)
	{
		if (pFirst == NULL)
		{
			pFirst = new Element<T>;
			pNext = NULL;
			pFirst->setpInfo(info);
		}
		else
		{
			Element<T>* pAux = pFirst;
			while (pAux->getpNext() != NULL)
				pAux = pAux->getpNext();

			pAux->setpNext(new Element<T>);
			pAux = pAux->getpNext();
			pAux->setpNext(NULL);
			pAux->setpInfo(info);
		}
	}
	void removeFromList()
	{
		Chart<T>* pAux = pFirst;
		Chart<T>* pPrevious;
		while (pAux->pNext != NULL)
		{
			pPrevious = pAux;
			pAux = pNext;
		}
		delete pAux;
		pPrevious->pNext = NULL;
	}
	void setpFirst(Element<T>* el)
	{
		pFirst = el;
	}
	void setpNext(Element<T>* el)
	{
		pNext = el;
	}
	Element<T>* getpFirst()
	{
		return pFirst;
	}
	Element<T>* getpNext()
	{
		return pNext;
	}
	Element<T>* getpLast()
	{
		Element<T>* pAux = pFirst;
		while (pAux->getpNext() != NULL)
			pAux = pAux->getpNext();
		return pAux;
	}

private:
	Element<T>* pFirst;
	Element<T>* pNext;
};