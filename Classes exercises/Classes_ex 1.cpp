#include <iostream>
using std::cin;
using std::cout;

class Time {
private:
    //struct members
    unsigned short hour;
    unsigned short minutes;
    unsigned short seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        setHour(h);
        setMinute(m);
        setSecond(s);
    }
    void setHour(int h) {
        if (h >= 0 && h <= 23) {
            hour = h;
        }
        else {
            std::cout << "Invalid hour input" << std::endl;
        }
    }
    void setMinute(int m) {
        if (m >= 0 && m <= 59) {
            minute = m;
        }
        else {
            std::cout << "Invalid minute input" << std::endl;
        }
    }
    void setSecond(int s) {
        if (s >= 0 && s <= 59) {
            second = s;
        }
        else {
            std::cout << "Invalid second input" << std::endl;
        }
    }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
};

class Event {
private:
    //struct members
    char title[128];
    char organiser[128];
    Time start_time;
    Time end_time;

public:
    Event() {
        strcpy(title, "");
        strcpy(organizer, "");
        start_time = Time(0, 0, 0);
        end_time = Time(0, 0, 0);
    }
    Event(const char* t, const char* o, const Time& st, const Time& et) {
        setTitle(t);
        setOrganizer(o);
        setStartTime(st);
        setEndTime(et);
    }
    void setTitle(const char* t) {
        if (strlen(t) < 128) {
            strcpy(title, t);
        }
        else {
            strcpy(title, "");
        }
    }
    void setOrganizer(const char* o) {
        if (strlen(o) < 128) {
            strcpy(organizer, o);
        }
        else {
            strcpy(organizer, "");
        }
    }
    void setStartTime(const Time& st) {
        start_time = st;
    }
    void setEndTime(const Time& et) {
        end_time = et;
    }
    const char* getTitle() const {
        return title;
    }
    const char* getOrganizer() const {
        return organizer;
    }
    Time getStartTime() const {
        return start_time;
    }
    Time getEndTime() const {
        return end_time;
    }
    int getDurationInMinutes() const {
        int duration = (end_time.getHour() - start_time.getHour()) * 60
            + (end_time.getMinute() - start_time.getMinute());
        return duration;
    }
    bool isOverlap(const Event& e) const {
        if (start_time.getHour() < e.getEndTime().getHour() &&
            end_time.getHour() > e.getStartTime().getHour()) {
            return true;
        }
        return false;
    }
};

int main()
{
    unsigned short n;
    cout << "Enter the number of events: ";
    cin >> n;

    Event events[n];
    for (unsigned short i = 0; i < n; i++) {
        string title, organizer;
        Time start_time, end_time;

        // Input event details from user
        cout << "Enter event " << i + 1 << " title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter event " << i + 1 << " organizer: ";
        getline(cin, organizer);

        cout << "Enter event " << i + 1 << " start time (hour minute second): ";
        int start_hour, start_minute, start_second;
        cin >> start_hour >> start_minute >> start_second;
        start_time = Time(start_hour, start_minute, start_second);

        cout << "Enter event " << i + 1 << " end time (hour minute second): ";
        int end_hour, end_minute, end_second;
        cin >> end_hour >> end_minute >> end_second;
        end_time = Time(end_hour, end_minute, end_second);

        events[i] = Event(title, organizer, start_time, end_time);
    }

    // Sort events by start time
    sort(events, events + n, [](const Event& a, const Event& b) {
        return a.get_start_time() < b.get_start_time();
        });

    // Find non-overlapping events
    Event current_event = events[0];
    cout << current_event.get_title() << " ("
        << current_event.get_start_time().to_string() << " - "
        << current_event.get_end_time().to_string() << ")" << endl;

    for (int i = 1; i < n; i++) {
        if (events[i].get_start_time() >= current_event.get_end_time()) {
            current_event = events[i];
            cout << current_event.get_title() << " ("
                << current_event.get_start_time().to_string() << " - "
                << current_event.get_end_time().to_string() << ")" << endl;
        }
    }

    return 0;
}