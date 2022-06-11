#include <iostream>
#include <vector>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestRun.h>

#include "cell.hpp"
#include "point.hpp"
#include "board.hpp"

void cellTest();
void pointTest();
void boardTest();

int main(int argc, char const *argv[]) {
  if (CU_initialize_registry() != CUE_SUCCESS)
    std::cout << "Can't initialize test registry" << std::endl;

	CU_pSuite cellSuit = CU_add_suite("cellSuit", NULL, NULL);
	CU_pSuite pointSuit = CU_add_suite("pointSuit", NULL, NULL);
	CU_pSuite boardSuit = CU_add_suite("boardSuit", NULL, NULL);

	if (CU_get_error() != CUE_SUCCESS)
    std::cout << "CUnit error" << std::endl;

	CU_add_test(cellSuit, "cellSuit", cellTest);
	CU_add_test(pointSuit, "pointSuit", pointTest);
	CU_add_test(boardSuit, "pointSuit", boardTest);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();  
  CU_cleanup_registry(); 
  return CU_get_number_of_failures();
}


void cellTest() {
  
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      bool isAilve = (i + j) % 2;
      Cell c(i, j, isAilve);
      CU_ASSERT_EQUAL(c.getCol(), i);
      CU_ASSERT_EQUAL(c.getRow(), j);
      CU_ASSERT_EQUAL(c.getIsAlive(), isAilve);
    }
  }

  Cell c(-1, -1, false);

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      bool isAilve = (i + j) % 2;

      c.setCol(i);
      c.setRow(j);
      c.setIsAlive(isAilve);
      
      CU_ASSERT_EQUAL(c.getCol(), i);
      CU_ASSERT_EQUAL(c.getRow(), j);
      CU_ASSERT_EQUAL(c.getIsAlive(), isAilve);
    }
  }
}

void pointTest() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      Point p(i, j);
      CU_ASSERT_EQUAL(p.x, i);
      CU_ASSERT_EQUAL(p.y, j);
    }
  }
}


void boardTest() {
  Board b(16, 16);

  for (int i = -4; i < 20; i++) {
    for (int j = -4; j < 20; j++) {
      if (i < 0 || j < 0 || i >= 16 || j >= 16) {
        CU_ASSERT_FALSE(b.cellBelong(i, j));
      } else {
        CU_ASSERT_TRUE(b.cellBelong(i, j));
      }
    }
  }

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      bool state = b.getCellState(i, j);
      std::vector<Cell> nbs = b.getNeighbors(i, j);

      int count = 0;
      for (Cell & c : nbs) {
        if (c.getIsAlive()) count++;
      }

      CU_ASSERT_EQUAL(b.countAliveNeighbors(i, j), count);

      bool newState;
      if (state) {
        if (count == 3 || count == 2) newState = true;
        else newState = false;
      } else {
        if (count == 3) newState = true;
        else newState = false;
      }

      CU_ASSERT_EQUAL(b.newCellState(Cell(i, j, state)), newState);
    }
  }
}