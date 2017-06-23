#ifndef HW4_NEW_KIDSROOM_H
#define HW4_NEW_KIDSROOM_H
#include "EscapeRoomWrapper.h"
using mtm::escaperoom;

class kidsRoom : public escaperoom::EscapeRoomWrapper {
    int ageLimit;
public:
    kidsRoom(char* name, const int& escapeTime, const int& level,
              const int& maxParticipants, const int& ageLimit,
              const int& numOfScaryEnigmas);
    void setNewAgeLimit (const int& limit);
    int getAgeLimit();
    std::ostream& operator<<(std::ostream& output, const kidsRoom& room);
};

#endif //HW4_NEW_KIDSROOM_H
