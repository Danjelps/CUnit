#define BOOST_TEST_MODULE mytests

#include <CUnit.h>
#include <TestDB.h>

void test_main(void)
{
	int result = main();

	CU_ASSERT_EQUAL(result, 0);
}


