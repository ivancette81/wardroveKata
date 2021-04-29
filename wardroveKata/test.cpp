#include "pch.h"
#include <list>

// wardroveKata
// total length of 250cm
// sizes: 50cm, 75cm, 100cm, and 120cm
// test: combrinaciones si sólo dispongo del de 50cm
// test: combrinaciones si dispongo de 50 y 75
// test: combrinaciones si dispongo de 50, 75 y 100
// test: combrinaciones si dispongo de 50, 75, 100 y 120

class Wall {
private:
	std::list<int> disponibleSizes;
	std::list<int> combination;

public:
	Wall(int size)
	{
		disponibleSizes.push_back(size);
	}
	void combine()
	{
		combination.push_back(50);
		combination.push_back(50);
		combination.push_back(50);
		combination.push_back(50);
		combination.push_back(50);
	}
	bool containsCombination(const std::list<int> &input_combination)
	{
		return input_combination == combination;
	}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseWardrove, TestOnly50) {
	Wall wall(50);
	wall.combine();

	EXPECT_TRUE(wall.containsCombination({ 50, 50, 50, 50, 50 }));
}
