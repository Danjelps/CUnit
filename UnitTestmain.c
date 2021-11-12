#include <CUnit.h>
#include <TestDB.h>
#include <InitDeinit.h>
#include <Basic.h>
#include <assert.h>

//#define CU_DLL

static CU_TestInfo cmdTests[] = {
	{ "CmdTest1", CmdTest1 },
	{ "CmdTest2", CmdTest2 },
	CU_TEST_INFO_NULL,
};

static CU_SuiteInfo CmdSuite[] =
{
	{ "cmdTestSuite", CmdTestInit, CmdTestDeinit, CmdTestSetup, CmdTestTeardown, cmdTests },
	CU_SUITE_INFO_NULL,
};

int test_main(void)
{
	CU_initialize_registry();

	assert(NULL != CU_get_registry());
	assert(!CU_is_test_running());

	/* Register suites. */
	if (CU_register_suites(CmdSuite) != CUE_SUCCESS) {
		fprintf(stderr, "suite registration failed - %s\n",
			CU_get_error_msg());
	}
	else
	{
		CU_basic_set_mode(CU_BRM_VERBOSE);
		CU_set_error_action(CUEA_IGNORE);
		printf("\nTests completed with return value %d.\n", CU_basic_run_tests());
		CU_cleanup_registry();
	}

	return 0;
}