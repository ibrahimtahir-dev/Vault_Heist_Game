#pragma once
#include <string>
#include "Event.h"

class EventLog {
public:
    EventLog();
    ~EventLog();

   
    void setEnabled(bool on);
    bool isEnabled() const;

    void emit(int type, int nodeA = -1, int nodeB = -1,
        int oldVal = 0, int newVal = 0, int aux = 0,
        const std::string& note = "");

    void clear();
    int  size() const;
    bool empty() const;
    const Event& at(int index) const;   

    
    static std::string describe(const Event& e);   

private:
    EventLog(const EventLog&);              
    EventLog& operator=(const EventLog&);   

    Event* events_;
    int size_;
    int capacity_;
    bool enabled_;
};
