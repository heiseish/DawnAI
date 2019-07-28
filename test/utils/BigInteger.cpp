#include <dawn/utils/BigInteger.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( BigInteger_test_equal ) {
	dawn::BigInteger a(1000), b("1000");
    BOOST_CHECK_EQUAL( a, b );
}

BOOST_AUTO_TEST_CASE( BigInteger_test_multiply ) {
	dawn::BigInteger a("100000000000010230210312040120310201");
	a *= dawn::BigInteger(1000012312);
    BOOST_CHECK( a > 0 );
}