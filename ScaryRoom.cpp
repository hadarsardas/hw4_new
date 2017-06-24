#include "ScaryRoom.h"

int ScaryRoom::getAgeLimit() const {
    return ageLimit;
}
void ScaryRoom::incNumberOfScaryEnigmas() {
    numOfScaryEnigmas++;
}

void ScaryRoom::setNewAgeLimit(const int &limit) {
    if (limit<0){
        throw mtm::escaperoom::ScaryRoomIllegalAgeLimit();
    }
    ageLimit=limit;
}

ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level,
                     const int &maxParticipants, const int &ageLimit,
                     const int &numOfScaryEnigmas):
        EscapeRoomWrapper(name,escapeTime,level,maxParticipants),
        ageLimit(ageLimit),numOfScaryEnigmas(numOfScaryEnigmas) {}

std::ostream& operator<<(std::ostream& output, const ScaryRoom& room){
    return output<<"ScaryRoom: "<< room.getName() <<" ("<< room.getMaxTime() <<
                 "/" << room.level() <<"/" << room.getMaxParticipants() << "/"
                 << room.getAgeLimit()<< ")";
}