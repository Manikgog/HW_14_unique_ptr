/*!
\brief класс урожай (Harvest) и его наследники Apple (яблоко), Peach (персик) и Cone (шишка)
Класс Harvest содержит основные характеристики плода: _harvestName (вид плода),
_weight (вес плода), _color (цвет плода).
Классы наследники содержат поле _sortOfHarvest, т.е. сорт плода.
*/
#ifndef _HARVEST_H_
#define _HARVEST_H_

#include <string>

class Harvest
{
private:
	std::string _harvestName;	//< _harvestName название плода
	float _weight;				//< _weight вес плода
	std::string _color;			//< _color цвет плода

public:
	Harvest(const std::string& harvestName, float weight, const std::string& color)
		: _harvestName(harvestName), _weight(weight), _color(color) {}

	virtual ~Harvest() {}

	/*!
	метод возвращающий название плода
	\param[out] std::string название плода
	*/
	std::string GetHarvestName()
	{
		return _harvestName;
	}

	/*!
	метод возвращающий вес плода
	\param[out] float число с плавающей точкой, характеризующее вес плода
	*/
	float GetWeight()
	{
		return _weight;
	}

	/*!
	метод возвращающий цвет плода
	\param[out] std::string цвет плода
	*/
	std::string GetColor()
	{
		return _color;
	}

	virtual void PrintHarvest() = 0;


};

class Apple : public Harvest
{
private:
	std::string _sortOfHarvest;

public:
	Apple() : Harvest("", 0.0f, ""), _sortOfHarvest("") {}
	Apple(std::string harvestName, float weight, std::string color, std::string sortOfHarvest)
		: Harvest(harvestName, weight, color), _sortOfHarvest(sortOfHarvest) {}

	/*!
	метод для возвращения сорта яблока
	\param[out] std::string сорт яблока
	*/
	std::string GetSortOfHarvest()
	{
		return _sortOfHarvest;
	}

	/*!
	метод для вывода на экран полей класса Apple и его родителя Harvest
	*/
	void PrintHarvest() override
	{
		std::cout << "Вид плода: " << GetHarvestName() << "\nВес плода: " << GetWeight() << "\nЦвет плода: " << GetColor() << std::endl;
		std::cout << "Сорт: " << _sortOfHarvest << std::endl;
	}

};

class Peach : public Harvest
{
private:
	std::string _sortOfHarvest;

public:
	Peach() : Harvest("", 0.0f, ""), _sortOfHarvest("") {}
	Peach(std::string harvestName, float weight, std::string color, std::string sortOfHarvest)
		: Harvest(harvestName, weight, color), _sortOfHarvest(sortOfHarvest) {}
	
	/*!
	метод для возвращения сорта персика
	\param[out] std::string сорт персика
	*/
	std::string GetSortOfHarvest()
	{
		return _sortOfHarvest;
	}

	/*!
	метод для вывода на экран полей класса Peach и его родителя Harvest
	*/
	void PrintHarvest() override
	{
		std::cout << "Вид плода: " << GetHarvestName() << "\nВес плода: " << GetWeight() << "\nЦвет плода: " << GetColor() << std::endl;
		std::cout << "Сорт: " << _sortOfHarvest << std::endl;
	}

};

class Cone : public Harvest
{
private:
	std::string _sortOfHarvest;

public:
	Cone() : Harvest("", 0.0f, ""), _sortOfHarvest("") {}
	Cone(std::string harvestName, float weight, std::string color, std::string sortOfHarvest)
		: Harvest(harvestName, weight, color), _sortOfHarvest(sortOfHarvest) {}

	/*!
	метод для возвращения сорта шишки
	\param[out] std::string сорт шишки
	*/
	std::string GetSortOfHarvest()
	{
		return _sortOfHarvest;
	}

	/*!
	метод для вывода на экран полей класса Cone и его родителя Harvest
	*/
	void PrintHarvest() override
	{
		std::cout << "Вид плода: " << GetHarvestName() << "\nВес плода: " << GetWeight() << "\nЦвет плода: " << GetColor() << std::endl;
		std::cout << "Сорт: " << _sortOfHarvest << std::endl;
	}

};



#endif // !_HARVEST_H_

