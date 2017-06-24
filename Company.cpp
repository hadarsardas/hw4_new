#include "Company.h"
using::mtm::escaperoom::Company;
Company::Company(string name, string phoneNumber) {
    this->name=name;
    this->phoneNumber=phoneNumber;
    this->rooms=set<EscapeRoomWrapper*>();
}
void Company::createRoom(char *name, const int &escapeTime, const int &level,
                         const int &maxParticipants) {
    EscapeRoomWrapper room=EscapeRoomWrapper(name,escapeTime,level,
                                             maxParticipants);
    rooms.insert(&room);
}
void Company::createScaryRoom(char *name, const int &escapeTime,
                              const int &level, const int &maxParticipants,
                              const int &ageLimit,
                              const int &numOfScaryEnigmas) {
    ScaryRoom roomScary=ScaryRoom(name,escapeTime,level,maxParticipants,
                                  ageLimit,numOfScaryEnigmas);
    rooms.insert(&roomScary);
}
void Company::createKidsRoom(char *name, const int &escapeTime,
                             const int &level, const int &maxParticipants,
                             const int &ageLimit) {
    kidsRoom roomKids=kidsRoom(name,escapeTime,level,maxParticipants,ageLimit);
    rooms.insert(&roomKids);
}
set<mtm::escaperoom::EscapeRoomWrapper*> Company::getAllRooms() const {
    return rooms;
}
void Company::removeRoom(const EscapeRoomWrapper &room) {
    if (rooms.size() == 0) {
        throw CompanyRoomNotFoundException();
    }
    for(std::set<EscapeRoomWrapper*>::iterator it=rooms.begin();it!=rooms.end();
        it++){
        if(**it==room){
            rooms.erase(it);
            return;
        }
    }
    throw CompanyRoomNotFoundException();
}