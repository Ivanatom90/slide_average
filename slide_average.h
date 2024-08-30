#pragma once
#include <iostream>
#include <vector>
#include <numeric>

#include "log_duration.h"

template <typename Type>
class SlideAverage{
  public:
    SlideAverage(int period) : period_(period){
        FillVector();
        MakeSlideAvarage();
    }

    void MakeSlideAvarage(){
            auto begin = numbers_.begin();
            auto end = numbers_.begin() + period_;
            slide_avarage_.reserve(numbers_.size() - period_ + 1);
            LOG_DURATION LD("time ");
            while(end != numbers_.end()){
                slide_avarage_.push_back(Avarage(begin, end));
                begin++;
                end++;
            }
    }

    void PrintSlideAvarege()const{
        for(const Type& num:slide_avarage_){
            std::cout<<num<<std::endl;
        }
    }
    private:

    void FillVector(){
        numbers_.reserve(1E6);
        for(int i=0; i<1E6; i++){
            numbers_.push_back(rand());
        }
    }

    template<typename Iterator>
    Type Avarage(Iterator begin, Iterator end){
        return std::accumulate(begin, end, 0.00)/period_;
    }

    int period_;
    std::vector<Type> numbers_;
    std::vector<Type> slide_avarage_;
};
