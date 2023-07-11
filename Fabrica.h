/*!
\brief файл содержит абстрактный класс FabricaOfTrees и три класса наследника
классы FabricaOfTrees и его наследники служат для создания объектов и возвращения указателей на них.
Объекты создаются с заранее заданными постоянными характеристиками:
plantName - вид растения (дерево, куст и т.п.),
size - условный размер (средний, большой, маленький),
amountOfHarvest - количество урожая в шт.,
name - название растения (яблоня, персиковое дерево, кедр).
Количество урожая (amountOfHarvest) задаётся случайным образом в заданных пределах.
*/
#ifndef _FABRICA_H_
#define _FABRICA_H_

#include <iostream>
#include <memory>
#include "Plant.h"

class FabricaOfTrees
{
public:
	virtual AppleTree* makeAppleTree() = 0;
	virtual PeachTree* makePeachTree() = 0;
	virtual SpruceTree* makeSpruceTree() = 0;
	virtual ~FabricaOfTrees() {};
};

class FabricaOfAppleTrees : public FabricaOfTrees
{
public:
	AppleTree* _appleTree;

	~FabricaOfAppleTrees()
	{
		std::cout << "деструктор яблони\n";
		if (_appleTree)
			delete _appleTree;
		_appleTree = nullptr;
	}

	/*!
	метод для создания объекта AppleTree
	\param[out] AppleTree* указатель на созданный объект
	*/
	AppleTree* makeAppleTree()override
	{
		int amountOfHarvest = rand() % 20 + 40;
		_appleTree = new AppleTree("дерево", "средний", amountOfHarvest, "яблоня");
		return _appleTree;
	}

	PeachTree* makePeachTree() { return nullptr; }
	SpruceTree* makeSpruceTree() { return nullptr; }

};

class FabricaOfPeachTrees : public FabricaOfTrees
{
public:
	PeachTree* _peachTree;

	~FabricaOfPeachTrees()
	{
		std::cout << "деструктор персика\n";
		if (_peachTree)
			delete _peachTree;
		_peachTree = nullptr;
	}

	/*!
	метод для создания объекта PeachTree
	\param[out] PeachTree* указатель на созданный объект
	*/
	PeachTree* makePeachTree()override
	{
		int amountOfHarvest = rand() % 10 + 30;
		_peachTree = new PeachTree("дерево", "средний", amountOfHarvest, "персиковое дерево");
		return _peachTree;
	}
	AppleTree* makeAppleTree() { return nullptr; }
	SpruceTree* makeSpruceTree() { return nullptr; }
};

class FabricaOfSpruceTrees : public FabricaOfTrees
{
public:
	SpruceTree* _spruceTree = nullptr;

	~FabricaOfSpruceTrees()
	{
		std::cout << "деструктор кедра\n";
		if (_spruceTree)
			delete _spruceTree;
		_spruceTree = nullptr;
	}

	/*!
	метод для создания объекта SpruceTree
	\param[out] SpruceTree* указатель на созданный объект
	*/
	SpruceTree* makeSpruceTree()override
	{
		int amountOfHarvest = rand() % 50 + 90;
		_spruceTree = new SpruceTree("дерево", "большой", amountOfHarvest, "кедр");
		return _spruceTree;
	}
	AppleTree* makeAppleTree() { return nullptr; }
	PeachTree* makePeachTree() { return nullptr; }
};


#endif
