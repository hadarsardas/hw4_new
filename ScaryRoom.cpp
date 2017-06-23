#include "ScaryRoom.h"

int ScaryRoom::getAgeLimit() {
    return ageLimit;
}
void ScaryRoom::incNumberOfScaryEnigmas() {
    numOfScaryEnigmas++;
}

void ScaryRoom::setNewAgeLimit(const int &limit) {
    if (limit<0){
        throw ScaryRoomIllegalAgeLimit;
    }
    ageLimit=limit;
}

ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level,
                     const int &maxParticipants, const int &ageLimit,
                     const int &numOfScaryEnigmas): {
    EscapeRoomWrapper(name, escapeTime, level, maxParticipants);
    this->ageLimit;
    this->numOfScaryEnigmas=numOfScaryEnigmas;
}

std::ostream& ScaryRoom::operator<<(std::ostream &output,
                                    const ScaryRoom &room) {
    return output<<"ScaryRoom: "<< room.getName() <<" ("<< room.getMaxTime() <<
                 "/" << room.level() <<"/" << room.getMaxParticipants() << "/"
                 << room. getAgeLimit()<< ")";
}