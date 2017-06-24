#ifndef HW4_NEW_SCARYROOM_H
#define HW4_NEW_SCARYROOM_H
#include "EscapeRoomWrapper.h"


class ScaryRoom : public mtm::escaperoom::EscapeRoomWrapper {
    int ageLimit;
    int numOfScaryEnigmas;
public:
    ScaryRoom(char *name, const int &escapeTime, const int &level,
              const int &maxParticipants, const int &ageLimit,
              const int &numOfScaryEnigmas);

    ScaryRoom(const ScaryRoom& scary)=default;

    void setNewAgeLimit(const int &limit);

    void incNumberOfScaryEnigmas();

    int getAgeLimit() const;

    friend std::ostream& operator<<(std::ostream& output, const ScaryRoom& room);
};
std::ostream& operator<<(std::ostream& output, const ScaryRoom& room);

#endif //HW4_NEW_SCARYROOM_H