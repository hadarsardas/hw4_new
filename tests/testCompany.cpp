#include "../EscapeRoomWrapper.h"
#include "../ScaryRoom.h"
#include "../KidsRoom.h"
#include "../Company.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;


void test1() {

    ASSERT_NO_THROW(Company("Company1","0501234567"));
    ASSERT_NO_THROW(Company("Company2","0523456789"));
}

void test2() {
    Company Company1("Company1","0501234567");
    ASSERT_NO_THROW(Company1.createRoom((char*)"The Robbery of The Century",40,3,6));
    ASSERT_NO_THROW(Company1.createRoom((char*)"Mossad",52,4,3));
    ASSERT_NO_THROW(Company1.createKidsRoom((char*)"The Real Survivor",45,5,5,14));
    ASSERT_NO_THROW(Company1.createKidsRoom((char *) "KidsEscape", 50,6,2,10));
    ASSERT_NO_THROW(Company1.createScaryRoom((char *) "Haunted Matam Castle", 60,9,4,99,5));
    ASSERT_NO_THROW(Company1.createScaryRoom((char *) "Lost Students", 52,7,6,26,3));
}

int main() {
    RUN_TEST(test1);
    RUN_TEST(test2);
}