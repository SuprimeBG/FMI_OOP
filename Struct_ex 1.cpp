#include <iostream>
using std::cin;
using std::cout;

struct Time {
    //struct members
    unsigned short hour;
    unsigned short minutes;
    unsigned short seconds;

    //Member function to convert time to seconds
    int to_seconds() const {
        return hour * 3600 + minutes * 60 + seconds;
    }
};

struct Event {
    //struct members
    char title[128];
    char organiser[128];
    Time start_time;
    Time end_time;
};

Time get_duration(Event event) {
    Time duration;
    unsigned short duration_seconds = (event.end_time.hour * 3600 + event.end_time.minutes * 60 + event.end_time.seconds) -
        (event.start_time.hour * 3600 + event.start_time.minutes * 60 + event.start_time.seconds);
    duration.hour = duration_seconds / 3600;
    duration.minutes = (duration_seconds % 3600) / 60;
    duration.seconds = duration_seconds % 60;
    return duration;
}

int main()
{
    unsigned short n;
    cout << "Enter number of events: ";
    cin >> n;

    Event* events = new Event[n];

    for (int i = 0; i < n; i++) {
        char title[128], organizer[128];
        unsigned short start_h, start_m, start_s, end_h, end_m, end_s;

        cout << "Enter the title of event " << i + 1 << ": ";
        cin >> title;

        cout << "Enter the organizer of event " << i + 1 << ": ";
        cin >> organizer;

        cout << "Enter the start time of event " << i + 1 << " (hour minute second): ";
        cin >> start_h >> start_m >> start_s;
        events[i].start_time.hour = start_h;
        events[i].start_time.minutes = start_m;
        events[i].start_time.seconds = start_s;

        cout << "Enter the end time of event " << i + 1 << " (hour minute second): ";
        cin >> end_h >> end_m >> end_s;
        events[i].end_time.hour = end_h;
        events[i].end_time.minutes = end_m;
        events[i].end_time.seconds = end_s;

        for (int j = 0; j < 128; j++) {
            events[i].title[j] = title[j];
            events[i].organiser[j] = organizer[j];
        }

        unsigned short total_duration_seconds = 0;
        for (int i = 0; i < n; i++) {
            total_duration_seconds += (get_duration(events[i]).hour * 3600 +
                get_duration(events[i]).minutes * 60 +
                get_duration(events[i]).seconds);
        }

        unsigned short h = total_duration_seconds / 3600;
        unsigned short m = (total_duration_seconds % 3600) / 60;
        unsigned short s = total_duration_seconds % 60;

        cout << "Total duration of all events: " << h << " hours " << m << " minutes " << s << " seconds" << std::endl;

        delete[] events;

        return 0;
    }
}
