#include "funkcje.h"
#include <gtest/gtest.h>

using namespace std;

TEST(ZamienTest, ZamieniaZnaki) {
	ASSERT_EQ(zamien("margaryna", "a", "aa"), "maargaarynaa");
	ASSERT_EQ(zamien("margaryna", "a", ""), "mrgryn");
	ASSERT_EQ(zamien("margaryna", "ar", "x"), "mxgxyna");
	test();
}