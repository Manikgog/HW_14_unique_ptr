/*!
\brief класс Garden (Сад) для хранения указателей на объекты растений (AppleTree, PeachTree, SpruceTree)
*/
#ifndef _GARDEN_H_
#define _GARDEN_H_

#include <vector>
#include "Plant.h"

template <typename T>
class GardenOfTrees
{
private:
	std::vector<std::unique_ptr<T>> _plants;


public:

	~GardenOfTrees()
	{}

	/*!
	метод для добавления растения в сад (для добавления указателя std::unique_ptr<T> на объект типа Т (AppleTree, PeachTree или SpruceTree) в вектор _plants
	\param[in] plant указатель std::unique_ptr<T> на оьъект типа Т (AppleTree, PeachTree или SpruceTree)
	*/
	void Push_back(T* plant)
	{
		_plants.push_back(std::make_unique<T>(*plant));
	}

	/*!
	метод для  обеспечения доступа к вектору умных указателей
	std::unique_ptr<T> по переданному индексу
	\param[in] index целое число, которые соответствует индексу вектора умных указателей
	\param[out] std::unique_ptr<T>& ссылка на указатель
	*/
	std::unique_ptr<T>& GetPlants(size_t index)
	{
		return _plants.at(index);
	}

	size_t Size()
	{
		return _plants.size();
	}

};

#endif

