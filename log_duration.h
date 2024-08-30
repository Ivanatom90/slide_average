#pragma once
#include <chrono>
#include <iostream>

std::string globaltime;

class LOG_DURATION{
public:
    LOG_DURATION(std::string p): point(p), now_(std::chrono::system_clock::now()){
        std::cout<<"Start "<<p<<std::endl;
    }
    std::string GetTime(){
        return time_;
    }
    ~LOG_DURATION(){
        using seconds = std::chrono::duration<double>;
        using millisec = std::chrono::duration<double, std::ratio_multiply<seconds::period, std::milli>>;
        auto time = std::chrono::system_clock::now() -now_;
        std::cout<<millisec(time).count()<<"      milliseconds"<<std::endl;
        time_ = std::to_string (millisec(time).count());
        globaltime=time_;
        std::cout<<"END "<<point<<std::endl<<std::endl;

    }
private:
    std::string point;
    std::chrono::system_clock::time_point now_;
    std::string time_;
};
