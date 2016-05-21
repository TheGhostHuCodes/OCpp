//
// Created by Yung-Jin Hu on 5/4/16.
//

#ifndef OCPP_BASIC_STOPWATCH_H
#define OCPP_BASIC_STOPWATCH_H

#include <chrono>
#include <iostream>

using namespace std::chrono;

class StopWatch {
public:
    explicit StopWatch(bool start) :
            m_start(system_clock::time_point::min()), m_log(std::cout) {
        if (start) { Start(); }
    }

    explicit StopWatch(char const* activity = "StopWatch", bool start = true) :
            m_start(system_clock::time_point::min()), m_log(std::cout) {
        m_activity = activity;
        if (start) { Start(); }
    };

    StopWatch(std::ostream& log, char const* activity = "StopWatch", bool start = true) :
            m_start(system_clock::time_point::min()), m_log(log) {
        m_activity = activity;
        if (start) { Start(); }
    }

    // Stop and destroy a stopwatch.
    ~StopWatch() {
        Stop();
    }

    // Clears the timer.
    void Reset() {
        m_start = system_clock::time_point::min();
    }

    // Returns true if the timer is running.
    bool IsStarted() const {
        return (m_start != system_clock::time_point::min());
    }

    void Start(char const* event_name = "start") {
        m_log << m_activity << ": " << event_name << std::endl;
        m_start = system_clock::now();
    }

    // Stop a running stopwatch, set/return elapsed time.
    unsigned Stop(char const* event_name = "stop") {
        auto duration = GetMilliseconds();
        m_log << m_activity << ": " << event_name << ": "<< duration << " ms" << std::endl;
        return duration;
    }

    // Get the number of milliseconds since the timer was started.
    unsigned long GetMilliseconds() {
        if (IsStarted()) {
            return (unsigned)(duration_cast<milliseconds>(system_clock::now() - m_start).count());
        }
        return 0;
    }

private:
    system_clock::time_point m_start;
    char const* m_activity;
    std::ostream& m_log;
};
#endif //OCPP_BASIC_STOPWATCH_H
