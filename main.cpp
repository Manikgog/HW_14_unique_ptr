#include <iostream>
#include <string>
#include <Windows.h>
#include <memory>
#include "Harvest.h"
#include "Plant.h"
#include "Garden.h"
#include "Fabrica.h"
#include "Backpack.h"



int main()
{
	system("chcp 1251");
	system("cls");
	
	GardenOfTrees<AppleTree> gardenOfAppleTree;							//< яблоневый сад (класс содержащий вектор указателей на объекты класса AppleTree)
	for (int i = 0; i < 3; i++)
	{
		FabricaOfTrees* fabrica = new FabricaOfAppleTrees();
		gardenOfAppleTree.Push_back(fabrica->makeAppleTree());
		delete fabrica;
	}

	GardenOfTrees<PeachTree> gardenOfPeachTree;							//< сад персиковых деревьев (класс содержащий вектор указателей на объекты класса PeachTree)
	for (int i = 0; i < 5; i++)
	{
		FabricaOfTrees* fabrica = new FabricaOfPeachTrees();

		gardenOfPeachTree.Push_back(fabrica->makePeachTree());
		delete fabrica;
	}

	GardenOfTrees<SpruceTree> gardenOfSpruceTree;						//< сад кедров (класс содержащий вектор указателей на объекты класса SpruceTree)
	for (int i = 0; i < 8; i++)
	{
		FabricaOfTrees* fabrica = new FabricaOfSpruceTrees();
		gardenOfSpruceTree.Push_back(fabrica->makeSpruceTree());
		delete fabrica;
	}

	Backpack<Apple> backpackOfApples;									//< рюкзак с яблоками (вектор указателей на объекты типа Apple)
	for (size_t i = 0; i < gardenOfAppleTree.Size(); i++)
	{
		while (gardenOfAppleTree.GetPlants(i)->GetAmountOfHarvest() > 0)
		{
			std::unique_ptr<Apple> apple = gardenOfAppleTree.GetPlants(i)->GetHarvestApple();
			backpackOfApples.Push_back(std::make_unique<Apple>(*apple));
		}
	}

	Backpack<Peach> backpackOfPeaches;									//< рюкзак с персиками (вектор указателей на объекты типа Peach)
	for (size_t i = 0; i < gardenOfPeachTree.Size(); i++)
	{
		while (gardenOfPeachTree.GetPlants(i)->GetAmountOfHarvest() > 0)
		{
			std::unique_ptr < Peach> peach = gardenOfPeachTree.GetPlants(i)->GetHarvestPeach();
			backpackOfPeaches.Push_back(std::make_unique <Peach>(*peach));
		}
	}

	Backpack<Cone> backpackOfCones;										//< рюкзак с шишками (вектор указателей на объекты типа Cone)
	for (size_t i = 0; i < gardenOfSpruceTree.Size(); i++)
	{
		while (gardenOfSpruceTree.GetPlants(i)->GetAmountOfHarvest() > 0)
		{
			std::unique_ptr <Cone> cone = gardenOfSpruceTree.GetPlants(i)->GetHarvestCone();
			backpackOfCones.Push_back(std::make_unique <Cone>(*cone));
		}
	}
	std::cout << "-------------------------------------------------------------------------------------\n";
	std::cout << "Количество яблонь саду равно " << gardenOfAppleTree.Size() << std::endl;
	std::cout << "Количество персиковых деревьев в саду равно " << gardenOfPeachTree.Size() << std::endl;
	std::cout << "Количество деревьев в кедровнике равно " << gardenOfSpruceTree.Size() << std::endl;
	std::cout << "-------------------------------------------------------------------------------------\n";
	std::cout << "Количество яблок в рюкзаке - " << backpackOfApples.GetSize() << " шт.\n";
	std::cout << "Полный вес рюкзака с яблоками равен - " << backpackOfApples.GetTotalWeight() << " кг." << std::endl;
	std::cout << "-------------------------------------------------------------------------------------\n";
	std::cout << "Количество персиков в рюкзаке - " << backpackOfPeaches.GetSize() << " шт.\n";
	std::cout << "Полный вес рюкзака с персиками равен - " << backpackOfPeaches.GetTotalWeight() << " кг." << std::endl;
	std::cout << "-------------------------------------------------------------------------------------\n";
	std::cout << "Количество шишек в рюкзаке - " << backpackOfCones.GetSize() << " шт.\n";
	std::cout << "Полный вес рюкзака с шишками равен - " << backpackOfCones.GetTotalWeight() << " кг." << std::endl;
	std::cout << "-------------------------------------------------------------------------------------\n";
	Cone cone = backpackOfCones.GetHarvest();
	std::cout << "Количество шишек в рюкзаке - " << backpackOfCones.GetSize() << " шт.\n";


	return 0;
}

