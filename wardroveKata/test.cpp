#include "pch.h"
#include <list>
#include <algorithm>

// wardroveKata
// total length of 250cm
// sizes: 50cm, 75cm, 100cm, and 120cm
// test: combinaciones si sólo dispongo del de 50cm
// test: combinaciones si dispongo de 50 y 75
// test: combinaciones si dispongo de 50, 75 y 100
// test: combinaciones si dispongo de 50, 75, 100 y 120

class Wall {
private:
	std::list<int> disponibleSizes;
	std::list<std::list<int>> combinations;

	const int WALL_SIZE = 250;
public:
	Wall(const std::list<int>& sizes)
	{
		disponibleSizes = sizes;
		disponibleSizes.sort();
	}
	void combine()
	{
		std::list<int> combination;
		if (std::find(disponibleSizes.begin(), disponibleSizes.end(), 50) != disponibleSizes.end())
		{
			combination.push_back(50);
			combination.push_back(50);
			combination.push_back(50);
			combination.push_back(50);
			combination.push_back(50);
			combinations.push_back(combination);
		}
		if (std::find(disponibleSizes.begin(), disponibleSizes.end(), 75) != disponibleSizes.end())
		{
			combination.clear();
			combination.push_back(75);
			combination.push_back(75);
			combination.push_back(50);
			combination.push_back(50);
			combinations.push_back(combination);
		}

	}
	bool containsCombination(const std::list<int> &input_combination)
	{
		for (auto it = combinations.begin(); it != combinations.end(); it++)
		{
			if (input_combination == *it) return true;
		}
		return false;
	}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseWardrove, TestOnly50) {
	Wall wall({ 50 });
	wall.combine();

	EXPECT_TRUE(wall.containsCombination({ 50, 50, 50, 50, 50 }));
}

TEST(TestCaseWardrove, Test50_75) {
	Wall wall({ 50,75 });
	wall.combine();

	EXPECT_TRUE(wall.containsCombination({ 75, 75, 50, 50 }));
	EXPECT_TRUE(wall.containsCombination({ 50, 50, 50, 50, 50 }));
}