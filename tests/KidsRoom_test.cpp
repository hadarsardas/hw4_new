#include "../KidsRoom.h"
#include "../mtmtest.h"

static void makeRooms(){
    KidsRoom bob=KidsRoom((char*)"SpongeBob", 60, 10, 7, 10);
    ASSERT_EQUALS(bob.getMaxTime(), 60);
    ASSERT_EQUALS(bob.getAgeLimit(),10 );
    ASSERT_EQUALS(bob.getMaxParticipants(),7);
    ASSERT_EQUALS(bob.level(), 10);
    ASSERT_EQUALS(bob.getName(), (char*)"SpongeBob");
    KidsRoom frozen=KidsRoom((char*)"Frozen", 70, 5, 8, 6);
    ASSERT_EQUALS(frozen.getMaxTime(), 70);
    ASSERT_EQUALS(frozen.getAgeLimit(),6 );
    ASSERT_EQUALS(frozen.getMaxParticipants(),8);
    ASSERT_EQUALS(frozen.level(), 5);
    ASSERT_EQUALS(frozen.getName(), (char*)"Frozen");
}

static void ageLimit(){
    KidsRoom lion=KidsRoom((char*)"Lion King", 90, 10, 2, 5);
    ASSERT_EQUALS(lion.getMaxTime(), 90);
    ASSERT_EQUALS(lion.getAgeLimit(),5);
    ASSERT_EQUALS(lion.getMaxParticipants(),2);
    ASSERT_EQUALS(lion.level(), 10);
    ASSERT_EQUALS(lion.getName(), (char*)"Lion King");
    lion.setNewAgeLimit(20);
    ASSERT_EQUALS(lion.getAgeLimit(),20);
    lion.setNewAgeLimit(10);
    ASSERT_EQUALS(lion.getAgeLimit(),10);
    ASSERT_THROWS(mtm::escaperoom::ScaryRoomIllegalAgeLimit,
                  lion.setNewAgeLimit(-8));
    lion.setNewAgeLimit(0);
    ASSERT_EQUALS(lion.getAgeLimit(),0);
}
static void rateCheck(){
    KidsRoom Nemo=KidsRoom((char*)"Nemo", 30, 8, 6, 10);
    Nemo.rate(5);
    ASSERT_EQUALS(Nemo.getRate(), 5);
    Nemo.rate(2);
    ASSERT_EQUALS(Nemo.getRate(), 3.5);
    Nemo.rate(5);
    ASSERT_EQUALS(Nemo.getRate(), 4);
    Nemo.rate(4);
    ASSERT_EQUALS(Nemo.getRate(), 4);
    Nemo.rate(1);
    ASSERT_EQUALS(Nemo.getRate(), 3.4);
}

static void prinCheck(){
    KidsRoom Stitch=KidsRoom((char*)"Stitch", 60, 7, 4, 10);
    ASSERT_PRINT("Kids Room: Stitch (60/7/4/10)", Stitch);
    KidsRoom lilo=KidsRoom((char*)"Lilo", 60, 8, 3, 12);
    ASSERT_PRINT("Kids Room: Lilo (60/8/3/12)", lilo);
}

int main(){
    RUN_TEST(makeRooms);
    RUN_TEST(ageLimit);
    RUN_TEST(rateCheck);
    RUN_TEST(prinCheck);
}