/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, testingemptyboard)
{
	Piezas game;
	Piece got = game.pieceAt(0,0);
	Piece test = Blank;
	ASSERT_EQ(got, test);
}

TEST(PiezasTest, getoutofbounds)
{
	Piezas game;
	Piece got = game.pieceAt(5,5);
	Piece test = Invalid;
	ASSERT_EQ(got, test);
}

TEST(PiezasTest, testfirstplaced)
{
	Piezas game;
	game.dropPiece(1);
	Piece got = game.pieceAt(0,1);
	Piece test = X;
	ASSERT_EQ(got, test);
}

TEST(PiezasTest, testsecondplaced)
{
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(1);
	Piece got = game.pieceAt(1,1);
	Piece test = O;
	ASSERT_EQ(got, test);
}

TEST(PiezasTest, placingoutofbounds)
{
	Piezas game;	
	Piece got = game.dropPiece(5);
	Piece test = Invalid;
	ASSERT_EQ(got, test);
}

TEST(PiezasTest, overplacing)
{
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(1);
	Piece got = game.dropPiece(1);
	Piece test = Blank;
	ASSERT_EQ(got, test);
}