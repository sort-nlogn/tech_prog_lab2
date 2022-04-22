#pragma once

class Time{
    private:
        int sec, min, hrs;
    public:
        Time(int s = 0, int m = 0, int h = 0);

        friend Time &operator++(Time &t);

        friend Time &operator--(Time &t);

        friend Time &operator++(Time &t, int ignore);

        friend Time &operator--(Time &t, int ignore);

        void display();
};