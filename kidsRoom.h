#ifndef HW4_NEW_KIDSROOM_H
#define HW4_NEW_KIDSROOM_H
#include "EscapeRoomWrapper.h"

class kidsRoom : public mtm::escaperoom::EscapeRoomWrapper {
    int ageLimit;
public:
    kidsRoom(char* name, const int& escapeTime, const int& level,
             const int& maxParticipants, const int& ageLimit);

    void setNewAgeLimit(const int& limit);

    int getAgeLimit() const;

    friend std::ostream& operator<<(std::ostream& output, const kidsRoom& room);
};

std::ostream& operator<<(std::ostream& output, const kidsRoom& room);

#endif //HW4_NEW_KIDSROOM_H