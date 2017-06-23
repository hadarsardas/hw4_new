#include "kidsRoom.h"

KidsRoom(char* name, const int& escapeTime, const int& level,
         const int& maxParticipants, const int& ageLimit){
    EscapeRoomWrapper(name, escapeTime, level, maxParticipants);
    this->ageLimit;
}

int kidsRoom::getAgeLimit() {
    return ageLimit;
}

void kidsRoom::setNewAgeLimit(const int &limit) {
    if (limit<0){
        throw ScaryRoomIllegalAgeLimit;
    }
    ageLimit=limit;
}

int kidsRoom::getAgeLimit() {
    return ageLimit;
}

std::ostream& kidsRoom::operator<<(std::ostream &output,
                                   const kidsRoom &room) {
    return output<<"Kids Room: "<< room.getName() <<" (" << room.getMaxTime()
                 << "/"<< room.level() <<"/" << room.getMaxParticipants() << "/"
                 <<room.getAgeLimit()<< ")";
}