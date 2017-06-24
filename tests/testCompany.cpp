#include "../EscapeRoomWrapper.h"
#include "../ScaryRoom.h"
#include "../KidsRoom.h"
#include "../Company.h"
#include "../mtmtest.h"
#include <assert.h>
#include "../Exceptions.h"

using namespace mtm::escaperoom;


void createCompany() {

    ASSERT_NO_THROW(Company("Company1","0501234567"));
    ASSERT_NO_THROW(Company("Company2","0523456789"));
}

void createRoom() {
    Company Company1("Company1","0501234567");
    ASSERT_NO_THROW(Company1.createRoom((char*)"baseRoom",40,3,6));
    ASSERT_NO_THROW(Company1.createKidsRoom((char*)"kidsRoom",45,5,5,14));
    ASSERT_NO_THROW(Company1.createScaryRoom((char *) "scaryRoom", 52,7,6,26,3));
}

void getAllRoomsTest() {
    Company Company("Company","0501234567");
    EscapeRoomWrapper Room1((char*)"The Robbery of The Century",40,3,6);
    std::set<EscapeRoomWrapper*> roomSet=Company.getAllRooms();
    ASSERT_TRUE(roomSet.insert(&Room1).second);
    ASSERT_EQUALS(roomSet.size(),1);
    ASSERT_NO_THROW(Company.createRoom((char*)"The Robbery of The Century",40,3,6));
    ASSERT_NO_THROW(Company.createRoom((char*)"Mossad",52,4,3));
    ASSERT_NO_THROW(Company.createKidsRoom((char*)"The Real Survivor",45,5,5,14));
    ASSERT_NO_THROW(Company.createKidsRoom((char *) "KidsEscape", 50,6,2,10));
    ASSERT_NO_THROW(Company.createScaryRoom((char *) "Haunted Matam Castle", 60,9,4,99,5));
    ASSERT_NO_THROW(Company.createScaryRoom((char *) "Lost Students", 52,7,6,26,3));
    std::set<EscapeRoomWrapper*> roomSet2=Company.getAllRooms();
    ASSERT_FALSE(roomSet.insert(&Room1).second);
    ASSERT_EQUALS(roomSet2.size(),6);
}

int main() {
    RUN_TEST(createCompany);
    RUN_TEST(createRoom);
    RUN_TEST(getAllRoomsTest);
}