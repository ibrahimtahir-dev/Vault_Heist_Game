#include "EventLog.h"

EventLog::EventLog() : events_(nullptr), size_(0), capacity_(0), enabled_(true) {}
EventLog::~EventLog() { delete[] events_; }

void EventLog::setEnabled(bool on) { enabled_ = on; }
bool EventLog::isEnabled() const { return enabled_; }

void EventLog::emit(int type, int nodeA, int nodeB,
    int oldVal, int newVal, int aux, const std::string& note) {
    if (!enabled_) return;

    if (size_ == capacity_) {
        int newCap = (capacity_ == 0) ? 64 : capacity_ * 2;
        Event* fresh = new Event[newCap];
        for (int i = 0; i < size_; ++i) fresh[i] = events_[i];
        delete[] events_;
        events_ = fresh;
        capacity_ = newCap;
    }

    Event& e = events_[size_++];
    e.type = type;
    e.nodeA = nodeA;
    e.nodeB = nodeB;
    e.oldVal = oldVal;
    e.newVal = newVal;
    e.aux = aux;
    e.note = note;
}

void EventLog::clear() { size_ = 0; }
int  EventLog::size() const { return size_; }
bool EventLog::empty() const { return size_ == 0; }
const Event& EventLog::at(int index) const { return events_[index]; }



std::string EventLog::describe(const Event& e) {
    std::string s = eventTypeName(e.type);
    s += " [A=" + std::to_string(e.nodeA);
    s += " B=" + std::to_string(e.nodeB);
    s += " old=" + std::to_string(e.oldVal);
    s += " new=" + std::to_string(e.newVal);
    s += " aux=" + std::to_string(e.aux) + "]";
    if (!e.note.empty()) s += " " + e.note;
    return s;
}