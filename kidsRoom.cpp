#include "KidsRoom.h"




kidsRoom::kidsRoom(char *name, const int &escapeTime, const int &level,
                   const int &maxParticipants, const int &ageLimit):
        EscapeRoomWrapper(name,escapeTime,level,maxParticipants),
        ageLimit(ageLimit) {}

int kidsRoom::getAgeLimit() const {
    return ageLimit;
 }

void kidsRoom::setNewAgeLimit(const int &limit) {
    if (limit<0){
        throw mtm::escaperoom::ScaryRoomIllegalAgeLimit();
    }
    ageLimit=limit;
}

std::ostream& operator<<(std::ostream& output, const kidsRoom& room){
    return output<<"Kids Room: "<< room.getName() <<" (" << room.getMaxTime()
                 << "/"<< room.level() <<"/" << room.getMaxParticipants()
                 << "/" << room.getAgeLimit()<< ")";
}