/*!
\brief файл с классом Plant и его наследниками AppleTree, PeachTree, SpruceTree.
*/
#ifndef _PLANT_H_
#define _PLANT_H_

#include <string>
#include "Harvest.h"

class Plant
{
private:
	std::string _plantName;	//< _plantName вид растения
	std::string _size;		//< _size размер растения
	int _amountHarvest;		//< _amountHarvest количество плодов на растении

public:
	Plant(const std::string& plantName, const std::string& size, int amountHarvest)
		: _plantName(plantName), _size(size), _amountHarvest(amountHarvest) {}

	Plant(const Plant& plant)
		: _plantName(plant._plantName),
		_size(plant._size),
		_amountHarvest(plant._amountHarvest) {}

	virtual ~Plant() {}

	/*!
	метод возвращающий название вида растения
	\param[out] std::string вид растения
	*/
	std::string GetPlantName()
	{
		return _plantName;
	}

	/*!
	метод возвращающий размер растения
	\param[out] std::string размер растения
	*/
	std::string GetSizeOfPlant()
	{
		return _size;
	}

	/*!
	метод возвращающий количество плодов на растении
	\param[out] int& количество плодов на растении
	*/
	int& GetAmountOfHarvest()
	{
		return _amountHarvest;
	}

	virtual void PrintPlant() = 0;

	virtual std::unique_ptr<Apple> GetHarvestApple() = 0;
	virtual std::unique_ptr<Peach> GetHarvestPeach() = 0;
	virtual std::unique_ptr <Cone> GetHarvestCone() = 0;
};


class AppleTree : public Plant
{
private:
	std::string _name;	//< _name название растения

public:
	AppleTree(std::string plantName, std::string size, int amountHarvest, std::string name)
				: Plant(plantName, size, amountHarvest), _name(name) {}

	/*!
	метод выводящий на экран поля класса
	*/
	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	/*!
	метод возвращающий название растения
	\param[out] std::string название растения
	*/
	std::string GetName()
	{
		return _name;
	}
	/*!
	\brief метод для сбора урожая
	определяет количество плодов на растении, затем уменьшает его и возвращает
	указатель std::unique_ptr<Apple> на объект плода если количество плодов на 
	растении больше нуля, в противном случает возвращает нулевой указатель.
	\param[out] std::unique_ptr<Apple> указатель на объект плода
	*/
	std::unique_ptr<Apple> GetHarvestApple() override
	{
		int amount = GetAmountOfHarvest()--;

		if (amount > 0)
			return std::make_unique<Apple>("яблоко", 0.12f, "красный", "антоновка");
		return nullptr;
	}
	std::unique_ptr<Peach> GetHarvestPeach() { return nullptr; }
	std::unique_ptr <Cone> GetHarvestCone() { return nullptr; }

};

class PeachTree : public Plant
{
private:
	std::string _name;

public:
	PeachTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest), _name(name) {}
	
	/*!
	метод выводящий на экран поля класса
	*/
	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	/*!
	метод возвращающий название растения
	\param[out] std::string название растения
	*/
	std::string GetName()
	{
		return _name;
	}

	/*!
	\brief метод для сбора урожая
	определяет количество плодов на растении, затем уменьшает его и возвращает
	указатель std::unique_ptr<Peach> на объект плода если количество плодов на
	растении больше нуля, в противном случает возвращает нулевой указатель.
	\param[out] std::unique_ptr<Peach> указатель на объект плода
	*/
	std::unique_ptr<Peach> GetHarvestPeach() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return std::make_unique<Peach>("персик", 0.15f, "красный", "принц");
		return nullptr;
	}
	std::unique_ptr<Apple> GetHarvestApple() { return nullptr; }
	std::unique_ptr <Cone> GetHarvestCone() { return nullptr; }
};

class SpruceTree : public Plant
{
private:
	std::string _name;

public:
	SpruceTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest), _name(name) {}

	/*!
	метод выводящий на экран поля класса
	*/
	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	/*!
	метод возвращающий название растения
	\param[out] std::string название растения
	*/
	std::string GetName()
	{
		return _name;
	}

	/*!
	\brief метод для сбора урожая
	определяет количество плодов на растении, затем уменьшает его и возвращает
	указатель std::unique_ptr<Cone> на объект плода если количество плодов на
	растении больше нуля, в противном случает возвращает нулевой указатель.
	\param[out] std::unique_ptr<Cone> указатель на объект плода
	*/
	std::unique_ptr <Cone> GetHarvestCone() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return std::make_unique<Cone>("шишка", 0.05f, "коричневый", "еловая");
		return nullptr;
	}

	std::unique_ptr<Apple> GetHarvestApple() { return nullptr; }
	std::unique_ptr<Peach> GetHarvestPeach() { return nullptr; }
};


#endif // !

