#pragma once
#include <iostream>
#include <string>
#include <vector>

class MCU{
protected:
    float cpu_speed;
    int memory;
    std::string os;
    std::string name;
    int volt;
public:
    MCU(float cpu_speed,int memory,std::string os,std::string name,int volt);
    virtual void showSpek();
    virtual ~MCU();
    virtual void nambah_volt(int penambahan_voltase);
    virtual void ganti_os(std::string new_os);
};
