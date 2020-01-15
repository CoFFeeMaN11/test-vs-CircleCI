#include "pch.h"

class CFoo: public IFoo {
public:
	MOCK_METHOD0(Bar, int());
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(Foo(),0);
}

TEST(TestCaseName, Test2) {
	CFoo foo;
	ON_CALL(foo, Bar()).WillByDefault(::testing::Return(1));
	EXPECT_EQ(foo.Bar(), 1);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}