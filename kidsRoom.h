#ifndef HW4_NEW_KIDSROOM_H
#define HW4_NEW_KIDSROOM_H
#include "EscapeRoomWrapper.h"
#include <iostream>


class KidsRoom : public mtm::escaperoom::EscapeRoomWrapper {
    int ageLimit;
public:
    KidsRoom(char* name, const int& escapeTime, const int& level,
             const int& maxParticipants, const int& ageLimit);

    KidsRoom(const KidsRoom& kids)=default;

    void setNewAgeLimit(const int& limit);

    int getAgeLimit() const;

    friend std::ostream& operator<<(std::ostream& output, const KidsRoom& room);

    std::ostream& print(std::ostream &output) const override ;
};

std::ostream& operator<<(std::ostream& output, const KidsRoom& room) ;
#endif //HW4_NEW_KIDSROOM_H