
/*!
\brief класс рюкзак (Backpack)
для складывания урожая
*/
#ifndef _BACKPACK_H_
#define _BACKPACK_H_

#include <vector>

template <typename T>
class Backpack
{
private:
	std::vector<std::unique_ptr<T>> _backpack;

public:

	~Backpack()
	{}

	/*!
	метод для добавления в вектор указателей. Создаёт новый указатель и добавляет его в вектор.
	\param[in] harvest указатель на объект Apple, Peach или Cone
	*/
	void Push_back(const std::unique_ptr<T>& harvest)
	{
		_backpack.push_back(std::make_unique<T>(*harvest));
	}

	/*!
	метод для определения полного веса рюкзака
	\param[out] float число с плавающей запятой
	*/
	float GetTotalWeight()
	{
		float totalWeight = 0;
		for (const auto& el : _backpack)
		{
			totalWeight += el->GetWeight();
		}
		return totalWeight;
	}

	/*!
	метод для определения количества плодов в рюкзаке
	\param[out] size_t целое число
	*/
	size_t GetSize()
	{
		return _backpack.size();
	}

	/*!
	\brief метод для получения объектов типа T из класса Backpack
	\param[out] объект типа Т
	*/
	T GetHarvest()
	{
		if (_backpack.size() > 0)
		{
			T last = *(_backpack.back());
			_backpack.pop_back();
			return last;
		}
		std::cout << "Рюкзак пуст!\n";
		return T();
	}
};

#endif // !_BACKPACK_H_

